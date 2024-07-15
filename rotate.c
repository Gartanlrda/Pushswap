/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:13:49 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/15 15:24:44 by ggoy             ###   ########.fr       */
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

void	do_pushswap(t_list **a)
{
	if (valid_lst(*a) == 1)
	{
		index_maker(*a);
		sortin_list(a);
		if ((*a)->content.index <= (ft_lstsize(*a) / 2))
		{
			while (check_sort(*a) != 1)
				rra(a);
		}
		else
		{
			while (check_sort(*a) != 1)
				ra(a);
		}
	}
	else
		write(2, "Error\n", 6);
	free_lst(*a);
}
