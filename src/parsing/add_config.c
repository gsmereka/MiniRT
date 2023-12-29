/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:41:28 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/23 18:44:17 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	add_ambient_lighting(t_token *token, t_data *data)
{
	char	**color;

	token->type = AMBIENT_LIGHTING;
	data->has_ambient_lighting = 1;
	token->lighting_ratio = atod(token->args[1]);
	color = ft_split(token->args[2], ',');
	if (!color)
		exit_error("Error\nFail at split on add_ambient_lighting()\n", 2, data);
	token->color.r = ft_atoi(color[0]);
	token->color.g = ft_atoi(color[1]);
	token->color.b = ft_atoi(color[2]);
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
		exit_error("Error\nFail at split on add_light()\n", 2, data);
	token->coordinate.x = atod(coordinates[0]);
	token->coordinate.y = atod(coordinates[1]);
	token->coordinate.z = atod(coordinates[2]);
	free_array((void **)coordinates);
	token->lighting_ratio = atod(token->args[2]);
	data->lights_size++;
	return (0);
}

int	add_camera(t_token *token, t_data *data)
{
	char	**coordinates;
	char	**normalized_3d_direction;

	token->type = CAMERA;
	data->has_camera = 1;
	coordinates = ft_split(token->args[1], ',');
	if (!coordinates)
		exit_error("Error\nFail at split on add_camera()\n", 2, data);
	token->coordinate.x = atod(coordinates[0]);
	token->coordinate.y = atod(coordinates[1]);
	token->coordinate.z = atod(coordinates[2]);
	free_array((void **)coordinates);
	normalized_3d_direction = ft_split(token->args[2], ',');
	if (!normalized_3d_direction)
		exit_error("Error\nFail at split on add_camera()\n", 2, data);
	token->normalized_3d_direction.x = atod(normalized_3d_direction[0]);
	token->normalized_3d_direction.y = atod(normalized_3d_direction[1]);
	token->normalized_3d_direction.z = atod(normalized_3d_direction[2]);
	free_array((void **)normalized_3d_direction);
	token->fov = atod(token->args[3]);
	return (1);
}

int	add_resolution(char	**args, t_data *data)
{
	data->win_height = ft_atoi(args[2]);
	data->win_width = ft_atoi(args[1]);
	return (0);
}
