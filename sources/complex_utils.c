/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:36:44 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/25 16:19:27 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

t_complex	conjugate(t_complex z)
{
	z.imaginary *= -1;
	return (z);
}

t_complex	create_complex(double x, double y)
{
	t_complex	z;

	z.real = x;
	z.imaginary = y;
	return (z);
}

t_complex	iterator(t_complex c, t_complex z)
{
	t_complex	z_new;

	z_new = complex_sum(complex_square(z), c);
	return (z_new);
}

t_complex	complex_square(t_complex z)
{
	t_complex	square;

	square.real = (z.real * z.real) + (z.imaginary * z.imaginary * (-1));
	square.imaginary = z.real * z.imaginary * 2;
	return (square);
}

t_complex	complex_sum(t_complex x, t_complex y)
{
	t_complex	sum;

	sum.real = x.real + y.real;
	sum.imaginary = x.imaginary + y.imaginary;
	return (sum);
}
