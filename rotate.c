/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:13:49 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/15 15:39:35 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_list **a)
{
	t_list	*temp;

	temp = (*a);
	(*a) = (*a)->next;
	temp->next = NULL;
	ft_lstadd_back(a, temp);
	printf("%s\n", "ra");
}

void	rb(t_list **b)
{
	t_list	*temp;

	temp = (*b);
	(*b) = (*b)->next;
	temp->next = NULL;
	ft_lstadd_back(b, temp);
	printf("%s\n", "rb");
}

void	rr(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*tempb;

	tempb = (*b);
	(*b) = (*b)->next;
	tempb->next = NULL;
	ft_lstadd_back(b, tempb);
	temp = (*a);
	(*a) = (*a)->next;
	temp->next = NULL;
	ft_lstadd_back(a, temp);
	printf("%s\n", "rr");
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
