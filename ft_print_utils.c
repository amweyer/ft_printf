/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:47:32 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/03 19:45:57 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	return (len);
}

int	ft_putnbr_b(int n, char *base)
{
	long	nb;
	char	c;
	int		len_base;
	int		len;

	nb = n;
	len = 0;
	len_base = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		len++;
	}
	if (nb / len_base > 0)
		len += ft_putnbr_b(nb / len_base, base);
	c = base[nb % len_base];
	ft_putchar(c);
	len++;
	return (len);
}

int	ft_putnbr_bu(unsigned long nb, char *base)
{
	char			c;
	unsigned long	len_base;
	int				len;

	len = 0;
	len_base = ft_strlen(base);
	c = base[nb % len_base];
	if (nb / len_base > 0)
		ft_putnbr_bu(nb / len_base, base);
	ft_putchar(c);
	len++;
	return (len);
}
