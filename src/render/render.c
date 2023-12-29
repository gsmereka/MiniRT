/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:20:54 by gde-mora          #+#    #+#             */
/*   Updated: 2023/11/22 19:55:57 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static void	aux_render(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->camera->height)
	{
		j = 0;
		while (j < data->camera->width)
		{
			render_scene(data, i, j);
			j++;
		}
		i++;
	}
}

int	handle_render(void *data_ptr)
{
	t_data		*data;
	static int	run;

	data = (t_data *)data_ptr;
	if (!run)
	{
		aux_render(data);
		run = 1;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

// versão que cada quadro gerado equivale a um raio traçado (mais lento, porem é possivel fechar o programa enquanto esta renderizando)
// int	handle_render(void *data_ptr)
// {
// 	t_data		*data;
// 	static int	i;
// 	static int	j;

// 	data = (t_data *)data_ptr;
// 	if (i < data->camera->height)
// 	{
// 		if (j < data->camera->width)
// 		{
// 			render_scene(data, i, j);
// 			mlx_put_image_to_window(data->mlx_ptr,
// 				data->win_ptr, data->img, 0, 0);
// 			j++;
// 			return (0);
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
// 	return (0);
// }

void	render(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		exit_error(INTERFACE_ERROR, 2, data);
	if (!data->win_width && !data->win_height) // escolher um lugar melhor pra isso
	{
		data->win_width = 500;
		data->win_height = 500;
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
		data->win_width, data->win_height, "miniRT");
	data->img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	data->address_img = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->size_line, &data->endian);
	mlx_expose_hook(data->win_ptr, &handle_render, data);
	mlx_key_hook(data->win_ptr, &handle_esc, data);
	mlx_hook(data->win_ptr, 17, 0, &handle_x, data);
	// mlx_loop_hook(data->mlx_ptr, &handle_render, (void *)data); // dessa forma dá pra fechar antes de renderizar tudo
	mlx_loop(data->mlx_ptr);
}
