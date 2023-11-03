/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:07:15 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/03 16:09:07 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	calculate_direction(t_ray *new_ray,
	t_CAMERA *camera, double j, double i)
{
	t_tuple	temp;

	new_ray->direction.x = camera->front.x * camera->focal_length;
	new_ray->direction.y = camera->front.y * camera->focal_length;
	new_ray->direction.z = camera->front.z * camera->focal_length;
	temp.x = camera->right.x * (j / (double)camera->width - 0.50);
	temp.y = camera->right.y * (j / (double)camera->width - 0.50);
	temp.z = camera->right.z * (j / (double)camera->width - 0.50);
	new_ray->direction.x += temp.x;
	new_ray->direction.y += temp.y;
	new_ray->direction.z += temp.z;
	temp.x = camera->up.x * ((double)camera->height
			/ (double)camera->width) * (i / (double)camera->height - 0.50);
	temp.y = camera->up.y * ((double)camera->height
			/ (double)camera->width) * (i / (double)camera->height - 0.50);
	temp.z = camera->up.z * ((double)camera->height
			/ (double)camera->width) * (i / (double)camera->height - 0.50);
	new_ray->direction.x += temp.x;
	new_ray->direction.y += temp.y;
	new_ray->direction.z += temp.z;
}

void	set_ray_origin(t_ray *new_ray, t_tuple *center)
{
	pass_tuple_values(&new_ray->origin, center);
}

t_ray	*get_ray(t_CAMERA *camera, double j, double i)
{
	t_ray	*new_ray;

	if (!camera)
		return (NULL);
	new_ray = ft_calloc(1, sizeof(t_ray));
	if (!new_ray)
		return (NULL);
	calculate_direction(new_ray, camera, j, i);
	set_ray_origin(new_ray, &camera->center);
	return (new_ray);
}
