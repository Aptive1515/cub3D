/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:12:13 by tdelauna          #+#    #+#             */
/*   Updated: 2022/01/11 20:51:24 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*tmp;
	t_list	*first;

	tmp = new;
	first = *alst;
	if (!alst || !new)
		return ;
	tmp->next = *alst;
	*alst = tmp;
	first->prev = tmp;
}
