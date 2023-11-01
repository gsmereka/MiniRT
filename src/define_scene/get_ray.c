/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:07:15 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/01 17:35:42 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_ray	*get_ray(t_CAMERA *camera, double j, double i)
{
	static int	g;
	t_ray	*new_ray;
	t_tuple	temp;
	t_tuple	aux;

    if (!camera)
        return (NULL);
	new_ray = ft_calloc(1, sizeof(t_ray));
    if (!new_ray)
        return (NULL);
	// direction = self.front * self.focal_length
    new_ray->direction.x = camera->front.x * camera->focal_length;
    new_ray->direction.y = camera->front.y * camera->focal_length;
    new_ray->direction.z = camera->front.z * camera->focal_length;

    // temp = self.right * (j / self.width - 0.5)
    temp.x = camera->right.x * (j / (double)camera->width - 0.50);
    temp.y = camera->right.y * (j / (double)camera->width - 0.50);
    temp.z = camera->right.z * (j / (double)camera->width - 0.50);

    // direction += temp
    new_ray->direction.x += temp.x;
    new_ray->direction.y += temp.y;
    new_ray->direction.z += temp.z;

    // temp = self.up * (self.height / self.width) * (i / self.height - 0.5)
    temp.x = camera->up.x * ((double)camera->height / (double)camera->width) * (i / (double)camera->height - 0.50);
    temp.y = camera->up.y * ((double)camera->height / (double)camera->width) * (i / (double)camera->height - 0.50);
    temp.z = camera->up.z * ((double)camera->height / (double)camera->width) * (i / (double)camera->height - 0.50);

    // direction += temp
    new_ray->direction.x += temp.x;
    new_ray->direction.y += temp.y;
    new_ray->direction.z += temp.z;

    pass_tuple_values(&new_ray->origin, &camera->center);
	if (!g)
	{
		// print_tuple(&camera->center);
		// printf("camera %f %f %f\n", camera->up.x, camera->up.y, camera->up.z);
		// printf("camera %f %f %f\n", camera->right.x, camera->right.y, camera->right.z);
	}
	g++;
	return (new_ray);
}
