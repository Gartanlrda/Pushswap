/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:22:10 by ggoy              #+#    #+#             */
/*   Updated: 2024/06/27 04:27:51 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_list **a)
{
	t_list		*temp;
	t_list		*temp2;

	temp2 = (*a);
	temp = ft_lstlast(*a);
	while (temp2->next != temp)
		temp2 = temp2->next;
	temp2->next = NULL;
	ft_lstadd_front(a, temp);
	printf("%s\n", "rra");
}

void	rrb(t_list **b)
{
	t_list		*temp;
	t_list		*temp2;

	temp2 = (*b);
	temp = ft_lstlast(*b);
	while (temp2->next != temp)
		temp2 = temp2->next;
	temp2->next = NULL;
	ft_lstadd_front(b, temp);
	printf("%s\n", "rrb");
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	printf("%s\n", "rrr");
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
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
	rrr(&lst1, &lst2);
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
