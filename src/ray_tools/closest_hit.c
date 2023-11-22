/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:04:48 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/22 14:28:22 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_hit	*closest_hit(t_scene *scene, t_ray *ray)
{
	t_hit	*hit;
	t_hit	*closest_hit;
	int		i;

	i = 0;
	closest_hit = NULL;
	while (scene->objects[i])
	{
		hit = intersect_sphere(scene->objects[i], ray);
		if (hit && (!closest_hit || hit->distance < closest_hit->distance))
		{
			free(closest_hit);
			closest_hit = hit;
		}
		else if (hit)
			free(hit);
		i++;
	}
	return (closest_hit);
}
