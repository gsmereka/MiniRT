/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:55:50 by gsmereka          #+#    #+#             */
/*   Updated: 2023/08/13 15:42:16 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void multiply_teste_tuple(t_tuple *tuple, double factor)
{
	tuple->x = tuple->x * factor;
	tuple->y = tuple->y * factor;
	tuple->z = tuple->z * factor;
}

void	paint_relogio(t_tuple *tuple, unsigned int color, t_data *data);

void	criar_relogio(t_data *data)
{
	double		angulo;
	double		raio;
	t_matrix	rota;
	t_tuple		ponto;
	t_tuple		temp;
	int			i;

	angulo = (M_PI / 6);
	raio = (3.0 / 8) * data->win_width;
	temp = create_point(0, 0, raio);
	rota = rotation_y(data, angulo);
	i = 0;
	while(i <= 12)
	{
		ponto = multiply_matrix_with_tuple(&rota, &temp);
		paint_relogio(&ponto, RED, data);
		pass_tuple_values(&temp, &ponto);
		i++;
	}
}

void	criar_relogio_2(t_data *data)
{
	t_tuple		relogio;
	t_tuple		twelve;
	t_tuple		three;
	t_tuple		extra;
	double		raio;
	t_matrix	r;
	t_matrix	r_2;

	(void)data;
	// passo 2
	relogio = create_point(0, 0, 0);
	twelve = create_point(0, 0, 1);

	// passo 3
	r = rotation_y(data, (3 * M_PI) / 6);
	three = multiply_matrix_with_tuple(&r, &twelve);
	// print_tuple(three);

	// passo 4
	raio = (3.0 / 8) * data->win_width;

	multiply_teste_tuple(&twelve, raio);
	multiply_teste_tuple(&three, raio);

	paint_relogio(&twelve, RED, data);
	paint_relogio(&three, RED, data);
	paint_relogio(&relogio, GREEN, data);

	// passo

	r_2 = rotation_y(data, M_PI / 6);
	extra = multiply_matrix_with_tuple(&r_2, &twelve);
	print_tuple(&extra);
	paint_relogio(&extra, RED, data);
}

void	paint_relogio(t_tuple *tuple, unsigned int color, t_data *data)
{
	int		i;
	int		x;
	int		z;

	i = 0;
	x = dtoi(tuple->x);
	z = dtoi(tuple->z);
	while (i < 16)
	{
		paint_pixel(x + i, z, color, data);
		paint_pixel(x, z + i, color, data);
		paint_pixel(x + i, z + 15, color, data);
		paint_pixel(x + 15, z + i, color, data);
		i++;
	}
}

static int	handle_render(t_data *data)
{
	data->address_img = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
		&data->size_line, &data->endian);
	criar_relogio(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

int	test_render(t_data	*data)
{
	// criar_relogio(data);
	// exit_error("", 0, data);
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		exit_error(INTERFACE_ERROR, 2, data);
	if (!data->win_width && !data->win_height)
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
	mlx_loop(data->mlx_ptr);
	return (1);
}
