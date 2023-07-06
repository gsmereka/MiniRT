/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:41:28 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/06 21:08:34 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	add_ambient_lighting(t_token *token, t_data *data)
{
	char	**color;

	token->type = AMBIENT_LIGHTING;
	data->has_ambient_lighting = 1;
	token->ratio = atod(token->args[1]);
	color = ft_split(token->args[2], ',');
	if (!color)
		exit_error("fail color\n", 2, data);
	token->color.r = atod(color[0]);
	token->color.g = atod(color[1]);
	token->color.b = atod(color[2]);
	free_array((void **)color);
	return (0);
}

int	add_light(t_token *token, t_data *data)
{
	char	**coordinates;

	token->type = LIGHT;
	data->has_light = 1;
	coordinates = ft_split(token->args[1], ',');
	if (!coordinates)
		exit_error("fail coordinate\n", 2, data);
	token->coordinate.x = atod(coordinates[0]);
	token->coordinate.y = atod(coordinates[1]);
	token->coordinate.z = atod(coordinates[2]);
	free_array((void **)coordinates);
	//token->normalized_vector.x = normalize(coordinates[0]);
	token->brightness = atod(token->args[2]);
	return (0);
}

int	add_camera(t_token *token, t_data *data)
{
	char	**coordinates;
	char	**normalized_vector;

	token->type = CAMERA;
	data->has_camera = 1;
	coordinates = ft_split(token->args[1], ',');
	if (!coordinates)
		exit_error("fail coordinate\n", 2, data);
	token->coordinate.x = atod(coordinates[0]);
	token->coordinate.y = atod(coordinates[1]);
	token->coordinate.z = atod(coordinates[2]);
	free_array((void **)coordinates);
	normalized_vector = ft_split(token->args[2], ',');
	if (!normalized_vector)
		exit_error("fail_normalized_vector\n", 2, data);
	token->normalized_vector.x = atod(normalized_vector[0]);
	token->normalized_vector.y = atod(normalized_vector[1]);
	token->normalized_vector.z = atod(normalized_vector[2]);
	free_array((void **)normalized_vector);
	return (1);
}

int	add_resolution(char	**args, t_data *data)
{
	data->win_height = ft_atoi(args[2]);
	data->win_width = ft_atoi(args[1]);
	return (0);
}
