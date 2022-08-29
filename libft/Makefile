SRCS		= ft_memset.c ft_bzero.c ft_calloc.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
			ft_strlen.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
			ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_strmapi.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
			get_next_line.c get_next_line_utils.c\
			ft_printf.c ft_printf_annexe.c ft_printf_put.c\
			ft_doubletab.c\

SRCSB		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS		= ${SRCS:.c=.o}

OBJSB		= $(SRCSB:.c=.o)

NAME		= libft.a

CC			= gcc

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(OBJSB)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:		all $(OBJSB)
			ar rcs $(NAME) $(OBJSB)

.PHONY:		all clean fclean re
