# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 12:05:28 by mherrezu          #+#    #+#              #
#    Updated: 2023/04/10 14:13:37 by mherrezu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c check_arguments.c libft_utils.c generate_list.c list_utils.c \
		push_swap.c mov_push_swap.c mov_rotate.c mov_reverse.c sort_algorithm.c \
		sort_free_utils.c do_movements.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
				$(RM) $(OBJS)

fclean: 	clean
						$(RM) $(NAME)

re:			fclean all 

py2: all
	python3 pythonvisualizer.py `ruby -e "puts (-1..0).to_a.shuffle.join(' ')"`

py3: all
	python3 pythonvisualizer.py `ruby -e "puts (-1..1).to_a.shuffle.join(' ')"`

py4: all
	python3 pythonvisualizer.py `ruby -e "puts (-2..1).to_a.shuffle.join(' ')"`
	
py5: all
	python3 pythonvisualizer.py `ruby -e "puts (-2..2).to_a.shuffle.join(' ')"`

py15: all
	python3 pythonvisualizer.py `ruby -e "puts (-7..8).to_a.shuffle.join(' ')"`

py30: all
	python3 pythonvisualizer.py `ruby -e "puts (-15..15).to_a.shuffle.join(' ')"`

py50: all
	python3 pythonvisualizer.py `ruby -e "puts (-25..25).to_a.shuffle.join(' ')"`

py100: all
	python3 pythonvisualizer.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`

py200: all
	python3 pythonvisualizer.py `ruby -e "puts (-100..100).to_a.shuffle.join(' ')"`

py500: all
	python3 pythonvisualizer.py `ruby -e "puts (-250..250).to_a.shuffle.join(' ')"`

.PHONY: all clean fclean re 