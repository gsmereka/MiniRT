/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:54:28 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/22 14:28:22 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_tuple	ray_position(t_ray *ray, double time)
{
	t_tuple	position;

	ray->direction = multiply_tuple(&ray->direction, time);
	position = sum_tuples(&ray->direction, &ray->origin);
	return (position);
}