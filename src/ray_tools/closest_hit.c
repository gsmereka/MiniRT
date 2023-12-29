/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:04:48 by gsmereka          #+#    #+#             */
/*   Updated: 2023/12/04 21:28:30 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_hit	closest_hit(t_scene *scene, t_ray *ray)
{
	t_hit	hit;
	t_hit	closest_hit;
	int		i;

	i = 0;
	while (scene->objects[i])
	{
		if (scene->objects[i]->type == SPHERE)
			hit = intersect_sphere(scene->objects[i], ray);
		else if (scene->objects[i]->type == PLANE)
			hit = intersect_plane(scene->objects[i], ray);
		else if (scene->objects[i]->type == CYLINDER)
			hit = intersect_cylinder(scene->objects[i], ray);
		if (hit.hit && (!closest_hit.hit || hit.distance < closest_hit.distance))
		{
			closest_hit = hit;
		}
		i++;
	}
	return (closest_hit);
}
