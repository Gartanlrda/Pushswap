/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:46:02 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/18 13:49:39 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*ft_kastonkrane(char *status, char temp[BUFFER_SIZE + 1])
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	while (status && status[i] != '\n' && status[i])
		i++;
	if (status[i] == '\n')
		i++;
	result = ft_strjoin(NULL, status, i);
	j = 0;
	while (status[i])
	{
		temp[j] = status[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	free(status);
	return (result);
}

int	ft_check(char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	static char	stat[100][BUFFER_SIZE + 1];
	int			last;

	tmp = NULL;
	if (fd < 0 || fd > 129)
		return (NULL);
	if (stat[fd][0])
		tmp = ft_strdup(stat[fd]);
	last = 1;
	while (ft_check(stat[fd]) == 0 && last)
	{
		last = read(fd, stat[fd], BUFFER_SIZE);
		if (last < 0)
			return (free(tmp), NULL);
		stat[fd][last] = '\0';
		tmp = ft_strjoin(tmp, stat[fd], (ft_strlen(stat[fd])
					+ ft_strlen(tmp) + 1));
	}
	if (last == 0 && tmp[0])
		return (tmp);
	if (last == 0)
		return (free(tmp), NULL);
	return (ft_kastonkrane(tmp, stat[fd]));
}

/*
int	main(void)
{
	int	fd;
	int	i;
	char	*result;

	i = 1;
	fd = open("42_with_nl", O_RDONLY);
	while (i < 8)
	{
		result = get_next_line(fd);
		printf("ligne%i = %s", i, result);
		free(result);
		i++;
	}
}
*/

/*int	main(int ac, char **av)
{
	int	fd;
	int	i;
	char	*result;

	i = 0;
	fd = open(av[1], O_RDONLY);
	result = "";
	while (result)
	{
		result = get_next_line(fd);
		printf("%s", result);
		free(result);
		i++;
		if (i == 30)
			break ;
	}
}*/
