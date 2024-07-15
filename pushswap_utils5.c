/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 08:14:47 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/15 14:00:43 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	index_max(t_list **a)
{
	int		max;
	t_list	*temp;

	max = -2147483647;
	temp = *a;
	while (temp)
	{
		if (temp->content.index > max)
			max = temp->content.index;
		temp = temp->next;
	}
	return (max);
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

int	three_highest(t_list **a, int value)
{
	int	max;

	max = index_max(a);
	if (value > max - 3)
		return (0);
	else
		return (1);
}

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
	update_position(*a);
	update_position(*b);
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
	update_position(*a);
	update_position(*b);
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
	update_position(*a);
	update_position(*b);
	while (tmp->content.position != best_b(a, b))
		tmp = tmp->next;
	current = best_b(a, b);
	if (current <= ft_lstsize(*b) / 2)
		cheapest = current;
	else
		cheapest = ft_lstsize(*b) - current;
	return (cheapest);
}

void	push_the_f(t_list **a, t_list **b)
{
	int		rotate_a;
	int		rotate_b;

	while (*b)
	{
		update_position(*a);
		update_position(*b);
		rotate_a = 1;
		rotate_b = 1;
		if (best_a(a, b) > ft_lstsize(*a) / 2)
			rotate_a = -1;
		if (best_b(a, b) > ft_lstsize(*b) / 2)
			rotate_b = -1;
		if (rotate_a > 0 && rotate_b > 0)
			dual_rotate(a, b);
		else if (rotate_a < 0 && rotate_b < 0)
			dual_reverse(a, b);
		else
			mix_push(a, b);
		pa(a, b);
	}
}

void	dual_rotate(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		rev_a;
	int		rev_b;

	rev_b = op_in_b(a, b);
	tmp = *b;
	while (tmp->content.position != best_b(a, b))
		tmp = tmp->next;
	rev_a = op_in_a(a, tmp->content.index);
	while (rev_a && rev_b)
	{
		rr(a, b);
		rev_a--;
		rev_b--;
	}
	while (rev_a)
	{
		ra(a);
		rev_a--;
	}
	while (rev_b)
	{
		rb(b);
		rev_b--;
	}
}

void	dual_reverse(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		rev_a;
	int		rev_b;

	rev_b = op_in_b(a, b);
	tmp = *b;
	while (tmp->content.position != best_b(a, b))
		tmp = tmp->next;
	rev_a = op_in_a(a, tmp->content.index);
	while (rev_a && rev_b)
	{
		rrr(a, b);
		rev_a--;
		rev_b--;
	}
	while (rev_a)
	{
		rra(a);
		rev_a--;
	}
	while (rev_b)
	{
		rrb(b);
		rev_b--;
	}
}

void	mix_push(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		rev_a;
	int		rev_b;

	rev_b = op_in_b(a, b);
	tmp = *b;
	while (tmp->content.position != best_b(a, b))
		tmp = tmp->next;
	rev_a = op_in_a(a, tmp->content.index);
	if (best_a(a, b) > ft_lstsize(*a) / 2)
	{
		while (rev_a)
		{
			rra(a);
			rev_a--;
		}
	}
	else
	{
		while (rev_a)
		{
			ra(a);
			rev_a--;
		}
	}
	if (best_b(a, b) > ft_lstsize(*b) / 2)
	{
		while (rev_b)
		{
			rrb(b);
			rev_b--;
		}
	}
	else
	{
		while (rev_b)
		{
			rb(b);
			rev_b--;
		}
	}
}
