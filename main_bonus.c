/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:13:21 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/18 17:52:30 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	if (valid_lst(*a) == 1)
	{
		index_maker(*a);
		do_manual_sort(a);
	}
	else
	{
		write(2, "Error\n", 6);
		return ;
	}
	if (check_sort(*a) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_lst(*a);
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
		do_pushswap_bonus(&a);
	}
}
