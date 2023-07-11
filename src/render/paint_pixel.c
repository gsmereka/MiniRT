/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:02:13 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/11 15:11:49 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	paint_pixel(int x, int y, unsigned int color, t_data *data) //recebe as posições como int
{
	char	*pointer;
	int		pixel;

	y = data->win_height - y;
	//x = data->win_width - x;

	// Verifica se o X ou Y ultrapassa a tela.
	if (x > data->win_width || y > data->win_height || x < 0 || y < 0)
		return ;

	// Seleciona a posição do pixel a ser pintado.
	pixel = x * data->size_line + y * \
	(data->bits_per_pixel / 8);

	// Seleciona o ponteiro do pixel escolhido e altera sua cor.
	pointer = data->address_img + pixel;
	*(unsigned int *)pointer = color;
}
