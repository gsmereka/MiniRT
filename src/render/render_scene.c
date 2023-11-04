/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:04:34 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/04 15:41:19 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	render_scene(t_scene *scene, t_camera *camera, t_data *data)
{
	int				i;
	int				j;
	t_color			ray_color;
	unsigned int	pixel_color;
	t_ray			*ray;

	i = 0;
	while (i < camera->height)
	{
		j = 0;
		while (j < camera->width)
		{
			calculate_ray_direction(scene->object_ray, data->camera, j, i);
			ray_color = trace_ray(data->scene,
					scene->object_ray, scene->light_ray);
			pixel_color = color_to_int(&ray_color);
			paint_pixel(j, i, pixel_color, data);
			j++;
		}
		i++;
	}
}
