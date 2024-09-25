/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:25:04 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/25 16:19:37 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static int	render(t_data *data);
static void	initialize_data(t_data *data, int fractal, t_complex c);
static void	initialize_hooks(t_data *data);

int	initialize_window(int fractal, t_complex c)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	initialize_data(&data, fractal, c);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	initialize_hooks(&data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	free(data.img.mlx_img);
	return (0);
}

static void	initialize_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, ButtonPressMask,
		&handle_mouse_click, data);
	mlx_mouse_hook(data->win_ptr, &handle_scaling, data);
}

static void	initialize_data(t_data *data, int fractal, t_complex c)
{
	data->plain.start_x = WIDTH / 2;
	data->plain.start_y = HEIGHT / 2;
	data->plain.left_x = -2.2;
	data->plain.right_x = 1.94;
	data->plain.lower_y = -1.1;
	data->plain.upper_y = 1.15;
	data->fractal = fractal;
	data->julia_c = c;
}

static int	render(t_data *data)
{
	if (!data->win_ptr)
		return (MLX_ERROR);
	if (data->fractal == MANDELBROT)
		render_mandelbrot(data);
	else if (data->fractal == JULIA)
		render_julia(data->julia_c, data);
	else
		render_tricorn(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}
