/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:06:05 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/30 02:50:05 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

static void	free_data(t_data *data)
{
	if (data->mlx_ptr && data->img)
		mlx_destroy_image(data->mlx_ptr, data->img);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

int	exit_error(char *msg, int status, t_data *data)
{
	ft_printf(msg);
	free_data(data);
	exit(status);
}

int	exit_successful(t_data *data)
{
	free_data(data);
	exit (0);
}
