/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:13:49 by ggoy              #+#    #+#             */
/*   Updated: 2024/06/27 04:28:08 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_list **a)
{
	t_list	*temp;

	temp = (*a);
	(*a) = (*a)->next;
	temp->next = NULL;
	ft_lstadd_back(a, temp);
	printf("%s\n", "ra");
}

void	rb(t_list **b)
{
	t_list	*temp;

	temp = (*b);
	(*b) = (*b)->next;
	temp->next = NULL;
	ft_lstadd_back(b, temp);
	printf("%s\n", "rb");
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	printf("%s\n", "rrr");
}
/*
int	main(int argc, char **argv)
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*new1;
	t_list	*new2;
	int		i;

	i = 1;
	if (argc > 1)
	{
		lst1 = ft_lstnew(makenode(ft_atoi(argv[i]), i));
		lst2 = ft_lstnew(makenode(ft_atoi(argv[i]), i));
		i++;
		while (argv[i])
		{
			new1 = ft_lstnew(makenode(ft_atoi(argv[i]), i));
			new2 = ft_lstnew(makenode(ft_atoi(argv[i]), i));
			ft_lstadd_back(&lst1, new1);
			ft_lstadd_back(&lst2, new2);
			i++;
		}
	}
	rr(&lst1, &lst2);
	while(lst1)
	{
		printf("%i\n", lst1 -> content . element);
		lst1 = lst1 -> next;
	}
	while(lst2)
	{
		printf("%i\n", lst2 -> content . element);
		lst2 = lst2 -> next;
	}
}*/
