/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc <hzakharc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:51:02 by hzakharc          #+#    #+#             */
/*   Updated: 2024/06/22 17:05:31 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int ft_put_hex(size_t n, int type)
{
	size_t	i;
	char *s_lower = "0123456789abcdef";
	char *s_upper = "0123456789ABCDEF";
	
	i = 0;
	if (n / 16)
		i += ft_put_hex(n / 16, type);

	if (type == 0)
		ft_putchar_fd(s_lower[n % 16], 1);
	else
		ft_putchar_fd(s_upper[n % 16], 1);
	return (i + 1);
}

static	int ft_put_ptr(void *ptr)
{
	size_t	i;
	
	i = 0;
	ft_putstr_fd("0x", 1);
	i += 2;
	i += ft_put_hex((size_t)&ptr, 0);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	int size;
	va_list	args;

	i = 0;
	size = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'c')
			{
				ft_putchar_fd(va_arg(args, int), 1);
				size++;
				i++;
			}
			else if (s[i] == 's')
			{
				ft_putstr_fd(va_arg(args, char *), 1);
				size += ft_strlen(va_arg(args, char *));
				i++;
			}
			else if (s[i] == 'x')
			{
				size += ft_put_hex(va_arg(args, unsigned long), 0);
				i++;
			}
			else if (s[i] == 'X')
			{
				size += ft_put_hex(va_arg(args, unsigned long), 1);
				i++;
			}
			else if (s[i] == 'p')
			{
				size += ft_put_ptr(va_arg(args, void *));
				i++;
			}
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			size++;
			i++;
		}
	}
	
	return (size);
}
