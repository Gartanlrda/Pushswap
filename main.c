/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:49:48 by ggoy              #+#    #+#             */
/*   Updated: 2024/06/27 05:09:14 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	valid_lst(t_list *lst)
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

void	free_lst(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = (lst)->next;
		free(lst);
		lst = tmp;
	}
}

static void	makelist(t_list **a, char **pre_sort)
{
	t_list		*new;
	int			i;
	static int	index = 1;

	i = 0;
	while (pre_sort[i])
	{
		new = ft_lstnew(makenode(ft_atoi(pre_sort[i]), index));
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
	//t_list	*b;
	t_list	*tmp;
	//t_list	*tmp2;
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
				return (0);
			}
			i++;
		}
		if (valid_lst(a) == 1)
		{
			index_maker(a);
			sortin_five(&a);
			tmp = a;
			//tmp2 = b;
			while (tmp)
			{
				printf("%i - %i\n", tmp->content.element, tmp->content.index);
				tmp = tmp -> next;
			}
			/*while (tmp2)
			{
				printf("%s\n", "Liste b:");
				printf("%i - %i\n", tmp2->content.element, tmp2->content.index);
				tmp2 = tmp2 -> next;
			}*/
		}
		else
			write(2, "Error\n", 6);
		free_lst(a);
		//free_lst(b);
	}
}
