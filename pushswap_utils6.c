/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:05:36 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/15 14:25:03 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	rotator_a(a, b, rev_a);
	rotator_b(a, b, rev_b);
}

void	rotator_a(t_list **a, t_list **b, int rev_a)
{
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
}

void	rotator_b(t_list **a, t_list **b, int rev_b)
{
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
