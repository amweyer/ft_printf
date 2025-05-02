# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 13:09:41 by amweyer           #+#    #+#              #
#    Updated: 2025/05/02 16:13:52 by amweyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = 	ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
	

BONUS_SRC = 	ft_lstadd_back_bonus.c\
				ft_lstadd_front_bonus.c\
				ft_lstclear_bonus.c\
				ft_lstdelone_bonus.c\
			


OBJS := $(SRC:%.c=%.o)

BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

NAME = libftprintf.a

CC = cc

CCFLAGS = -Wall -Werror -Wextra

all: $(NAME) 


$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	${CC} ${CCFLAGS} -c $< -o $@

bonus: $(BONUS_OBJS) $(OBJS)
	ar rcs $(NAME) $(BONUS_OBJS) $(OBJS)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

