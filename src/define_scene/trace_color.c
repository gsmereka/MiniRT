/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:08:21 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/03 19:01:43 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_tuple	trace_color(t_SCENE *scene, t_ray *object_ray, t_ray *light_ray)
{
	t_HIT			*closesthit;
	t_HIT			*light_hit;
	t_tuple			result;
	t_tuple			light_position;
	t_tuple			tuple_subtraction;
	double			intensity;
	int				i;

	closesthit = closest_hit(scene, object_ray);
	if (closesthit)
	{
		intensity = scene->ambient_light;
		i = 0;
		while (scene->lights[i])
		{
			pass_tuple_values(&light_position, &scene->lights[i]->position);
			tuple_subtraction = subtract_tuples(&closesthit->position, &scene->lights[i]->position);
			init_ray(light_ray, &light_position, &tuple_subtraction);
			light_hit = closest_hit(scene, light_ray);
			if (light_hit && light_hit->object->id == closesthit->object->id)
				intensity += LIGHT_at(scene->lights[i], closesthit);
			i++;
			free(light_hit);
		}
		if (intensity >= 1)
			intensity = 1;
		if (intensity < 0)
			intensity *= -1;
		result.x = (double)closesthit->object->color.r * intensity;
		result.y = (double)closesthit->object->color.g * intensity;
		result.z = (double)closesthit->object->color.b * intensity;
	}
	else
		result = scene->background;
	free(closesthit);
	return (result);
}
