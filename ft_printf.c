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
			len += ft_dispatch(str[i], args);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

#include <stdio.h>

int	main(void)
{


    printf(" NULL %s NULL ", NULL);
    printf("\n");
    ft_printf(" NULL %s NULL ", NULL);
    
// 	int a = 5;
// 	printf("interger: %i ", 15);
// 	printf("hexa: %x ", 10);
// 	printf("HEXA %X ", 13);
// 	printf("pourcent %% ");
// 	printf("decimal: %d ", 0X10);
// 	printf("unsigned: %u ", -42);


// 	printf("char : %c ", 'L');
// 	printf("pointeur : %p\n", &a);

// 	ft_printf("interger: %i ", 15);
// 	ft_printf("hexa: %x ", 10);
// 	ft_printf("HEXA %X ", 13);
// 	ft_printf("pourcent %% ");
// 	ft_printf("decimal: %d ", 0X10);
// 	ft_printf("unsigned: %u ", -42);

// 	ft_printf("char : %c ", 'L');
// 	ft_printf("pointeur : %p\n", &a);

}
// #include <stdio.h>

// int	main(void)
// {
// 	int a = 5;

// 	// --- %c Tests (1–9) ---
// 	printf("Test 1:\n");
// 	printf("%c\n", '0');
// 	ft_printf("%c\n", '0');

// 	printf("Test 2:\n");
// 	printf("%c \n", '0');
// 	ft_printf("%c \n", '0');

// 	printf("Test 3:\n");
// 	printf("%c\n", '0' - 256);
// 	ft_printf("%c\n", '0' - 256);

// 	printf("Test 4:\n");
// 	printf("%c \n", '0' + 256);
// 	ft_printf("%c \n", '0' + 256);

// 	printf("Test 5:\n");
// 	printf("%c %c %c \n", '0', 0, '1');
// 	ft_printf("%c %c %c \n", '0', 0, '1');

// 	printf("Test 6:\n");
// 	printf("%c %c %c \n", ' ', ' ', ' ');
// 	ft_printf("%c %c %c \n", ' ', ' ', ' ');

// 	printf("Test 7:\n");
// 	printf("%c %c %c \n", '1', '2', '3');
// 	ft_printf("%c %c %c \n", '1', '2', '3');

// 	printf("Test 8:\n");
// 	printf("%c %c %c \n", '2', '1', 0);
// 	ft_printf("%c %c %c \n", '2', '1', 0);

// 	printf("Test 9:\n");
// 	printf("%c %c %c \n", 0, '1', '2');
// 	ft_printf("%c %c %c \n", 0, '1', '2');

// 	// --- %s Tests (2–9) ---
// 	printf("Test 2:\n");
// 	printf("%s\n", "");
// 	ft_printf("%s\n", "");

// 	printf("Test 3:\n");
// 	printf("%s \n", "");
// 	ft_printf("%s \n", "");

// 	printf("Test 4:\n");
// 	printf("%s \n", "");
// 	ft_printf("%s \n", "");

// 	printf("Test 5:\n");
// 	printf("%s \n", "-");
// 	ft_printf("%s \n", "-");

// 	printf("Test 6:\n");
// 	printf("%s %s \n", "", "-");
// 	ft_printf("%s %s \n", "", "-");

// 	printf("Test 7:\n");
// 	printf("%s %s \n", " - ", "");
// 	ft_printf("%s %s \n", " - ", "");

// 	printf("Test 8:\n");
// 	printf("%s %s %s %s %s\n", " - ", "", "4", "", "s2");
// 	ft_printf("%s %s %s %s %s\n", " - ", "", "4", "", "s2");

// 	printf("Test 9:\n");
// 	printf("%s %s %s %s %s \n", " - ", "", "4", "", "2 ");
// 	ft_printf("%s %s %s %s %s \n", " - ", "", "4", "", "2 ");

// 	return (0);
// }
