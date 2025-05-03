/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:23:36 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/03 17:29:25 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_detect_char(char c, va_list args)
{
	char	c_char;
	char	*c_str;

	if (c == 'c')
	{
		c_char = (char)va_arg(args, int);
		ft_putchar_fd(c_char, 1);
	}
	if (c == 's')
	{
		c_str = va_arg(args, char *);
		ft_putstr_fd(c_str, 1);
	}
}

void	ft_detect_unsigned(char c, va_list args)
{
	unsigned int	c_uint;
	unsigned long	c_ulong;

	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		c_ulong = va_arg(args, unsigned long);
		ft_putnbr_base_unisgned(c_ulong, "0123456789abcdef");
	}
	if (c == 'u')
	{
		c_uint = va_arg(args, unsigned int);
		ft_putnbr_base_unisgned(c_uint, "0123456789");
	}
}

void	ft_detect_int(char c, va_list args)
{
	int	i;

	i = va_arg(args, int);
	if ((c == 'd') || (c == 'i'))
		ft_putnbr_base(i, "0123456789");
	if (c == 'x')
		ft_putnbr_base(i, "0123456789abcdef");
	if (c == 'X')
		ft_putnbr_base(i, "0123456789ABCDEF");
}

void	ft_detect_alnum(char c, va_list args)
{
	if (!args)
		return ;
	if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 'd' || c == 'i' || c == 'x' || c == 'X')
		ft_detect_int(c, args);
	else if (c == 'p' || c == 'u')
		ft_detect_unsigned(c, args);
	else
		ft_detect_char(c, args);
}