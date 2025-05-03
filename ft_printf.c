/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:50:20 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/03 19:28:42 by amweyer          ###   ########.fr       */
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
            //ft_dispatch(str[i], args);
			len += ft_dispatch(str[i], args);
            i++;
		}
		else
        {
			len += ft_putchar(str[i]);
		    i++;
        }
	}
	va_end(args);
	return (len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int a = 5;
// 	printf("interger: %i ", 15);
// 	printf("hexa: %x ", 10);
// 	printf("HEXA %X ", 13);
// 	printf("pourcent %% ");
// 	printf("decimal: %d ", 0X10);
// 	printf("unsigned: %u ", -42);
// 	printf("string: %s ", "test");
// 	printf("char : %c ", 'L');
// 	printf("pointeur : %p\n", &a);

// 	ft_printf("interger: %i ", 15);
// 	ft_printf("hexa: %x ", 10);
// 	ft_printf("HEXA %X ", 13);
// 	ft_printf("pourcent %% ");
// 	ft_printf("decimal: %d ", 0X10);
// 	ft_printf("unsigned: %u ", -42);
// 	ft_printf("string: %s ", "test");
// 	ft_printf("char : %c ", 'L');
// 	ft_printf("pointeur : %p\n", &a);

// }

// #include <stdio.h>

// #define TEST(num, expr) printf("Test %d: %s\n", num, expr);

// int	main(void)
// {
// 	// Tests pour %c
// 	TEST(1, printf("%c", '0'));
// 	TEST(2, printf(" %c ", '0'));
// 	TEST(3, printf(" %c", '0' - 256));
// 	TEST(4, printf("%c ", '0' + 256));
// 	TEST(5, printf(" %c %c %c ", '0', 0, '1'));
// 	TEST(6, printf(" %c %c %c ", ' ', ' ', ' '));
// 	TEST(7, printf(" %c %c %c ", '1', '2', '3'));
// 	TEST(8, printf(" %c %c %c ", '2', '1', 0));
// 	TEST(9, printf(" %c %c %c ", 0, '1', '2'));

// 	// Tests pour %s
// 	TEST(2, printf(" %s", ""));
// 	TEST(3, printf("%s ", ""));
// 	TEST(4, printf(" %s ", ""));
// 	TEST(5, printf(" %s ", "-"));
// 	TEST(6, printf(" %s %s ", "", "-"));
// 	TEST(7, printf(" %s %s ", " - ", ""));
// 	TEST(8, printf(" %s %s %s %s %s", " - ", "", "4", "", "s2"));
// 	TEST(9, printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));

// 	return (0);
// }