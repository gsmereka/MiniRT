/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:02:13 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/04 15:25:58 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	paint_pixel(int x, int y, unsigned int color, t_data *data)
{
	char	*pointer;
	int		pixel;

	if (x > data->win_width || x < 0)
		return ;
	if (y > data->win_height || x < 0)
		return ;
	pointer = data->address_img;
	pointer += (y * data->size_line) + (x * (data->bits_per_pixel / 8));
	pixel = data->bits_per_pixel - 8;
	while (pixel >= 0)
	{
		if (data->endian == 0)
			*pointer++ = (color >> (data->bits_per_pixel - 8 - pixel)) & 0xFF;
		else
			*pointer++ = (color >> pixel) & 0xFF;
		pixel -= 8;
	}
}
