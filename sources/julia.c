/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:12:44 by daria             #+#    #+#             */
/*   Updated: 2024/09/25 16:19:50 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	is_in_julia(t_complex c, t_complex z)
{
	int	counter;

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

void	render_julia(t_complex c, t_data *data)
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
			img_pix_put(&data->img, j, i, get_color(is_in_julia(c, dot)));
			j++;
		}
		i++;
	}
}
