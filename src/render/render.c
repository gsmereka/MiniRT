/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:20:54 by gde-mora          #+#    #+#             */
/*   Updated: 2023/08/08 18:35:04 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static int	handle_render(t_data *data)
{
	int		i;
	int		pos;

	i = 0;
	//int pos = (y * size_line + x * (bits_per_pixel / 8));
	//deve ter verificação para n usar pontos q passem da tela
	data->address_img = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
		&data->size_line, &data->endian);
	pos = 50;
	while (i < 16)
	{
		paint_pixel(pos + i, pos, RED, data);
		paint_pixel(pos, pos + i, RED, data);
		paint_pixel(pos + i, pos + 15, BLUE, data);
		paint_pixel(pos + 15, pos + i, BLUE, data);
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
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
	mlx_expose_hook(data->win_ptr, &handle_render, data);
	mlx_key_hook(data->win_ptr, &handle_esc, data);
	mlx_hook(data->win_ptr, 17, 0, &handle_x, data);
	mlx_loop_hook(data->mlx_ptr, &debug, (void *)data); // Função que verifica se o tester ja enviou o sinal SIGTERM
	mlx_loop(data->mlx_ptr);
}
