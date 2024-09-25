/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:02:09 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/25 16:17:26 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define HEIGHT 1080
# define WIDTH 1920
# define SCALING_FACTOR 0.04
# define MLX_ERROR 1
# define BLACK 0x000000
# define ITERATIONS 80

# define MANDELBROT 0
# define JULIA 1
# define TRICORN 2

# include "../libft/libft.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <math.h>

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_plain
{
	double	start_x;
	double	start_y;
	double	left_x;
	double	right_x;
	double	upper_y;
	double	lower_y;
}	t_plain;

typedef struct s_data
{
	int			fractal;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_plain		plain;
	t_complex	julia_c;
}	t_data;

double		ft_atof(char *number);
int			get_color(int iter);
int			handle_keypress(int keysum, t_data *data);
int			handle_mouse_click(int mouse_code, t_data *data);
int			handle_scaling(int keysum, int x, int y, t_data *data);
int			initialize_window(int fractal, t_complex c);
int			is_in_julia(t_complex c, t_complex z);
int			is_in_mandelbrot(t_complex c);
int			is_in_tricorn(t_complex c);
size_t		max_size(size_t a, size_t b);
t_complex	complex_sum(t_complex x, t_complex y);
t_complex	complex_square(t_complex z);
t_complex	conjugate(t_complex z);
t_complex	create_complex(double x, double y);
t_complex	iterator(t_complex c, t_complex z);
void		img_pix_put(t_img *img, int x, int y, int color);
void		render_julia(t_complex c, t_data *data);
void		render_mandelbrot(t_data *data);
void		render_tricorn(t_data *data);
void		translate_plain(t_data *data, double *i, double *j);
void		zoom_in(t_data *data, double x, double y);
void		zoom_out(t_data *data, double x, double y);

#endif
