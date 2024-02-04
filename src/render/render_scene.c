/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:04:34 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/22 19:55:12 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	render_scene(t_data *data, int i, int j)
{
	t_color			ray_color;
	unsigned int	pixel_color;

	ray_color = (t_color){0};
	data->scene->object_ray->direction.x = 0;
	data->scene->object_ray->direction.y = 0;
	data->scene->object_ray->direction.z = 0;
	data->scene->object_ray->direction.w = 0;
	calculate_ray_direction(data->scene->object_ray, data->camera, j, i);
	ray_color = trace_ray(data->scene,
			data->scene->object_ray, data->scene->light_ray);
	pixel_color = color_to_int(&ray_color);
	paint_pixel(j, i, pixel_color, data);
}
