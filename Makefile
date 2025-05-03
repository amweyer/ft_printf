# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 13:09:41 by amweyer           #+#    #+#              #
#    Updated: 2025/05/03 17:54:30 by amweyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_detect.c\
		ft_putnbr_base.c\
		ft_printf.c\

SUPP_SRC = $(addprefix libft/ ,ft_atoi.c\
							ft_bzero.c\
							ft_calloc.c\
							ft_isalnum.c\
							ft_isalpha.c\
							ft_isascii.c\
							ft_isdigit.c\
							ft_isprint.c\
							ft_itoa.c\
							ft_memchr.c\
							ft_memcmp.c\
							ft_memcpy.c\
							ft_memmove.c\
							ft_memset.c\
							ft_putchar_fd.c\
							ft_putendl_fd.c\
							ft_putnbr_fd.c\
							ft_putstr_fd.c\
							ft_strchr.c\
							ft_strdup.c\
							ft_striteri.c\
							ft_strjoin.c\
							ft_strlcat.c\
							ft_strlcpy.c\
							ft_strlen.c\
							ft_strmapi.c\
							ft_strncmp.c\
							ft_strnstr.c\
							ft_strrchr.c\
							ft_strtrim.c\
							ft_substr.c\
							ft_tolower.c\
							ft_toupper.c\
							ft_split.c\)

OBJS := $(SRC:%.c=%.o)

SUPP_OBJS := $(SUPP_SRC:%.c=%.o)

NAME = libftprintf.a

CC = cc

CCFLAGS = -Wall -Werror -Wextra 

INC_DIR = libft

CCDIR = -I$(INC_DIR)

all: $(NAME) 

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	${CC} ${CCDIR} ${CCFLAGS} -c $< -o $@

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all
