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
	t_tuple	front;
	t_tuple	up;
	t_tuple	right;

	front = multiply_tuple(&camera->front, camera->focal_length);
	right = multiply_tuple(&camera->right, (j / (double)camera->width - 0.5));
	up = multiply_tuple(&camera->up, (i / (double)camera->height - 0.5));
	ray->direction = sum_tuples(&ray->direction, &front);
	ray->direction = sum_tuples(&ray->direction, &right);
	ray->direction = sum_tuples(&ray->direction, &up);
}

void	calculate_ray_direction(t_ray *ray,
	t_camera *camera, double j, double i)
{
	double	pixel_center_coord[2];

	if (!camera)
		return ;
	pixel_center_coord[0] = camera->width - j - 0.5;
	pixel_center_coord[1] = camera->height - i - 0.5;
	calculate_direction(ray, camera,
		pixel_center_coord[0], pixel_center_coord[1]);
	normalize_ray(ray, &camera->center, &ray->direction);
}
