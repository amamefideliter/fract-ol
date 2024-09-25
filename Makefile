# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 10:22:51 by dzubkova          #+#    #+#              #
#    Updated: 2024/09/25 16:18:58 by dzubkova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PFX = sources/

SRCS = $(PFX)fract_ol.c $(PFX)complex_utils.c $(PFX)mandelbrot.c $(PFX)graphic_utils.c $(PFX)zooming_fractal.c $(PFX)julia.c $(PFX)tricorn.c $(PFX)fract_ol_utils.c main.c
OFILES = $(SRCS:.c=.o)

NAME = fract-ol

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -lXext -lX11 -L minilibx-linux
MAKE = make

all: $(NAME)

$(NAME): $(OFILES)
	$(MAKE) bonus -C ./libft
	cc $(CFLAGS) $(OFILES) -lm $(MLXFLAGS) libft/libft.a -o $(NAME)

%.o: %.c
	cc -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OFILES)
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all clean re fclean
