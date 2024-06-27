/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:27:27 by ggoy              #+#    #+#             */
/*   Updated: 2024/06/27 04:28:34 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	printf("%s\n", "pa");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	printf("%s\n", "pb");
}
/*
int	main(int argc, char **argv)
{
	t_list	*new;
	t_list	*lst1;
	t_list	*lst2;
	int		i;

	i = 1;
	if (argc > 1)
	{
		lst1 = ft_lstnew(makenode(ft_atoi(argv[i]), i));
		i++;
		lst2 = ft_lstnew(makenode(ft_atoi(argv[i]), i));
		i++;
		while (argv[i])
		{
			new = ft_lstnew(makenode(ft_atoi(argv[i]), i));
			ft_lstadd_back(&lst2, new);
			i++;
		}
		pb(&lst1, &lst2);
		while (lst1)
		{
			printf("%i\n", lst1 -> content . element);
			lst1 = lst1 -> next;
		}
	}
}*/
