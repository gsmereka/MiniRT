/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:08:21 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/03 19:15:11 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/miniRT.h"

double	trace_ilumination(t_SCENE *scene, t_hit *object_hit, t_ray *light_ray);

t_tuple	trace_ray(t_SCENE *scene, t_ray *object_ray, t_ray *light_ray)
{
	t_hit			*object_hit;
	t_tuple			ray_color;
	double			light_intensity;

	object_hit = closest_hit(scene, object_ray);
	if (object_hit)
	{
		light_intensity = trace_ilumination(scene, object_hit, light_ray);
		ray_color.x = (double)object_hit->object->color.r * light_intensity;
		ray_color.y = (double)object_hit->object->color.g * light_intensity;
		ray_color.z = (double)object_hit->object->color.b * light_intensity;
	}
	else
		ray_color = scene->background;
	free(object_hit);
	return (ray_color);
}

double	trace_ilumination(t_SCENE *scene, t_hit *object_hit, t_ray *light_ray)
{
	int		i;
	double	light_intensity;
	t_tuple	light_ray_direction;
	t_hit	*light_hit;

	light_intensity = scene->ambient_light;
	i = 0;
	while (scene->lights[i])
	{
		light_ray_direction = subtract_tuples(&object_hit->position,
				&scene->lights[i]->position);
		normalize_ray(light_ray, &scene->lights[i]->position, &light_ray_direction);
		light_hit = closest_hit(scene, light_ray);
		if (light_hit && light_hit->object->id == object_hit->object->id)
			light_intensity += LIGHT_at(scene->lights[i], object_hit);
		i++;
		free(light_hit);
	}
	if (light_intensity < 0)
		light_intensity *= -1;
	if (light_intensity >= 1)
		light_intensity = 1;
	return (light_intensity);
}
