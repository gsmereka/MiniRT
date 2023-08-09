/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:52:31 by gde-mora          #+#    #+#             */
/*   Updated: 2023/08/09 21:24:01 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_ray	create_ray(t_tuple *origin, t_tuple *direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);	
}

t_tuple	*position(t_ray *ray, double time)
{
	t_tuple	*temp_mult;
	t_tuple	*sum;

	temp_mult = multiply_tuple(ray->direction, time);
	sum = sum_tuples(temp_mult, ray->origin);
	free(temp_mult);
	return (sum);
}
