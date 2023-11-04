/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:46:18 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/04 15:33:36 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_color	*sum_colors(t_color *one, t_color *two)
{
	t_color	*new_color;

	new_color = ft_calloc(1, sizeof(t_color));
	new_color->r = one->r + two->r;
	new_color->g = one->g + two->g;
	new_color->b = one->b + two->b;
	return (new_color);
}

t_color	*subtract_colors(t_color *one, t_color *two)
{
	t_color	*new_color;

	new_color = ft_calloc(1, sizeof(t_color));
	new_color->r = one->r - two->r;
	new_color->g = one->g - two->g;
	new_color->b = one->b - two->b;
	return (new_color);
}

t_color	*multiply_color_scalar(t_color *color, double factor)
{
	t_color	*new_color;

	new_color = ft_calloc(1, sizeof(t_color));
	new_color->r = color->r * factor;
	new_color->g = color->g * factor;
	new_color->b = color->b * factor;
	return (new_color);
}

t_color	*multiply_color_x_color(t_color *one, t_color *two)
{
	t_color	*new_color;

	new_color = ft_calloc(1, sizeof(t_color));
	new_color->r = one->r * two->r;
	new_color->g = one->g * two->g;
	new_color->b = one->b * two->b;
	return (new_color);
}

unsigned int	color_to_int(t_color *color)
{
	unsigned int	final_color;

	final_color = 0;
	final_color |= ((unsigned int)color->r & 0xFF) << 16;  // Adiciona o valor de r ao componente vermelho.
	final_color |= ((unsigned int)color->g & 0xFF) << 8;   // Adiciona o valor de g ao componente verde.
	final_color |= ((unsigned int)color->b & 0xFF);        // Adiciona o valor de b ao componente azul
	return (final_color);
}
