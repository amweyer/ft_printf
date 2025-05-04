/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:50:20 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/03 19:47:36 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if ((str[i] == '%') && (ft_strchr("cspdiuxX%%", str[i + 1])))
		{
			i++;
			len += ft_dispatch(str[i], &args);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("Test 2:\n");
// 	printf("%d\n",printf("+W6,ISz'%%a\n{f8%uQf", -392960297));
// 	printf("\n");
// 	printf("%d\n",ft_printf("+W6,ISz'%%a\n{f8%uQf", -392960297));
// 	printf("\n");
// 	return (0);
// }
