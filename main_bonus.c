/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:13:21 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/23 09:43:51 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

static void	makelist(t_list **a, char **pre_sort)
{
	t_list		*new;
	int			i;
	static int	index = 1;

	i = 0;
	new = NULL;
	while (pre_sort[i])
	{
		if (ft_atoi(pre_sort[i]) > INT_MAX || ft_atoi(pre_sort[i]) < INT_MIN)
		{
			write(2, "Error\n", 6);
			free_tab(pre_sort);
			free_lst(*a);
			exit(EXIT_FAILURE);
		}
		new = ft_lstnew(makenode(ft_atoi(pre_sort[i]), index, index));
		ft_lstadd_back(a, new);
		i++;
		index++;
	}
}

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

void	do_pushswap_bonus(t_list **a)
{
	t_list	*b;

	b = NULL;
	if (*a)
	{
		if (valid_lst(*a) == 1)
		{
			index_maker(*a);
			do_manual_sort(a, &b);
		}
		else
		{
			write(2, "Error\n", 6);
			free_lst(*a);
			return ;
		}
		if (check_sort(*a) == 1 && b == NULL)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_lst(*a);
		free_lst(b);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	char	**pre_sort;
	int		i;

	i = 0;
	a = NULL;
	if (argc > 1)
	{
		while (argv[++i])
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
				return (0);
			}
		}
		do_pushswap_bonus(&a);
	}
}
