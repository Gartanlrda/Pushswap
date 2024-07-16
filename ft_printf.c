/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:04:51 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/16 12:04:17 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	kastatet(char s, va_list args, int count)
{
	if (s == 'c')
	{
		ft_putchar(va_arg(args, int));
		count++;
	}
	else if (s == 's')
		count = ft_putstr(va_arg(args, char *), count);
	else if (s == 'p')
		count = ft_put_address(va_arg(args, unsigned long), count);
	else if (s == 'i' || s == 'd')
		count = ft_putnbr(va_arg(args, int), count);
	else if (s == 'x')
		count = ft_put_base(va_arg(args, unsigned int), count, \
					"0123456789abcdef", 16);
	else if (s == 'X')
		count = ft_put_base(va_arg(args, unsigned int), count, \
					"0123456789ABCDEF", 16);
	else if (s == 'u')
		count = ft_putnbr(va_arg(args, unsigned int), count);
	else if (s == '%')
	{
		ft_putchar('%');
		count++;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	args;

	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count = kastatet(s[i], args, count);
			i++;
		}
		else
		{
			ft_putchar(s[i]);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	int i;
	long long	j;

	j = -435;
	i = printf("%i\n", -435);
	printf("%d\n", i);
	i = ft_printf("%i\n", j);
	printf("%d\n", i);
}*/
