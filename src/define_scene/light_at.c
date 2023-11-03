/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:18:50 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/03 10:07:55 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

double	tuple_magnitude_2(t_tuple *tuple) // Qual é a diferença entre W e C ?
{
	double	x;
	double	y;
	double	z;
	double	w;
	double	magnitude;

	x = pow(tuple->x, 2);
	y = pow(tuple->y, 2);
	z = pow(tuple->z, 2);
	// w = pow(tuple->w, 2);
	magnitude = sqrt(x + y + z);
	return (magnitude);
}

double LIGHT_at(t_POINTLIGHT *light, t_HIT *hit)
{
	t_tuple	direction;
	double	distance;
	double	cos_theta;
	double	result;
	static int	g;

	hit->position.w = 1;
	light->position.w = 1;
	direction = subtract_tuples(&light->position, &hit->position);
	direction.w = 1;
	distance = tuple_magnitude_2(&direction);
	normalize_tuple(&direction);
	cos_theta = dot_product(&direction, &hit->normal);
	result = light->intensity * (cos_theta / (distance * distance));
	return (result);
}
