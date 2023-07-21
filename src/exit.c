/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:06:05 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/21 18:26:57 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

static void	free_data(t_data *data)
{
	if (data->mlx_ptr && data->img)
		mlx_destroy_image(data->mlx_ptr, data->img);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->idmatrix_2x2)
		free_matrix(data->idmatrix_2x2);
	if (data->idmatrix_3x3)
		free_matrix(data->idmatrix_3x3);
	if (data->idmatrix_4x4)
		free_matrix(data->idmatrix_4x4);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->tokens)
		token_clear(&data->tokens);
}

int	exit_error(char *msg, int status, t_data *data)
{
	ft_putstr_fd(msg, 2);
	free_data(data);
	exit(status);
}

int	exit_successful(t_data *data)
{
	free_data(data);
	exit (0);
}
