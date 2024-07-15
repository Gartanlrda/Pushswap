/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:26:17 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/15 13:57:55 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	update_position(t_list *a)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = a;
	while (temp)
	{
		temp->content.position = i;
		temp = temp->next;
		i++;
	}
}

void	update_rev_position(t_list *a)
{
	t_list	*temp;
	int		i;

	i = ft_lstsize(a) - 1;
	temp = a;
	while (temp)
	{
		temp->content.position = i;
		temp = temp->next;
		i--;
	}
}

int	check_quarter(t_list *a, int quarter)
{
	t_list	*temp;

	temp = a;
	while (temp)
	{
		if (temp->content.index > quarter)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void	find_best_op(t_list**a, t_list **b, int quarter)
{
	int	i;

	update_position(*a);
	if (find_front(a, quarter) < find_back(a, quarter))
	{
		i = find_front(a, quarter);
		while (i > 0)
		{
			ra(a);
			i--;
		}
		pb(a, b);
	}
	else
	{
		i = find_back(a, quarter);
		while (i > 0)
		{
			rra(a);
			i--;
		}
		pb(a, b);
	}
}

int	find_front(t_list **a, int quarter)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *a;
	while (tmp->content.index > quarter
		|| three_highest(a, tmp->content.index) == 0)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
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
