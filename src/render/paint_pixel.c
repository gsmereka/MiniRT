/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:02:13 by gsmereka          #+#    #+#             */
/*   Updated: 2023/10/28 16:36:14 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	paint_pixel2(int x, int y, unsigned int color, t_data *data)
{
	char	*pointer;
	int		pixel;

	(void)color;
	// x = x + (data->win_width / 2); // Testar com resolução impar
	// y = y + (data->win_height / 2);
	// Verifica se o X ou Y ultrapassa a tela.
	printf("%d %d %d %d\n", x, y, data->win_width, data->win_height);
	if (x > data->win_width || y > data->win_height)
		return ;

	// Seleciona a posição do pixel a ser pintado.
	pixel = x * data->size_line + y * \
	(data->bits_per_pixel / 4);

	// Seleciona o ponteiro do pixel escolhido e altera sua cor.
	pointer = data->address_img + pixel;
	*(unsigned int *)pointer = color;
}


// void	write_pixel(t_canvas canvas, int x, int y, int color)
void	paint_pixel(int x, int y, unsigned int color, t_data *data)
{
	char	*pointer;
	int		pixel;

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
