/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 08:14:47 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/12 14:02:28 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int index_max(t_list **a)
{
	int max;
	t_list  *temp;
		
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

int index_min(t_list **a)
{
	int min;
	t_list  *temp;

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
	int max;

	max = index_max(a);
	if (value > max - 3)
		return (0);
	else
		return (1);
}

int place_in_a(t_list **a, int index_b)
{
	
	t_list  *tmp;
	int	 i;
	int	lower_big;
	
	i = 0;
	tmp = *a;
	lower_big = index_max(a);
	// printf("index :%i\n", index_b);
	while (tmp)
	{
		// printf("lower big: %i\n", lower_big);
		if (tmp->content.index > index_b && tmp->content.index < lower_big)
		{
			lower_big = tmp->content.index;
			i = tmp->content.position;
		}
		tmp = tmp->next;
	}
	return (i);
}

int best_rotate(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		best_op;
	int		next_op;
	int		size_a;

	update_position(*a);
	update_position(*b);
	tmp = *b;
	size_a = ft_lstsize(*a);
	if (place_in_a(a, tmp->content.index) > tmp->content.position)
		best_op = place_in_a(a, tmp->content.index);
	else
		best_op = tmp->content.position;
	while (tmp)
	{
		if (place_in_a(a, tmp->content.index) > tmp->content.position)
			next_op = place_in_a(a, tmp->content.index);
		else
			next_op = tmp->content.position;
		if (next_op < best_op)
			best_op = next_op;
		tmp = tmp->next;
	}
	// printf("rotate : %d\n", best_op);
	return (best_op);
}

int start_position(t_list **a, t_list **b)
{
	t_list  *tmp;
	int	 best_op;
	int	 next_op;
	int	 position;

	update_position(*a);
	update_position(*b);
	tmp = *b;
	position = tmp->content.position;
	if (place_in_a(a, tmp->content.index) > tmp->content.position)
		best_op = place_in_a(a, tmp->content.index);
	else
		best_op = tmp->content.position;
	while (tmp)
	{
		if (place_in_a(a, tmp->content.index) > tmp->content.position)
			next_op = place_in_a(a, tmp->content.index);
		else
			next_op = tmp->content.position;
		if (next_op < best_op)
		{
			best_op = next_op;
			position = tmp->content.position;
		}
		tmp = tmp->next;
	}
	return (position);
}

int best_reverse(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		best_op;
	int		next_op;
	int		size_a;

	update_rev_position(*a);
	update_rev_position(*b);
	tmp = *b;
	size_a = ft_lstsize(*a);
	best_op = place_in_a(a, tmp->content.index);
	while (tmp)
	{
		next_op = place_in_a(a, tmp->content.index);
		if (next_op < best_op)
			best_op = next_op;
		tmp = tmp->next;
	}
	// printf("reverse : %d\n", best_op);
	return (best_op);
}

int end_position(t_list **a, t_list **b)
{
	t_list  *tmp;
	int	 best_op;
	int	 next_op;
	int	 position;

	update_rev_position(*a);
	update_rev_position(*b);
	tmp = *b;
	position = tmp->content.position;
	best_op = place_in_a(a, tmp->content.index);
	while (tmp)
	{
		next_op = place_in_a(a, tmp->content.index);
		if (next_op < best_op)
		{
			best_op = next_op;
			position = tmp->content.position;
		}
		tmp = tmp->next;
	}
	return (position);
}


void	good_position(t_list **a, t_list **b)
{
	t_list *tmp;
	t_list *tmp2;
	
	update_position(*a);
	update_position(*b);
	while (*b)
	{
		update_position(*a);
		update_position(*b);
		printf("best reverse: %i - best rotate: %i\n", best_reverse(a, b), best_rotate(a, b));
		if (best_rotate(a, b) <= best_reverse(a, b))
			push_start(a, b);
		else
			push_end(a, b);
		tmp2 = *a;
		while (tmp2)
		{
			printf("a - position: %i - index: %i - element:%i\n", tmp2->content.position, tmp2->content.index, tmp2->content.element);
			tmp2 = tmp2 -> next;
		}
		printf("\n");
		tmp = *b;
		while (tmp)
		{
			printf("b - position: %i - index: %i - element:%i\n", tmp->content.position, tmp->content.index, tmp->content.element);
			tmp = tmp -> next;
		}
		printf("\n");
	}
}

void	push_start(t_list **a, t_list **b)
{
	int		pos_a;
	int		pos_b;
	int		dual;
	t_list	*tmp;

	tmp = *b;
	pos_b = start_position(a, b);
	while (tmp->content.position != pos_b)
		tmp = tmp->next;
	pos_a = place_in_a(a, tmp->content.index);
	// printf("pos a %i - pos b %i\n", pos_a, pos_b);
	if (pos_a > pos_b)
	{
		dual = pos_a - pos_b;
		// printf("dual rotate : %d\n", pos_b);
		while (pos_b)
		{
			rr(a, b);
			pos_b--;
		}
		while (dual)
		{
			ra(a);
			dual--;
		}
	}
	else
	{
		dual = pos_b - pos_a;
		// printf("dual rotate : %d\n", pos_a);
		while (pos_a)
		{
			rr(a, b);
			pos_a--;
		}
		while (dual)
		{
			rb(b);
			dual--;
		}
	}
	// tmp = *a;
	// while (tmp)
	// {
		// printf("a - position: %i - index: %i - element:%i\n", tmp->content.position, tmp->content.index, tmp->content.element);
	// 	tmp = tmp -> next;
	// }
	 printf("PUSH START\n");
	pa(a, b);
}

void	push_end(t_list **a, t_list **b)
{
	int		pos_a;
	int		pos_b;
	int		dual;
	t_list	*tmp;

	tmp = *b;
	pos_b = end_position(a, b);
	while (tmp->content.position != pos_b)
		tmp = tmp->next;
	pos_a = place_in_a(a, tmp->content.index);
	// printf("pos a %i - pos b %i\n", pos_a, pos_b);
	if (pos_a > pos_b)
	{
		dual = pos_a - pos_b;
		// printf("dual reverse : %d\n", pos_b);
		while (pos_b)
		{
			rrr(a, b);
			pos_b--;
		}
		while (dual)
		{
			rra(a);
			dual--;
		}
	}
	else
	{
		dual = pos_b - pos_a;
		// printf("dual reverse : %d\n", pos_a);
		while (pos_a)
		{
			rrr(a, b);
			pos_a--;
		}
		while (dual)
		{
			rrb(b);
			dual--;
		}
	}
/* 	tmp = *a;
	while (tmp)
	{
		// printf("a - position: %i - index: %i - element:%i\n", tmp->content.position, tmp->content.index, tmp->content.element);
		tmp = tmp -> next;
	} */
	 printf("PUSH END\n");
	pa(a, b);
}
// ./push_swap 6 22 17 11 16 13 1 19 2 8 15 3 10 5 25 23 4 18 21 12 7 9 14 20 24