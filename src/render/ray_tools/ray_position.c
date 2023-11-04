/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:54:28 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/04 14:54:43 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/miniRT.h"

t_tuple	ray_position(t_ray *ray, double time)
{
	t_tuple	direction;
	t_tuple	position;

	direction = multiply_tuple(&ray->direction, time);
	position = sum_tuples(&direction, &ray->origin);
	return (position);
}