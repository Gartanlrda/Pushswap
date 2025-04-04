/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:28:06 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/18 16:33:59 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sortin_three(t_list **a)
{
	while (check_sort(*a) == 0)
	{
		if ((*a)->content.index < (*a)->next->content.index)
			rra(a);
		else if (((*a)->content.index > (*a)->next->content.index)
			&& ((*a)->content.index > ft_lstlast(*a)->content.index))
			ra(a);
		else
			sa(a);
	}
	return ;
}

static void	short_push_in_a(t_list **a, t_list **b)
{
	while (*b)
	{
		if (check_sort(*b) == 1)
		{
			pa(a, b);
			pa(a, b);
			sa(a);
		}
		else
		{
			pa(a, b);
			pa(a, b);
		}
	}
}

void	sortin_five(t_list **a)
{
	t_list	*b;
	int		mediane;

	b = NULL;
	mediane = 1 + (ft_lstsize(*a) / 2);
	while (ft_lstsize(b) < 2)
	{
		if ((*a)->content.index < mediane)
			pb(a, &b);
		else if ((*a)->next->content.index < mediane)
			sa(a);
		else
			rra(a);
	}
	sortin_three(a);
	short_push_in_a(a, &b);
}
