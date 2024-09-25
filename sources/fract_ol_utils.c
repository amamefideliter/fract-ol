/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:56:21 by daria             #+#    #+#             */
/*   Updated: 2024/09/25 16:19:30 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

double	ft_atof(char *number)
{
	char	in[12];
	char	fl[12];
	double	res;
	int		idx;
	int		minus;

	idx = 0;
	minus = 0;
	if (!number)
		return (0);
	if (*number == '-' && *(number + 1) == '0')
		minus = 1;
	while (*number && *number != '.' && *number != ',')
		in[idx++] = *number++;
	in[idx] = '\0';
	idx = 0;
	while (*number)
		fl[idx++] = *(++number);
	fl[idx] = '\0';
	res = ft_atoi(in) + ft_atoi(fl) / pow(10, ft_strlen(fl));
	if (minus)
		res *= -1;
	return (res);
}

int	get_color(int iter)
{
	if (iter == -1)
		return (BLACK);
	return ((int)(((600 * iter / ITERATIONS) + 300) % 256));
}

void	translate_plain(t_data *data, double *i, double *j)
{
	double	x;
	double	y;

	x = *j;
	y = *i;
	x = (x / WIDTH) * (data->plain.right_x - data->plain.left_x)
		+ data->plain.left_x;
	y = (y / HEIGHT) * (data->plain.upper_y - data->plain.lower_y)
		+ data->plain.lower_y;
	*i = x;
	*j = y;
}

size_t	max_size(size_t a, size_t b)
{
	if (a < b)
		return (b);
	return (b);
}
