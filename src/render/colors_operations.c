/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:24:33 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/23 18:24:45 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_color	sum_colors(t_color *one, t_color *two)
{
	t_color	new_color;

	new_color.r = one->r + two->r;
	new_color.g = one->g + two->g;
	new_color.b = one->b + two->b;
	return (new_color);
}

t_color	subtract_colors(t_color *one, t_color *two)
{
	t_color	new_color;

	new_color.r = one->r - two->r;
	new_color.g = one->g - two->g;
	new_color.b = one->b - two->b;
	return (new_color);
}

t_color	multiply_color_scalar(t_color *color, double factor)
{
	t_color	new_color;

	new_color.r = color->r * factor;
	new_color.g = color->g * factor;
	new_color.b = color->b * factor;
	return (new_color);
}

t_color	multiply_color_x_color(t_color *one, t_color *two)
{
	t_color	new_color;

	new_color.r = one->r * two->r;
	new_color.g = one->g * two->g;
	new_color.b = one->b * two->b;
	return (new_color);
}

unsigned int	color_to_int(t_color *color)
{
	unsigned int	final_color;

	final_color = 0;
	final_color |= ((unsigned int)color->b);
	final_color |= ((unsigned int)color->g) << 8;
	final_color |= ((unsigned int)color->r) << 16;
	return (final_color);
}
