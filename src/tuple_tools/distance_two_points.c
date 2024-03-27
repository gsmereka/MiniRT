/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:46:18 by gsmereka          #+#    #+#             */
/*   Updated: 2023/08/13 17:46:35 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

double	distance_two_points(t_tuple *hit_point, t_tuple *ray_origin)
{
	double	distance;
	double	x_diff;
	double	y_diff;
	double	z_diff;

	x_diff = ray_origin->x - hit_point->x;
	y_diff = ray_origin->y - hit_point->y;
	z_diff = ray_origin->z - hit_point->z;
	distance = sqrt(pow(x_diff, 2) + pow(y_diff, 2) + pow(z_diff, 2));
	return (distance);
}
