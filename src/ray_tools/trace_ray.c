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

#include "../../headers/miniRT.h"

// static t_color	trace_color_ilumination(t_scene *scene,
// t_hit *object_hit, t_ray *light_ray);
// t_color	trace_ray(t_scene *scene, t_ray *object_ray, t_ray *light_ray)
// {
// 	t_hit			*object_hit;
// 	t_color			ray_color;
// 	t_color			light_intensity;

// 	object_hit = closest_hit(scene, object_ray);
// 	if (object_hit)
// 	{
// 		light_intensity = trace_color_ilumination(scene, object_hit, light_ray);
// 		ray_color = multiply_color_x_color(&object_hit->object->color,
// 				&light_intensity);
// 		ray_color.r = fmin(255, fmax(0.0, ray_color.r));
// 		ray_color.g = fmin(255, fmax(0.0, ray_color.g));
// 		ray_color.b = fmin(255, fmax(0.0, ray_color.b));
// 	}
// 	else
// 		ray_color = (t_color){0};
// 	free(object_hit);
// 	return (ray_color);
// }

// static t_color
// trace_color_ilumination(t_scene *scene, t_hit *object_hit, t_ray *light_ray)
// {
// 	int		i;
// 	double	light_intensity;
// 	t_color	color_ilumination;
// 	t_tuple	light_ray_direction;
// 	t_hit	*light_hit;

// 	light_intensity = 0;
// 	i = 0;
// 	while (scene->lights[i])
// 	{
// 		light_ray_direction = subtract_tuples(&object_hit->position,
// 				&scene->lights[i]->coordinate);
// 		normalize_ray(light_ray,
// 			&scene->lights[i]->coordinate, &light_ray_direction);
// 		light_hit = closest_hit(scene, light_ray);
// 		if (light_hit && light_hit->object == object_hit->object)
// 			light_intensity += light_at(scene->lights[i], object_hit);
// 		i++;
// 		free(light_hit);
// 	}
// 	color_ilumination
// = sum_light_to_color(&scene->ambient_color, light_intensity);
// 	color_ilumination.r = fmin(color_ilumination.r, 1.0);
// 	color_ilumination.g = fmin(color_ilumination.g, 1.0);
// 	color_ilumination.b = fmin(color_ilumination.b, 1.0);
// 	return (color_ilumination);
// }

static double	trace_ilumination(t_scene *scene,
					t_hit *object_hit, t_ray *light_ray);

t_color	trace_ray(t_scene *scene, t_ray *object_ray, t_ray *light_ray)
{
	t_hit	*object_hit;
	t_color	ray_color;
	double	light_intensity;
	t_color	ambient_color;

	object_hit = closest_hit(scene, object_ray);
	if (object_hit)
	{
		light_intensity = trace_ilumination(scene, object_hit, light_ray);
		ambient_color = sum_light_to_color(&scene->ambient_color,
				light_intensity);
		ray_color = multiply_color_x_color(&object_hit->object->color,
				&ambient_color);
		ray_color.r = fmin(255, fmax(0.0, ray_color.r));
		ray_color.g = fmin(255, fmax(0.0, ray_color.g));
		ray_color.b = fmin(255, fmax(0.0, ray_color.b));
	}
	else
		ray_color = (t_color){0};
	free(object_hit);
	return (ray_color);
}


static double	trace_ilumination(t_scene *scene,
	t_hit *object_hit, t_ray *light_ray)
{
	int		i;
	double	light_intensity;
	t_tuple	light_ray_direction;
	t_hit	*light_hit;

	light_intensity = 0;
	i = 0;

	while (scene->lights[i])
	{
		light_ray_direction = subtract_tuples(&object_hit->position,
				&scene->lights[i]->coordinate);
		normalize_ray(light_ray,
			&scene->lights[i]->coordinate, &light_ray_direction);
		light_hit = closest_hit(scene, light_ray);
		if (light_hit && light_hit->object == object_hit->object)
		{
			light_intensity += light_at(scene->lights[i], object_hit);
		}
		free(light_hit);
		i++;
	}
	return (light_intensity);
}
