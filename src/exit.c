/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:06:05 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/04 10:51:37 by gsmereka         ###   ########.fr       */
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
	if (data->tokens)
		token_clear(&data->tokens);
	if (data->camera)
		free(data->camera);
	if (data->light)
		free_light(data->light);
	if (data->ambient_lighting)
		free(data->ambient_lighting);
	if (data->cylinder)
		free_cylinder(data->cylinder);
	if (data->sphere)
		free_sphere(data->sphere);
	if (data->plane)
		free_plane(data->plane);
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

int	free_array(void **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}
