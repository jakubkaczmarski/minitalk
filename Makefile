# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 13:53:09 by jkaczmar          #+#    #+#              #
#    Updated: 2022/02/05 20:27:47 by jkaczmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


all: client server

client:
	gcc -Wall -Wextra -Werror -o client	client.c ft_atoi.c ft_printf/ft_printf.c ft_printf/ft_putchar.c	ft_printf/ft_putstr_fd.c	ft_printf/typecheck.c	ft_printf/ft_putnbr_fd.c	ft_printf/ft_strlen.c	ft_printf/ft_puttinghex.c	ft_printf/ft_printstuff.c

server:
	gcc -Wall -Wextra -Werror -o server server.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_putstr_fd.c	ft_printf/typecheck.c	ft_printf/ft_putnbr_fd.c	ft_printf/ft_strlen.c	ft_printf/ft_puttinghex.c	ft_printf/ft_printstuff.c

# all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	@rm -f server.o client.o

re: fclean all

.PHONY: all clean fclean re
