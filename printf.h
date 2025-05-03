/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:59:44 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/03 17:48:19 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putnbr_base(int n, char *base);
void	ft_putnbr_base_unisgned(unsigned long nb, char *base);
void	ft_detect_alnum(char c, va_list args);
void	ft_detect_int(char c, va_list args);
void	ft_detect_unsigned(char c, va_list args);
void	ft_detect_char(char c, va_list args);

#endif