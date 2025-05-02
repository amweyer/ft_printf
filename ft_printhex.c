/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:00:45 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/02 19:26:16 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (siz > 0)
	{
		while (src[i] && i < (siz - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
void	ft_printhex(int n, int h_case)
{
	long	nb;
	char	c;
	char	*hexa_base;

	nb = n;
	hexa_base = malloc(17 * sizeof(char));
	if (!hexa_base)
		return ;
	if (!h_case)
		ft_strlcpy(hexa_base, "0123456789abcdef", 17);
	else
		ft_strlcpy(hexa_base, "0123456789ABCDEF", 17);
	if (nb < 0)
	{
		ft_putchar_fd('-');
		nb = -nb;
	}
	c = hexa_base[nb % 16];
	if (nb / 16 > 0)
		ft_printhex(nb / 16, h_case);
        ft_putchar_fd(c);
}

int	main(void)
{
	ft_printhex(159, 1);
}