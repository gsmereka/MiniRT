/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:04:34 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/03 15:55:01 by gsmereka         ###   ########.fr       */
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

t_tuple	get_ray_color(int j, int i, t_data *data)
{
	t_ray			*aux_ray;
	t_tuple			color;
	double			pixel_coord[2];

	pixel_coord[0] = j + 0.5;
	pixel_coord[1] = data->camera->height - 0.5 - i;
	aux_ray = get_ray(data->camera, pixel_coord[0], pixel_coord[1]);
	color = trace_color(data->scene, aux_ray);
	free(aux_ray);
	return (color);
}

void	render_scene(t_SCENE *scene, t_CAMERA *camera, t_data *data)
{
	int				i;
	int				j;
	t_tuple			color;
	unsigned int	final_color;

	i = 0;
	while (i < camera->height)
	{
		j = 0;
		while (j < camera->width)
		{
			color = get_ray_color(j, i, data);
			final_color = tuple_to_color(&color);
			paint_pixel(j, i, final_color, data);
			j++;
		}
		i++;
	}
}
