/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zooming_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:48:43 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/25 16:19:17 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	zoom_in(t_data *data, double x, double y)
{
	double	re;
	double	im;

	data->plain.start_x = x;
	data->plain.start_y = y;
	re = data->plain.left_x + (data->plain.start_x / WIDTH)
		* (data->plain.right_x - data->plain.left_x);
	data->plain.left_x = re - (re - data->plain.left_x) * (1 - SCALING_FACTOR);
	data->plain.right_x = re + (data->plain.right_x - re)
		* (1 - SCALING_FACTOR);
	im = data->plain.lower_y + (data->plain.start_y / HEIGHT)
		* (data->plain.upper_y - data->plain.lower_y);
	data->plain.lower_y = im - (im - data->plain.lower_y)
		* (1 - SCALING_FACTOR);
	data->plain.upper_y = im + (data->plain.upper_y - im)
		* (1 - SCALING_FACTOR);
}

void	zoom_out(t_data *data, double x, double y)
{
	double	re;
	double	im;

	data->plain.start_x = x;
	data->plain.start_y = y;
	re = data->plain.left_x + (data->plain.start_x / WIDTH)
		* (data->plain.right_x - data->plain.left_x);
	data->plain.left_x = re - (re - data->plain.left_x) * (1 + SCALING_FACTOR);
	data->plain.right_x = re + (data->plain.right_x - re)
		* (1 + SCALING_FACTOR);
	im = data->plain.lower_y + (data->plain.start_y / HEIGHT)
		* (data->plain.upper_y - data->plain.lower_y);
	data->plain.lower_y = im - (im - data->plain.lower_y)
		* (1 + SCALING_FACTOR);
	data->plain.upper_y = im + (data->plain.upper_y - im)
		* (1 + SCALING_FACTOR);
}
