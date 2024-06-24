/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 02:49:37 by ggoy              #+#    #+#             */
/*   Updated: 2024/06/19 07:27:18 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (nptr[i] - '0') + result * 10;
		i++;
	}
	return (result * sign);
}

static int	ft_splitercell(char const *s, char c)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
		}
		else
		{
			result++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (result);
}

static int	sp(const char *s, int start, char c)
{
	int	i;

	i = 0;
	while (start + i < ((int)ft_strlen(s)) && s[start + i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**re;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = -1;
	re = ft_calloc(sizeof(char *), ft_splitercell(s, c) + 1);
	while (s && s[i] && j < (ft_splitercell(s, c)))
	{
		if (s[i] == c)
			while (s && s[i] && s[i] == c)
				i++;
		else
		{
			j++;
			k = 0;
			re[j] = ft_calloc(sizeof(char), sp(s, i, c) + 1);
			while (s[i] && s[i] != c)
				re[j][k++] = s[i++];
		}
	}
	return (re);
}

void	*ft_calloc(size_t nb, size_t size)
{
	char		*result;
	size_t		i;
	size_t		total;

	if (size && nb > (size_t)-1 / size)
		return (NULL);
	i = 0;
	total = size * nb;
	result = malloc(total);
	if (!result)
		return (NULL);
	while (i < total)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}
