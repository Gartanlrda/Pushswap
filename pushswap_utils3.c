/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:28:06 by ggoy              #+#    #+#             */
/*   Updated: 2024/06/24 18:49:23 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return ((size_t)i);
}

int	check_sort(t_list *a)
{
	while (a->next)
	{
		if (a->next->content.index < a->content.index)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

void	sortin_three(t_list *a)
{
	while (check_sort(a) == 0)
	{
		printf("%i\n", check_sort(a));
		if (ft_lstlast(a)->content.index < a->content.index)
			rra(&a);
		else
			sa(&a);
	}
	return ;
}

void	sortin_five(t_list *a)
{
	t_list	*b;
	int		mediane;

	b = NULL;
	mediane = 1 + (ft_lstsize(a) / 2);
	printf("%i\n", mediane);
	while (ft_lstsize(b) < 2)
	{
		if (a->content.index > mediane)
			pb(&a,&b);
		else if (a->next->content.index > mediane)
			sa(&a);
		else
			rra(&a);
	}
	sortin_three(a);
	while (b)
	{
		if (check_sort(b) == 1)
		{
			pa(&a, &b);
			ra(&a);
			pa(&a, &b);
			ra(&a);
		}
		else
		{
			pa(&a, &b);
			pa(&a, &b);
			ra(&a);
			ra(&a);
		}
	}
}
