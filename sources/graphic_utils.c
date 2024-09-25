/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:10:32 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/25 16:19:42 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	handle_keypress(int keysum, t_data *data)
{
	if (keysum == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit (0);
}

int	handle_scaling(int keysum, int x, int y, t_data *data)
{
	if (keysum == 4)
		zoom_in(data, x, y);
	else if (keysum == 5)
		zoom_out(data, x, y);
	return (0);
}

int	handle_mouse_click(int mouse_code, t_data *data)
{
	if (mouse_code == 1)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit (0);
}
