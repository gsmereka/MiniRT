/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:04:34 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/03 19:17:22 by gsmereka         ###   ########.fr       */
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
	t_tuple			color_tuple;
	unsigned int	final_color;
	t_ray			*ray;

	i = 0;
	while (i < camera->height)
	{
		j = 0;
		while (j < camera->width)
		{
			prepare_ray(scene->object_ray, data->camera, j, i);
			color_tuple = trace_color(data->scene,
					scene->object_ray, scene->light_ray);
			final_color = tuple_to_color(&color_tuple);
			paint_pixel(j, i, final_color, data);
			j++;
		}
		i++;
	}
}
