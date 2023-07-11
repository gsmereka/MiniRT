/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:02:13 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/10 22:02:28 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	paint_pixel(int x, int y, unsigned int color, t_data *data)
{
	char	*pointer;
	int		max_size;
	int		pixel;

	// Seleciona a posição do pixel a ser pintado.
	pixel = x * data->size_line + y * \
	(data->bits_per_pixel / 8);

	// Seleciona a ultima posição possivel.
	max_size = data->win_width * data->size_line + data->win_height * \
	(data->bits_per_pixel / 8);

	// Verifica se o pixel escolhido não ultrapassa o limite.
	if (pixel > max_size)
		return ;
	
	// Seleciona o ponteiro do pixel escolhido e altera sua cor.
	pointer = data->address_img + pixel;
	*(unsigned int *)pointer = color;
}
