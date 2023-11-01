/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:08:21 by gsmereka          #+#    #+#             */
/*   Updated: 2023/10/31 23:20:37 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_tuple	trace_color(t_SCENE *scene, t_ray *ray)
{
	t_HIT			closesthit;
	t_ray			light_ray;
	t_HIT			light_hit;
	t_tuple			result;
	t_tuple			light_position;
	t_tuple			tuple_subtraction;
	double			intensity;
	int				i;

	closesthit = closest_hit(scene, ray);
	if (closesthit.valid)
	{
		intensity = scene->ambient_light;
		i = 0;
		while (i < scene->luzes_a_definir) // numero a definir
		{
			light_position = scene->lights[i].position;
			tuple_subtraction = subtract_tuples(&closesthit.position, &scene->lights[i].position);
			light_ray = init_ray(&light_position, &tuple_subtraction);
			light_hit = closest_hit(scene, &light_ray);
			if (light_hit.valid && &light_hit.object == &closesthit.object)
				intensity += LIGHT_at(&scene->lights[i], &closesthit);
			if (intensity < 1)
				intensity = 1;
			result.x = closesthit.object->color.r * intensity;
			result.y = closesthit.object->color.g * intensity;
			result.z = closesthit.object->color.b * intensity;
			i++;
		}
		return (result);
	}
	return (scene->background);
}
