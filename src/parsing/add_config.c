/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:41:28 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/04 00:01:21 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	add_ambient_lighting(char **args, t_data *data)
{
	(void)data;
	if (args && ft_strcmp(args[0], "A") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	return (0);
}

int	add_light(char **args, t_data *data)
{
	(void)data;
	if (args && ft_strcmp(args[0], "L") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	return (0);
}

int	add_camera(char **args, t_data *data)
{
	char	**coordinates;
	char	**normalized_vector;

	data->camera = ft_calloc(1, sizeof(t_camera));
	data->camera = (t_camera *){0};
	coordinates = ft_split(args[1], ',');
	if (!coordinates)
		exit_error("fail coordinate\n", 2, data);
	data->camera->coordinate.x = atod(coordinates[0]);
	data->camera->coordinate.y = atod(coordinates[1]);
	data->camera->coordinate.z = atod(coordinates[2]);
	free_array((void **)coordinates);
	normalized_vector = ft_split(args[2], ',');
	if (!normalized_vector)
		exit_error("fail_normalized_vector\n", 2, data);
	data->camera->normalized_vector.x = atod(normalized_vector[0]);
	data->camera->normalized_vector.y = atod(normalized_vector[1]);
	data->camera->normalized_vector.z = atod(normalized_vector[2]);
	free_array((void **)normalized_vector);
	return (1);
}

int	add_resolution(char	**args, t_data *data)
{
	data->win_height = ft_atoi(args[2]);
	data->win_width = ft_atoi(args[1]);
	return (0);
}
