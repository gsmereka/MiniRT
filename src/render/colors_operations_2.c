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

t_color	sum_light_to_color(t_color *color, double factor)
{
	t_color	new_color;

	new_color.r = color->r + factor;
	new_color.g = color->g + factor;
	new_color.b = color->b + factor;
	return (new_color);
}

t_color	normalize_color(t_color *color)
{
	t_color	new_color;

	new_color.r = color->r / 255.0;
	new_color.g = color->g / 255.0;
	new_color.b = color->b / 255.0;
	return (new_color);
}
