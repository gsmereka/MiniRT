/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:04:48 by gsmereka          #+#    #+#             */
/*   Updated: 2023/10/31 23:10:02 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_HIT	closest_hit(t_SCENE *scene, t_ray *ray)
{
	t_HIT	hit;
	t_HIT	closest_hit;
	int		limit;
	int		i;
	static	int g;

	i = 0;
	closest_hit = (t_HIT){0};
	limit = scene->objetos_a_definir;
	while (i < limit)
	{
		// if (!g)
		// 	printf("%f\n", ray->direction.x);
		// g++;
		hit = intersect_sphere(scene->objects[i], ray);
		if (!hit.valid || !closest_hit.valid || hit.distance < closest_hit.distance)
			closest_hit = hit;
		i++;
	}
	return (closest_hit);
}
