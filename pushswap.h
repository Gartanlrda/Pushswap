/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:39:13 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/15 14:18:30 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>

typedef struct s_psnode
{
	int	element;
	int	index;
	int	position;
}	t_psnode;

typedef struct s_list
{
	t_psnode		content;
	struct s_list	*next;
}	t_list;

void		index_maker(t_list *a);
void		sa(t_list **a);
void		sb(t_list **b);
void		ss(t_list **a, t_list **b);
void		ra(t_list **a);
void		rb(t_list **b);
void		rr(t_list **a, t_list **b);
void		rra(t_list **a);
void		rrb(t_list **b);
void		rrr(t_list **a, t_list **b);
void		pa(t_list **a, t_list **b);
void		pb(t_list **a, t_list **b);
void		ft_lstadd_back(t_list **lst, t_list *new);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *str);
void		*ft_calloc(size_t nb, size_t size);
int			ft_lstsize(t_list *lst);
int			is_valid(char *s);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(t_psnode content);
t_psnode	makenode(int element, int index, int position);
int			ft_atoi(const char *nptr);
int			check_sort(t_list *a);
int			ft_lstsize(t_list *lst);
void		sortin_five(t_list **a);
void		sortin_three(t_list **a);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		free_lst(t_list *lst);
void		update_position(t_list *a);
int			check_quarter(t_list *a, int quarter);
void		sortin_list(t_list **a);
void		find_best_op(t_list **a, t_list **b, int quarter);
int			index_max(t_list **a);
int			three_highest(t_list **a, int value);
int			find_back(t_list **a, int quarter);
int			find_front(t_list **a, int quarter);
void		update_rev_position(t_list *a);
int			op_in_a(t_list **a, int index_b);
int			best_b(t_list **a, t_list **b);
int			best_a(t_list **a, t_list **b);
int			op_in_b(t_list **a, t_list **b);
void		push_the_f(t_list **a, t_list **b);
void		dual_rotate(t_list **a, t_list **b);
void		dual_reverse(t_list **a, t_list **b);
void		mix_push(t_list **a, t_list **b);
void		rotator_a(t_list **a, t_list **b, int rev_a);
void		rotator_b(t_list **a, t_list **b, int rev_b);

#endif
