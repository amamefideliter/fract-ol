/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:43:04 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/25 16:17:17 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fract_ol.h"

static int	initialize_julia(char **argv, t_complex c);
static int	check_julia_args(char **argv);
static void	usage_error(void);
static void	check_valid_fractal(int argc, char **argv, t_complex c);

int	main(int argc, char **argv)
{
	t_complex	c;

	c.real = 0;
	c.imaginary = 0;
	if (argc < 2)
		usage_error();
	check_valid_fractal(argc, argv, c);
	return (0);
}

static int	initialize_julia(char **argv, t_complex c)
{
	c.real = ft_atof(argv[2]);
	c.imaginary = ft_atof(argv[3]);
	if (initialize_window(JULIA, c))
		return (1);
	return (0);
}

static int	check_julia_args(char **argv)
{
	char	*re;
	char	*im;

	re = argv[2];
	im = argv[3];
	while (*re)
	{
		if (!ft_isdigit(*re) && *re != '.' && *re != ',' && *re != '-')
			return (1);
		re++;
	}
	while (*im)
	{
		if (!ft_isdigit(*im) && *im != '.' && *im != ',' && *im != '-')
			return (1);
		im++;
	}
	return (0);
}

static void	usage_error(void)
{
	ft_putstr_fd("Dear, choose one of the following fractals: ", 2);
	ft_putstr_fd("mandelbrot, julia, tricorn.\n", 2);
	ft_putstr_fd("For julia set, give the value of", 2);
	ft_putstr_fd(" c = x + yi as following: julia x y.\n", 2);
	exit(1);
}

static void	check_valid_fractal(int argc, char **argv, t_complex c)
{
	if (!ft_strncmp(argv[1], "mandelbrot", max_size(sizeof(argv[1]), 11)))
	{
		if (argc != 2)
			usage_error();
		else
			initialize_window(MANDELBROT, c);
	}
	else if (!ft_strncmp(argv[1], "julia", max_size(sizeof(argv[1]), 6)))
	{
		if (argc != 4 || check_julia_args(argv))
			usage_error();
		else
			initialize_julia(argv, c);
	}
	else if (!ft_strncmp(argv[1], "tricorn", max_size(sizeof(argv[1]), 8)))
	{
		if (argc != 2)
			usage_error();
		else
			initialize_window(TRICORN, c);
	}
	else
		usage_error();
}
