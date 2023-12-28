/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:07:45 by gde-mora          #+#    #+#             */
/*   Updated: 2023/11/23 18:44:17 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	is_coordinate(char *arg);
int	is_normalized_3d_direction(char *arg);
int	is_color(char *arg);

int	is_coordinate(char *arg)
{
	char	**rgb;
	int		count;

	rgb = ft_split(arg, ',');
	if (!rgb)
		return (0);
	count = 0;
	while (rgb[count])
		count++;
	if (count != 3)
	{
		free_array((void **)rgb);
		return (0);
	}
	free_array((void **)rgb);
	return (1);
}

int	is_normalized_3d_direction(char *arg)
{
	char	**vector;
	t_tuple	tuple;
	int		index;
	double	value;

	vector = ft_split(arg, ',');
	if (!vector)
		return (0);
	index = 0;
	while (vector[index])
	{
		value = atod(vector[index]);
		if (value < -1 || value > 1)
		{
			free_array((void **)vector);
			return (0);
		}
		index++;
	}
	tuple = (t_tuple){0};
	tuple.x = atod(vector[0]);
	tuple.y = atod(vector[1]);
	tuple.z = atod(vector[2]);
	free_array((void **)vector);
	if (!are_floats_equal(1, tuple_magnitude(&tuple)))
		return(0);
	if (index != 3)
		return (0);
	return (1);
}

int	is_color(char *arg)
{
	char	**rgb;
	int		index;
	int		value;

	rgb = ft_split(arg, ',');
	if (!rgb)
		return (0);
	index = 0;
	while (rgb[index])
	{
		value = ft_atoi(rgb[index]);
		if (value < 0 || value > 255)
		{
			free_array((void **)rgb);
			return (0);
		}
		index++;
	}
	free_array((void **)rgb);
	if (index != 3)
		return (0);
	return (1);
}
