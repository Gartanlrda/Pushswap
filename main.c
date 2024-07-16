/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:49:48 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/16 11:42:28 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	valid_lst(t_list *lst)
{
	t_list	*checker;
	t_list	*start;

	start = lst;
	lst = lst->next;
	while (lst)
	{
		checker = start;
		while (checker && checker->content.index < lst->content.index)
		{
			if (checker->content.element == lst->content.element)
				return (0);
			else
				checker = checker->next;
		}
		lst = lst->next;
	}
	return (1);
}

void	do_pushswap(t_list **a)
{
	t_list	*tmp;

	if (valid_lst(*a) == 1)
	{
		index_maker(*a);
		sortin_list(a);
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
		tmp = *a;
	}
	else
		write(2, "Error\n", 6);
	free_lst(*a);
}

/*		while (tmp)
		{
			ft_printf("position: %i - index: %i - element: %i;\n", \
			tmp->content.position, tmp->content.index, tmp->content.element);
			tmp = tmp->next;
		}*/

static void	makelist(t_list **a, char **pre_sort)
{
	t_list		*new;
	int			i;
	static int	index = 1;

	i = 0;
	while (pre_sort[i])
	{
		new = ft_lstnew(makenode(ft_atoi(pre_sort[i]), index, index));
		ft_lstadd_back(a, new);
		i++;
		index++;
		new = NULL;
	}
}

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	char	**pre_sort;
	int		i;

	i = 1;
	a = NULL;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (is_valid(argv[i]) == 1)
			{
				pre_sort = ft_split(argv[i], ' ');
				makelist(&a, pre_sort);
				free_tab(pre_sort);
			}
			else
			{
				free_lst(a);
				write(2, "Error\n", 6);
			}
			i++;
		}
		do_pushswap(&a);
	}
}
