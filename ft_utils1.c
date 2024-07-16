/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:22:49 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/16 12:04:37 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_putstr(char *s, int count)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)", count));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
		count ++;
	}
	return (count);
}

int	ft_putnbr(long long nb, int count)
{
	static int	i;

	i = count;
	if (nb < 0)
	{
		i++;
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb < 10)
	{
		i++;
		ft_putchar(nb + '0');
	}
	if (nb > 9)
	{
		ft_putnbr((nb / 10), i);
		ft_putnbr((nb % 10), i);
	}
	return (i);
}

int	ft_put_base(unsigned long nb, int count, char *base, unsigned int lenb)
{
	static int	i;

	i = count;
	if (nb < 0)
	{
		i++;
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb < lenb)
	{
		i++;
		ft_putchar(base[nb]);
	}
	if (nb > (lenb - 1))
	{
		ft_put_base((nb / lenb), i, base, lenb);
		ft_put_base((nb % lenb), i, base, lenb);
	}
	return (i);
}

int	ft_put_address(unsigned long ptr, int count)
{
	if (!ptr)
		return (ft_putstr("(nil)", count));
	count = ft_putstr("0x", count);
	count = ft_put_base(ptr, count, "0123456789abcdef", 16);
	return (count);
}
/*
int main(void)
{
	int	i;

	i = ft_putnbr(-435, 0);
	printf("\n%i\n", i);
}*/
