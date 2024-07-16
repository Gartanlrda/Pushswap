/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:22:47 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/16 11:44:11 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_list **a)
{
	t_psnode	temp;

	temp = (*a)->next->content;
	(*a)->next->content = (*a)->content;
	(*a)->content = temp;
	ft_printf("%s\n", "sa");
}

void	sb(t_list **b)
{
	t_psnode	temp;

	temp = (*b)->next->content;
	(*b)->next->content = (*b)->content;
	(*b)->content = temp;
	ft_printf("%s\n", "sb");
}

void	ss(t_list **a, t_list **b)
{
	t_psnode	temp;
	t_psnode	tempb;

	temp = (*a)->next->content;
	(*a)->next->content = (*a)->content;
	(*a)->content = temp;
	tempb = (*b)->next->content;
	(*b)->next->content = (*b)->content;
	(*b)->content = tempb;
	ft_printf("%s\n", "ss");
}
