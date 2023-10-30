/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:08:21 by gsmereka          #+#    #+#             */
/*   Updated: 2023/10/29 23:08:41 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_tuple	trace_color(t_SCENE *scene, t_ray *ray)
{
	t_HIT			closest_hit;
	t_ray			light_ray;
	t_HIT			light_hit;
	t_tuple			result;
	t_tuple			light_position;
	t_tuple			tuple_subtraction;
	double			intensity;
	int				i;

	closest_hit = CLOSEST_HIT(scene, ray);
	if (closest_hit.valid)
	{
		intensity = scene->ambient_light;
		i = 0;
		while (i < scene->luzes_a_definir) // numero a definir
		{
			light_position = scene->lights[i].position;
			tuple_subtraction = subtract_tuples(&closest_hit.position, &scene->lights[i].position);
			light_ray = init_ray(&light_position, &tuple_subtraction);
			light_hit = CLOSEST_HIT(scene, &light_ray);
			if (light_hit.valid && &light_hit.object == &closest_hit.object)
				intensity += LIGHT_at(&scene->lights[i], &closest_hit);
			if (intensity < 1)
				intensity = 1;
			result.x = closest_hit.object->color.r * intensity;
			result.y = closest_hit.object->color.g * intensity;
			result.z = closest_hit.object->color.b * intensity;
			i++;
		}
		return (result);
	}
	return (scene->background);
}
