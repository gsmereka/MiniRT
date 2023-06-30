/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:20:54 by gde-mora          #+#    #+#             */
/*   Updated: 2023/06/30 03:51:17 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

static int	handle_esc(int key, t_data *data)
{
	if (key == KEY_ESCAPE)
		exit_successful(data);
	return (0);
}

static int	handle_x(t_data *data)
{
	exit_successful(data);
	return (0);
}

static int	handle_render(t_data *data)
{
	char	*dst;

	data->address_img = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
		&data->size_line, &data->endian);
	dst = data->address_img + (300 * data->size_line + 300 * \
		(data->bits_per_pixel / 8));
	*(unsigned int *)dst = 0x00FF0000;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

void	render(t_data *data)
{
	data->mlx_ptr = mlx_init(); //jogar isso no init_data ?
	if (!(data->mlx_ptr))
		exit_error(INTERFACE_ERROR, 2, data);
	mlx_get_screen_size(data->mlx_ptr, &data->size_x, &data->size_y); //
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->size_x - 30, \
		data->size_y - 480, "miniRT"); //qual tamanho? pelo arquivo rt?
	data->img = mlx_new_image(data->mlx_ptr, data->size_x - 30, data->size_y - 480);
	mlx_expose_hook(data->win_ptr, &handle_render, data);
	mlx_key_hook(data->win_ptr, &handle_esc, data);
	mlx_hook(data->win_ptr, 17, 0, &handle_x, data);
	mlx_loop(data->mlx_ptr);
}
