/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:04:48 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/03 20:00:27 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_HIT	*closest_hit(t_SCENE *scene, t_ray *ray)
{
	t_HIT	*hit;
	t_HIT	*closest_hit;
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
