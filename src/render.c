/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:20:54 by gde-mora          #+#    #+#             */
/*   Updated: 2023/07/03 23:46:50 by gde-mora         ###   ########.fr       */
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
	char	*pointer;
	int		i;
	//int		pos;

	i = 0;
	//int pos = (y * size_line + x * (bits_per_pixel / 8));
	//deve ter verificação para n usar pontos q passem da tela
	data->address_img = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
		&data->size_line, &data->endian);
	while (i < 16)
	{
		pointer = data->address_img + (i * data->size_line + i * \
		(data->bits_per_pixel / 8));
		*(unsigned int *)pointer = 0x00FF0000;
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

void	render(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		exit_error(INTERFACE_ERROR, 2, data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
		data->win_width, data->win_height, "miniRT");
	data->img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	mlx_expose_hook(data->win_ptr, &handle_render, data);
	mlx_key_hook(data->win_ptr, &handle_esc, data);
	mlx_hook(data->win_ptr, 17, 0, &handle_x, data);
	mlx_loop(data->mlx_ptr);
}
