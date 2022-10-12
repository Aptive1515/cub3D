# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/22 23:12:10 by pbondoer          #+#    #+#              #
#    Updated: 2022/10/12 09:53:56 by chaidel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D
OS		= $(shell uname)

# directories
SRCDIR		=	./src
INCDIR		=	./includes
OBJDIR		=	./obj

# src / obj files
SRC		=	main.c\
			parsing/verif_arg.c\
			parsing/parse_map.c\
			parsing/parse_utils.c\
			graph/figure.c\
			graph/graph_utils.c\
			graph/map.c\
			graph/texturing.c\
			player/player.c\
			player/player_utils.c\
			hook/hook_1.c\
			utils/utils.c\
			utils/error.c\
			checker/mapper.c\
			checker/option.c\
			checker/solver.c\
			ray/dda.c\
			ray/dda_utils.c\
			ray/ray_traicing.c\
			ray/ray_utils.c\
			ray/wall_affichage.c\


OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g3 #-fsanitize=address


# mlx library
ifeq ($(OS), Linux)
	MLX		= ./miniLibX_X11/
	MLX_LNK	= -L $(MLX) -l mlx -lXext -lX11
else
	MLX		= ./miniLibX/
	MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
endif

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/parsing
	mkdir -p $(OBJDIR)/graph
	mkdir -p $(OBJDIR)/player
	mkdir -p $(OBJDIR)/hook
	mkdir -p $(OBJDIR)/utils
	mkdir -p $(OBJDIR)/checker
	mkdir -p $(OBJDIR)/ray



$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -j -C $(FT)

$(MLX_LIB):
	@make -j -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean
	make all
