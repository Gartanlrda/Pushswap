/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:22:10 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/15 14:24:16 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_list **a)
{
	t_list		*temp;
	t_list		*temp2;

	temp2 = (*a);
	temp = ft_lstlast(*a);
	while (temp2->next != temp)
		temp2 = temp2->next;
	temp2->next = NULL;
	ft_lstadd_front(a, temp);
	printf("%s\n", "rra");
}

void	rrb(t_list **b)
{
	t_list		*temp;
	t_list		*temp2;

	temp2 = (*b);
	temp = ft_lstlast(*b);
	while (temp2->next != temp)
		temp2 = temp2->next;
	temp2->next = NULL;
	ft_lstadd_front(b, temp);
	printf("%s\n", "rrb");
}

void	rrr(t_list **a, t_list **b)
{
	t_list		*temp;
	t_list		*temp2;
	t_list		*tempb;
	t_list		*tempb2;

	temp2 = (*a);
	temp = ft_lstlast(*a);
	while (temp2->next != temp)
		temp2 = temp2->next;
	temp2->next = NULL;
	ft_lstadd_front(a, temp);
	tempb2 = (*b);
	tempb = ft_lstlast(*b);
	while (tempb2->next != tempb)
		tempb2 = tempb2->next;
	tempb2->next = NULL;
	ft_lstadd_front(b, tempb);
	printf("%s\n", "rrr");
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

int	index_min(t_list **a)
{
	int		min;
	t_list	*temp;

	min = 2147483647;
	temp = *a;
	while (temp)
	{
		if (temp->content.index < min)
			min = temp->content.index;
		temp = temp->next;
	}
	return (min);
}
