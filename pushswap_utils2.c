/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 02:50:06 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/02 20:54:47 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

static int	is_num(char c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	else
		return (0);
}

int	is_valid(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (is_space(s[i]) == 1 || is_num(s[i]) == 1)
		{
			if (s[i] == '-')
			{
				if (is_space(s[i - 1]) || i == 0)
					i++;
				else
					return (0);
			}
			else
				i++;
		}
		else
			return (0);
	}
	return (1);
}

static void	swap_index(t_list *a, t_list *start)
{
	int	tmp;

	tmp = (a)->content.index;
	(a)->content.index = start->content.index;
	start->content.index = tmp;
}

void	index_maker(t_list *a)
{
	t_list	*temp;
	t_list	*start;

	temp = a;
	start = a;
	while (start)
	{
		a = start->next;
		while (a)
		{
			if ((start->content.element > (a)->content.element)
				&& (start->content.index < (a)->content.index)
				|| (start->content.element < (a)->content.element)
				&& (start->content.index > (a)->content.index))
			{
				swap_index(a, start);
				start = temp;
				a = start->next;
			}
			else
				a = (a)->next;
		}
		start = start->next;
	}
}
