/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_instructions1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:52:09 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/18 18:07:58 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra_bonus(t_list **a)
{
	t_list	*temp;

	if (*a)
	{
		temp = (*a);
		(*a) = (*a)->next;
		temp->next = NULL;
		ft_lstadd_back(a, temp);
	}
}

void	rb_bonus(t_list **b)
{
	t_list	*temp;

	if (*b)
	{
		temp = (*b);
		(*b) = (*b)->next;
		temp->next = NULL;
		ft_lstadd_back(b, temp);
	}
}

void	rr_bonus(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*tempb;

	if (*b)
	{
		tempb = (*b);
		(*b) = (*b)->next;
		tempb->next = NULL;
		ft_lstadd_back(b, tempb);
	}
	if (*a)
	{
	temp = (*a);
	(*a) = (*a)->next;
	temp->next = NULL;
	ft_lstadd_back(a, temp);
	}
}

void	pa_bonus(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*b)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = *a;
		*a = temp;
	}
}

void	pb_bonus(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}
