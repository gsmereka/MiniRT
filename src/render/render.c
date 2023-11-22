/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:20:54 by gde-mora          #+#    #+#             */
/*   Updated: 2023/11/22 16:21:14 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	handle_render(void *data_ptr) //Enqunto fazemos os testes // Função que verifica se o tester ja enviou o sinal SIGTERM
{
	t_data	*data;

	data = (t_data *)data_ptr;
	static int	i;
	static int	j;

	if (i < data->camera->height)
	{
		if (j < data->camera->width)
		{
			render_scene(data, i, j);
			j++;
			return (0);
		}
		j = 0;
		i++;
	}
	return (0);
}

int	debug(void *data_ptr) //Enqunto fazemos os testes // Função que verifica se o tester ja enviou o sinal SIGTERM
{
	t_data	*data;

	data = (t_data *)data_ptr;
	if (data->debug_exit)
		exit_successful(data);
	return (0);
}

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

	// melhor posição pra pintar a imagem
	data->address_img = mlx_get_data_addr(data->img, &data->bits_per_pixel,
		&data->size_line, &data->endian);
	// mlx_expose_hook(data->win_ptr, &handle_render, data);
	
	mlx_key_hook(data->win_ptr, &handle_esc, data);
	mlx_hook(data->win_ptr, 17, 0, &handle_x, data);
	mlx_loop_hook(data->mlx_ptr, &handle_render, (void *)data);
	// mlx_loop_hook(data->mlx_ptr, &debug, (void *)data); // Função que verifica se o tester ja enviou o sinal SIGTERM
	mlx_loop(data->mlx_ptr);
}
