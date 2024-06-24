/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:22:47 by ggoy              #+#    #+#             */
/*   Updated: 2024/06/24 15:30:22 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_list **a)
{
	t_psnode	temp;

	temp = (*a)->next->content;
	(*a)->next->content = (*a)->content;
	(*a)->content = temp;
	printf("%s\n", "sa");
}

void	sb(t_list **b)
{
	t_psnode	temp;

	temp = (*b)->next->content;
	(*b)->next->content = (*b)->content;
	(*b)->content = temp;
	printf("%s\n", "rb");
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	printf("%s\n", "ss");
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
			ft_lstadd_back(&lst1, new1);
			new2 = ft_lstnew(makenode(ft_atoi(argv[i]), i));
			ft_lstadd_back(&lst2, new2);
			i++;
		}
		ss(&lst1, &lst2);
		while (lst1)
		{
			printf("%i\n", lst1 -> content . element);
			lst1 = lst1 -> next;
		}
		while (lst2)
		{
			printf("%i\n", lst2 -> content . element);
			lst2 = lst2 -> next;
		}
	}
}*/
