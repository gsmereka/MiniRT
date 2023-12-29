/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ray_direction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:21:55 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/22 14:28:22 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	calculate_direction(t_ray *ray,
	t_camera *camera, double j, double i)
{
	t_tuple	temp;
	ray->direction.x = camera->front.x * camera->focal_length;
	ray->direction.y = camera->front.y * camera->focal_length;
	ray->direction.z = camera->front.z * camera->focal_length;
	temp.x = camera->right.x * (j / (double)camera->width - 0.50);
	temp.y = camera->right.y * (j / (double)camera->width - 0.50);
	temp.z = camera->right.z * (j / (double)camera->width - 0.50);
	ray->direction.x += temp.x;
	ray->direction.y += temp.y;
	ray->direction.z += temp.z;
	temp.x = camera->up.x * ((double)camera->height
			/ (double)camera->width) * (i / (double)camera->height - 0.50);
	temp.y = camera->up.y * ((double)camera->height
			/ (double)camera->width) * (i / (double)camera->height - 0.50);
	temp.z = camera->up.z * ((double)camera->height
			/ (double)camera->width) * (i / (double)camera->height - 0.50);
	ray->direction.x += temp.x;
	ray->direction.y += temp.y;
	ray->direction.z += temp.z;
}
void	calculate_ray_direction(t_ray *ray,
	t_camera *camera, double j, double i)
{
	double	pixel_center_coord[2];
	if (!camera)
		return ;
	pixel_center_coord[0] = j + 0.5;
	pixel_center_coord[1] = camera->height - 0.5 - i;
	calculate_direction(ray, camera,
		pixel_center_coord[0], pixel_center_coord[1]);
	normalize_ray(ray, &camera->center, &ray->direction);
}