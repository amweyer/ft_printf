/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:00:45 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/03 17:19:23 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


void	ft_putnbr_base(int n, char *base)
{
	long	nb;
	char	c;
	int		len_base;

	nb = n;
	len_base = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb = -nb;
	}
	c = base[nb % len_base];
	if (nb / len_base > 0)
		ft_putnbr_base(nb / len_base, base);
	ft_putchar_fd(c, 1);
}
void	ft_putnbr_base_unisgned(unsigned long nb,char *base)
{
	char			c;
	unsigned long	len_base;

	len_base = ft_strlen(base);
	c = base[nb % len_base];
	if (nb / len_base > 0)
		ft_putnbr_base_unisgned(nb / len_base, base);
	ft_putchar_fd(c, 1);
}
