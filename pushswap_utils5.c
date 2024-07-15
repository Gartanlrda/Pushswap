/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 08:14:47 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/15 15:52:39 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	op_in_a(t_list **a, int index_b)
{
	t_list	*tmp;
	int		i;
	int		lower_big;

	i = 0;
	tmp = *a;
	lower_big = index_max(a);
	while (tmp)
	{
		if (tmp->content.index > index_b && tmp->content.index < lower_big)
		{
			lower_big = tmp->content.index;
			i = tmp->content.position;
		}
		tmp = tmp->next;
	}
	if (i <= ft_lstsize(*a) / 2)
		return (i);
	else
		return (ft_lstsize(*a) - i);
}

int	best_b(t_list **a, t_list **b)
{
	int		current;
	int		cheapest;
	int		best;
	t_list	*tmp;

	tmp = *b;
	cheapest = 2147483647;
	while (tmp)
	{
		if (tmp->content.position <= ft_lstsize(*b) / 2)
			current = op_in_a(a, tmp->content.index) + tmp->content.position;
		else
			current = op_in_a(a, tmp->content.index) \
				+ (ft_lstsize(*b) - tmp->content.position + 1);
		if (current < cheapest)
		{
			cheapest = current;
			best = tmp->content.position;
		}
		tmp = tmp->next;
	}
	return (best);
}

int	best_a(t_list **a, t_list **b)
{
	int		lower_big;
	int		i;
	int		index;
	t_list	*tmp;

	i = 0;
	lower_big = index_max(a);
	tmp = *b;
	while (tmp->content.position != best_b(a, b))
		tmp = tmp->next;
	index = tmp->content.index;
	tmp = *a;
	while (tmp)
	{
		if (tmp->content.index > index && tmp->content.index < lower_big)
		{
			lower_big = tmp->content.index;
			i = tmp->content.position;
		}
		tmp = tmp->next;
	}
	return (i);
}

int	op_in_total(t_list **a, t_list **b)
{
	int		current;
	int		cheapest;
	t_list	*tmp;

	tmp = *b;
	cheapest = 2147483647;
	while (tmp)
	{
		if (tmp->content.position <= ft_lstsize(*b) / 2)
			current = op_in_a(a, tmp->content.index) + tmp->content.position;
		else
			current = op_in_a(a, tmp->content.index) \
				+ (ft_lstsize(*b) - tmp->content.position + 1);
		if (current < cheapest)
			cheapest = current;
		tmp = tmp->next;
	}
	return (cheapest);
}

int	op_in_b(t_list **a, t_list **b)
{
	int		current;
	int		cheapest;
	t_list	*tmp;

	tmp = *b;
	cheapest = 2147483647;
	while (tmp->content.position != best_b(a, b))
		tmp = tmp->next;
	current = best_b(a, b);
	if (current <= ft_lstsize(*b) / 2)
		cheapest = current;
	else
		cheapest = ft_lstsize(*b) - current;
	return (cheapest);
}
