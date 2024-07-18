/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_instructions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:55:45 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/18 18:05:35 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra_bonus(t_list **a)
{
	t_list		*temp;
	t_list		*temp2;

	if (*a)
	{
		temp2 = (*a);
		temp = ft_lstlast(*a);
		while (temp2->next != temp)
			temp2 = temp2->next;
		temp2->next = NULL;
		ft_lstadd_front(a, temp);
	}
}

void	rrb_bonus(t_list **b)
{
	t_list		*temp;
	t_list		*temp2;

	if (*b)
	{
		temp2 = (*b);
		temp = ft_lstlast(*b);
		while (temp2->next != temp)
			temp2 = temp2->next;
		temp2->next = NULL;
		ft_lstadd_front(b, temp);
	}
}

void	rrr_bonus(t_list **a, t_list **b)
{
	t_list		*temp;
	t_list		*temp2;
	t_list		*tempb;
	t_list		*tempb2;

	if (*a)
	{
		temp2 = (*a);
		temp = ft_lstlast(*a);
		while (temp2->next != temp)
			temp2 = temp2->next;
		temp2->next = NULL;
		ft_lstadd_front(a, temp);
	}
	if (*b)
	{
		tempb2 = (*b);
		tempb = ft_lstlast(*b);
		while (tempb2->next != tempb)
			tempb2 = tempb2->next;
		tempb2->next = NULL;
		ft_lstadd_front(b, tempb);
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

void	free_lst(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = (lst)->next;
		free(lst);
		lst = tmp;
	}
}
