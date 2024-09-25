/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:38:56 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/25 16:19:55 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	is_in_mandelbrot(t_complex c)
{
	t_complex	z;
	int			counter;

	z.real = 0;
	z.imaginary = 0;
	counter = 0;
	while (counter < ITERATIONS)
	{
		z = iterator(c, z);
		if (z.real > 2 || z.real < -2)
			return (counter);
		counter++;
	}
	return (-1);
}

void	render_mandelbrot(t_data *data)
{
	int			i;
	int			j;
	double		tmp_i;
	double		tmp_j;
	t_complex	dot;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			tmp_i = i;
			tmp_j = j;
			translate_plain(data, &tmp_i, &tmp_j);
			dot = create_complex(tmp_i, tmp_j);
			img_pix_put(&data->img, j, i, get_color(is_in_mandelbrot(dot)));
			j++;
		}
		i++;
	}
}
