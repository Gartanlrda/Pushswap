/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_instructions3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:01:02 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/18 17:20:35 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa_bonus(t_list **a)
{
	t_psnode	temp;

	if (*a)
	{
		temp = (*a)->next->content;
		(*a)->next->content = (*a)->content;
		(*a)->content = temp;
	}
}

void	sb_bonus(t_list **b)
{
	t_psnode	temp;

	if (*b)
	{
		temp = (*b)->next->content;
		(*b)->next->content = (*b)->content;
		(*b)->content = temp;
	}
}

void	ss_bonus(t_list **a, t_list **b)
{
	t_psnode	temp;
	t_psnode	tempb;

	if (*a)
	{
		temp = (*a)->next->content;
		(*a)->next->content = (*a)->content;
		(*a)->content = temp;
	}
	if (*b)
	{
		tempb = (*b)->next->content;
		(*b)->next->content = (*b)->content;
		(*b)->content = tempb;
	}
}
