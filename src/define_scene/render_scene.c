/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:04:34 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/01 09:28:28 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	render_scene(t_SCENE *scene, t_CAMERA *camera, t_data *data)
{
	int				i;
	int				j;
	t_ray			*aux_ray;
	t_tuple			color;
	unsigned int	final_color;
	double			*pixel_coord;

	i = 0;
	pixel_coord = ft_calloc(3, sizeof(double));
	while (i < camera->width)
	{
		j = 0;
		while (j < camera->height)
		{
			pixel_coord[0] = j + 0.5;
			pixel_coord[1] = camera->height - 0.5 - i;
			aux_ray = get_ray(camera, pixel_coord[0], pixel_coord[1]);
			color = trace_color(scene, aux_ray);
			free(aux_ray);
			final_color = 0;
			final_color |= ((int)color.x & 0xFF) << 16;  // Adiciona o valor de r ao componente vermelho.
			final_color |= ((int)color.y & 0xFF) << 8;   // Adiciona o valor de g ao componente verde.
			final_color |= ((int)color.z & 0xFF);        // Adiciona o valor de b ao componente azul
	// 		// paint_pixel(i, j, RED, data);
			paint_pixel(i, j, final_color, data);
			j++;
		}
		i++;
	}
	free(pixel_coord);
}
