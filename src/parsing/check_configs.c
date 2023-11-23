/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_configs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:57:27 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/23 18:44:17 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	is_ambient_lighting(char **args, t_data *data)
{
	static int	paramenter_count;
	int			i;
	float		lighting_ratio;

	if (paramenter_count != 0 && ft_strcmp(args[0], "A") == 0)
		exit_error(REPEATED, 2, data);
	if (args && ft_strcmp(args[0], "A") == 0)
	{
		paramenter_count++;
		i = 0;
		while (args[i])
			i++;
		if (i != 3)
			exit_error(AMBIENT_ERROR, 2, data);
		lighting_ratio = atod(args[1]);
		if (lighting_ratio < 0 || lighting_ratio > 1)
			exit_error(AMBIENT_RATIO_ERROR, 2, data);
		if (!is_color(args[2]))
			exit_error(AMBIENT_COLOR_ERROR, 2, data);
		return (1);
	}
	return (0);
}

int	is_camera(char **args, t_data *data)
{
	static int	paramenter_count;
	int			fov;
	int			i;

	if (paramenter_count != 0 && ft_strcmp(args[0], "C") == 0)
		exit_error(REPEATED, 2, data);
	if (args && ft_strcmp(args[0], "C") == 0)
	{
		paramenter_count++;
		i = 0;
		while (args[i])
			i++;
		if (i != 4)
			exit_error(CAMERA_ERROR, 2, data);
		if (!is_coordinate(args[1]))
			exit_error(CAMERA_COORDINATE_ERROR, 2, data);
		if (!is_normalized_3d_direction(args[2]))
			exit_error(CAMERA_3D_NORMALIZED_VECTOR_ERROR, 2, data);
		fov = atod(args[3]);
		if (fov < 0 || fov > 180)
			exit_error(CAMERA_FOV_ERROR, 2, data);
		return (1);
	}
	return (0);
}

int	is_light(char **args, t_data *data)
{
	int		i;
	double	lighting_ratio;

	i = 0;
	if (args && ft_strcmp(args[0], "L") == 0)
	{
		while (args[i])
			i++;
		if (i != 3)
			exit_error(LIGHT_ERROR, 2, data);
		if (!is_coordinate(args[1]))
			exit_error(LIGHT_COORDINATE_ERROR, 2, data);
		lighting_ratio = atod(args[2]);
		if (lighting_ratio < 0 || lighting_ratio > 1)
			exit_error(LIGHT_LIGHTING_RATIO_ERROR, 2, data);
		return (1);
	}
	return (0);
}

int	is_resolution(char **args, t_data *data)
{
	static int	paramenter_count;
	int			i;
	int			win_width;
	int			win_height;

	i = 0;
	if (paramenter_count != 0 && ft_strcmp(args[0], "R") == 0)
		exit_error(REPEATED, 2, data);
	if (args && ft_strcmp(args[0], "R") == 0)
	{
		paramenter_count++;
		while (args[i])
			i++;
		if (i != 3)
			exit_error(WRONG_RESOLUTION, 2, data);
		win_height = ft_atoi(args[2]);
		win_width = ft_atoi(args[1]);
		if (win_height <= 0 || win_height > MAX_HEIGHT)
			exit_error(MAX_RESOLUTION, 2, data);
		if (win_width <= 0 || win_width > MAX_WIDTH)
			exit_error(MAX_RESOLUTION, 2, data);
		return (1);
	}
	return (0);
}
