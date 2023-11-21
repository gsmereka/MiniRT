/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:04:34 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/21 16:43:40 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	render_scene(t_scene *scene, t_camera *camera, t_data *data)
{
	int				i;
	int				j;
	t_color			ray_color;
	unsigned int	pixel_color;
	static int		h;
	t_ray			*ray;

	i = 0;
	ray_color = (t_color){0};
	while (i < camera->height)
	{
		j = 0;
		while (j < camera->width)
		{
			calculate_ray_direction(scene->object_ray, camera, j, i);
			if (!h)
			{
				// printf("background %d %d %d\n", scene->background.r, scene->background.g, scene->background.b);
				// printf("ray color %d %d %d\n", ray_color.r, ray_color.g, ray_color.b);
			}
			ray_color = trace_ray(scene,
					scene->object_ray, scene->light_ray);
			if (!h)
			{
				printf("%d %d %d\n", ray_color.r, ray_color.g, ray_color.b);
			}
			h++;
			pixel_color = color_to_int(&ray_color);
			paint_pixel(j, i, pixel_color, data);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
			j++;
		}
		i++;
	}
}
