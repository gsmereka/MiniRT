/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:41:28 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/05 00:47:26 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	add_ambient_lighting(char **args, t_data *data)
{
	char	**color;

	data->ambient_lighting = ft_calloc(1, sizeof(t_object));
	data->ambient_lighting->ratio = atod(args[1]);
	color = ft_split(args[2], ',');
	if (!color)
		exit_error("fail color\n", 2, data);
	data->ambient_lighting->color.r = atod(color[0]);
	data->ambient_lighting->color.g = atod(color[1]);
	data->ambient_lighting->color.b = atod(color[2]);
	free_array((void **)color);
	return (0);
}

int	add_light(char **args, t_data *data)
{
	char	**coordinates;

	data->light = ft_calloc(1, sizeof(t_object));
	coordinates = ft_split(args[1], ',');
	if (!coordinates)
		exit_error("fail coordinate\n", 2, data);
	data->light->coordinate.x = atod(coordinates[0]);
	data->light->coordinate.y = atod(coordinates[1]);
	data->light->coordinate.z = atod(coordinates[2]);
	free_array((void **)coordinates);
	//data->light->normalized_vector.x = normalize(coordinates[0]);
	data->light->brightness = atod(args[2]);
	return (0);
}

int	add_camera(char **args, t_data *data)
{
	char	**coordinates;
	char	**normalized_vector;

	data->camera = ft_calloc(1, sizeof(t_object));
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
