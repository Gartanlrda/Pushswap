/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 02:44:58 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/04 03:46:14 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

t_psnode	makenode(int element, int index, int position)
{
	t_psnode	node;

	node . position = position;
	node . element = element;
	node . index = index;
	return (node);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst -> next)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

t_list	*ft_lstnew(t_psnode content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list -> content = content;
	list -> next = NULL;
	return (list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst && *lst)
		ft_lstlast(*lst)-> next = new;
	else
		*lst = new;
}
