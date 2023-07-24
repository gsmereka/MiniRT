/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:46:18 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/10 21:28:03 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_color	*sum_colors(t_color *one, t_color *two) // É melhor que essas operações criem uma tupla nova ou substituam uma das tuplas anteriores ?
{
	t_color	*new_color;

	new_color = ft_calloc(1, sizeof(t_color));
	new_color->r = one->r + two->r;
	new_color->g = one->g + two->g;
	new_color->b = one->b + two->b;
	return (new_color);
}

t_color	*subtract_colors(t_color *one, t_color *two) // É melhor que essas operações criem uma tupla nova ou substituam uma das tuplas anteriores ?
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

t_color	*multiply_color_x_color(t_color *one, t_color *two) // isso é Hadamard product (or Schur product)
{
	t_color	*new_color;

	new_color = ft_calloc(1, sizeof(t_color));
	new_color->r = one->r * two->r;
	new_color->g = one->g * two->g;
	new_color->b = one->b * two->b;
	return (new_color);
}
