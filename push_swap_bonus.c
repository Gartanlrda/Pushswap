/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:17:02 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/23 09:38:42 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_manual_sort(t_list **a, t_list **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		bonus_instructions(a, b, line);
		free (line);
	}
}

void	bonus_instructions(t_list **a, t_list **b, char *line)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		pa_bonus(a, b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb_bonus(a, b);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		ra_bonus(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb_bonus(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr_bonus(a, b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra_bonus(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb_bonus(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr_bonus(a, b);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb_bonus(b);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		sa_bonus(a);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss_bonus(a, b);
	else
		line_error(a, b, line);
}

void	line_error(t_list **a, t_list **b, char *line)
{
	ft_printf("Error\n");
	free (line);
	free_lst(*a);
	free_lst(*b);
	exit (EXIT_FAILURE);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char)s1[i] && (unsigned char)s2[i]) && n > i)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
