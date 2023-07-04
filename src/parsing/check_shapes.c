/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:57:21 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/03 22:37:01 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	is_plane(char **args, t_data *data)
{
	int			i;

	if (args && ft_strcmp(args[0], "pl") == 0)
	{
		i = 0;
		while(args[i])
			i++;
		if (i != 4)
			exit_error(WRONG_RESOLUTION, 2, data);
		if (!is_coordinate(args[1]))
			exit_error(REPEATED, 2, data);
		if (!is_normalized_vector(args[2]))
			exit_error(REPEATED, 2, data);
		if (!is_color(args[2]))
			exit_error(REPEATED, 2, data);
		return (1);
	}
	return (0);
}

int	is_sphere(char **args, t_data *data)
{
	int		i;
	double	diameter;

	if (args && ft_strcmp(args[0], "sp") == 0)
	{
		i = 0;
		while(args[i])
			i++;
		if (i != 4)
			exit_error(WRONG_RESOLUTION, 2, data);
		if (!is_coordinate(args[1]))
			exit_error(REPEATED, 2, data);
		diameter = atod(args[2]);
		if (diameter <= 0)
			exit_error(REPEATED, 2, data);
		if (!is_color(args[3]))
			exit_error(REPEATED, 2, data);
		return (1);
	}
	return (0);
}

int	is_cylinder(char **args, t_data *data)
{
	double	diameter;
	double	height;
	int		i;

	if (args && ft_strcmp(args[0], "cy") == 0)
	{
		i = 0;
		while(args[i])
			i++;
		if (i != 5)
			exit_error(WRONG_RESOLUTION, 2, data);
		if (!is_coordinate(args[1]))
			exit_error(REPEATED, 2, data);
		if (!is_normalized_vector(args[2]))
			exit_error(REPEATED, 2, data);
		diameter = atod(args[3]);
		if (diameter <= 0)
			exit_error(REPEATED, 2, data);
		height = atod(args[4]);
		if (height <= 0)
			exit_error(REPEATED, 2, data);
		if (!is_color(args[5]))
			exit_error(REPEATED, 2, data);
		return (1);
	}
	return (0);
}
