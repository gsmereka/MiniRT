/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:04:34 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/04 11:34:12 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

unsigned int	tuple_to_color(t_tuple *color)
{
	unsigned int	final_color;

	final_color = 0;
	final_color |= ((unsigned int)color->x & 0xFF) << 16;  // Adiciona o valor de r ao componente vermelho.
	final_color |= ((unsigned int)color->y & 0xFF) << 8;   // Adiciona o valor de g ao componente verde.
	final_color |= ((unsigned int)color->z & 0xFF);        // Adiciona o valor de b ao componente azul
	return (final_color);
}

void	render_scene(t_SCENE *scene, t_CAMERA *camera, t_data *data)
{
	int				i;
	int				j;
	t_tuple			ray_color;
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
			pixel_color = tuple_to_color(&ray_color);
			paint_pixel(j, i, pixel_color, data);
			j++;
		}
		i++;
	}
}
