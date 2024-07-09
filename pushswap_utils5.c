/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 08:14:47 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/09 10:12:44 by ggoy             ###   ########.fr       */
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

/*void	good_position(t_list **a, t_list **b)
{
	int i;
		
	i = 0;
	while (*b)
	{
		if (is_possible(a, b) == 1)
			pa(a, b);
		while ((*b) && i > 0)
		{
			if (is_possible(a, b) == 1)
				pa(a, b);
			else
			{
				if (is_possible(a, b) == 1)
					pa(a, b);
				rrb(b);
				i--;
			}
		}
		while (ft_lstsize(*b) > 1 && is_possible(a, b) == 0)
		{
			rb(b);
			i++;
		}
	}
}

int is_possible(t_list **a, t_list **b)
{
	if (*b)
	{
		if (ft_lstsize(*b) > 1 && (*b)->next->content.index == ((*a)->content.index - 1))
			sb(b);
		if ((*a)->content.index == ((*a)->next->content.index + 1))
			sa(a);
		if (((*a)->content.index == ((*a)->next->content.index - 1))
			&& (((*b)->content.index == ((*a)->content.index - 1))
			|| ((*b)->content.index == ((*a)->content.index - 2))))
			return (1);
		else if (((*a)->content.index == ((*a)->next->content.index - 2))
			&& (((*b)->content.index == ((*a)->content.index + 1))))
		{
			pa(a, b);
			sa(a);
		}
		else
			return (0);
	}
	return (0);
}*/
// calculer le meilleur chiffre a push avec le moins de coups a faire
// nombre de coup pour positionner a / nombre de coup pour positionner B
// checker pour combiner rrr et rr ss
// checker si les chiffre sera le plus petit de A
// simuler combien de coup il faudrait a chaque b pour etre a la bonne place dans a
// +1 pour leur position, +1 pour le push, - le nombre de rota dans a;
// Determiner la bonne place dans A:
// Tout les next sont superieurs, while(next <) alors next
// comment memoriser le nombre de coup pour chaque element?

// Quelles fonctions?

// Place dans A: return int du nbr d'operations a faire

int place_in_a(t_list **a, int index_b)
{
	t_list  *tmp;
	int	 i;
	int	lower_big;
	
	i = 0;
	tmp = *a;
	lower_big = index_max(a);
	//printf("index :%i\n", index_b);
	while (tmp)
	{
		if (tmp->content.index > index_b && tmp->content.index < lower_big)
		{
			lower_big = tmp->content.index;
			i = tmp->content.position;
		}
		tmp = tmp->next;
	}
	// while (tmp)
	// {
	// 	if (tmp->content.index < index_b)
	// 	{
	// 		if (lower_big > tmp->content.index)
	// 		{
	// 			lower_big = tmp->content.index;
	// 			i = tmp->content.position;
	// 		}
	// 	}
	// 	tmp = tmp->next;
	// }
	//printf("i :%i\n", i);
	return (i);
}

// Parcourir B en utilisant ^; calculer le resultat et si ^ est plus grand return ^ sinon return position, le tout +1 (push)

int best_start(t_list **a, t_list **b)
{
	t_list  *tmp;
	int	 best_op;
	int	 next_op;

	tmp = *b;
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
	printf("rotate : %d\n", best_op);
	return (best_op);
}

int start_position(t_list **a, t_list **b)
{
	t_list  *tmp;
	int	 best_op;
	int	 next_op;
	int	 position;

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
// Faire les memes mais en partant de la fin

int best_end(t_list **a, t_list **b)
{
	t_list  *tmp;
	int	 best_op;
	int	 next_op;
	int	 size_a;
	int	 size_b;

	tmp = *b;
	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	if ((size_a - place_in_a(a, tmp->content.index)) > (size_b - tmp->content.position))
		best_op = (size_a - place_in_a(a, tmp->content.index));
	else
		best_op = (size_b - tmp->content.position);
	while (tmp)
	{
		if ((size_a - place_in_a(a, tmp->content.index)) > (size_b - tmp->content.position))
			next_op = (size_a - place_in_a(a, tmp->content.index));
		else
			next_op = (size_b - tmp->content.position);
		if (next_op < best_op)
			best_op = next_op;
		tmp = tmp->next;
	}
	printf("reverse : %d\n", best_op);
	return (best_op);
}

int end_position(t_list **a, t_list **b)
{
	t_list  *tmp;
	int	 best_op;
	int	 next_op;
	int	 size_a;
	int	 size_b;
	int	 position;

	tmp = *b;
	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	position = tmp->content.position;
	if ((size_a - place_in_a(a, tmp->content.index)) > (size_b - tmp->content.position))
		best_op = (size_a - place_in_a(a, tmp->content.index));
	else
		best_op = (size_b - tmp->content.position);
	while (tmp)
	{
		if ((size_a - place_in_a(a, tmp->content.index)) > (size_b - tmp->content.position))
			next_op = (size_a - place_in_a(a, tmp->content.index));
		else
			next_op = (size_b - tmp->content.position);
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
		if (best_start(a, b) < best_end(a, b))
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
	if (pos_a > pos_b)
	{
		dual = pos_a - pos_b;
		printf("dual rotate : %d\n", pos_b);
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
		printf("dual rotate : %d\n", pos_a);
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
	// 	printf("a - position: %i - index: %i - element:%i\n", tmp->content.position, tmp->content.index, tmp->content.element);
	// 	tmp = tmp -> next;
	// }
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
	if (pos_a > pos_b)
	{
		dual = pos_a - pos_b;
		printf("dual reverse : %d\n", pos_b);
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
		printf("dual reverse : %d\n", pos_a);
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
		printf("a - position: %i - index: %i - element:%i\n", tmp->content.position, tmp->content.index, tmp->content.element);
		tmp = tmp -> next;
	} */
	pa(a, b);
}
// prendre le meilleur resultat des deux et l'appliquer