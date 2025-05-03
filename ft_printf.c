/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:50:20 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/03 17:29:52 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if ((str[i] == '%') && ft_strchr("cspdiuxX%%", str[i + 1]))
		{
			i++;
			ft_detect_alnum(str[i], args);
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	int a = 5;
	printf("interger: %i ", NULL);
	printf("hexa: %x ", 10);
	printf("HEXA %X ", 13);
	printf("pourcent %% ");
	printf("decimal: %d ", 0X10);
	printf("unsigned: %u ", -42);
	printf("string: %s ", "test");
	printf("char : %c ", 'L');
	printf("pointeur : %p\n", &a);

	ft_printf("interger: %i ", NULL);
	ft_printf("hexa: %x ", 10);
	ft_printf("HEXA %X ", 13);
	ft_printf("pourcent %% ");
	ft_printf("decimal: %d ", 0X10);
	ft_printf("unsigned: %u ", -42);
	ft_printf("string: %s ", "test");
	ft_printf("char : %c ", 'L');
	ft_printf("pointeur : %p\n", &a);
}