/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:42:54 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/18 16:55:27 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# include <stdlib.h>

int		ft_strlen_gnl(char *s);
int		ft_check(char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, int len);
char	*ft_strdup(char *s);
char	*ft_kastonkrane(char *status, char temp[BUFFER_SIZE + 1]);

#endif
