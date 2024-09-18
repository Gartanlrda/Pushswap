/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:08:34 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/22 13:04:11 by ggoy             ###   ########.fr       */
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

int	three_highest(t_list **a, int value)
{
	int	max;

	max = index_max(a);
	if (value > max - 3)
		return (0);
	else
		return (1);
}

int	find_back(t_list **a, int quarter)
{
	t_list	*tmp;
	int		pos;

	pos = (ft_lstlast(*a)->content.position);
	while (1)
	{
		tmp = *a;
		while (tmp->content.position < pos)
			tmp = tmp->next;
		if (tmp->content.index <= quarter
			&& three_highest(a, tmp->content.index) == 1)
			return (ft_lstlast(*a)->content.position \
				- tmp->content.position + 1);
		else
			pos--;
	}
}

void	sortin_list(t_list **a)
{
	int		quarter;
	int		divider;
	t_list	*b;
	t_list	*tmp;

	b = NULL;
	divider = index_max(a) / 3;
	quarter = divider;
	while (ft_lstsize(*a) > 3 && check_quarter((*a), quarter) == 0)
	{
		while (ft_lstsize(*a) > 3 && check_quarter((*a), quarter) == 0)
			find_best_op(a, &b, quarter);
		quarter = quarter + divider;
	}
	sortin_three(a);
	tmp = b;
	push_the_f(a, &b);
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
