/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:26:17 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/22 14:09:36 by ggoy             ###   ########.fr       */
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

void	final_sort(t_list **a)
{
	if ((*a)->content.index <= (ft_lstsize(*a) / 2))
	{
		while (check_sort(*a) != 1)
			rra(a);
	}
	else
	{
		while (check_sort(*a) != 1)
			ra(a);
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
