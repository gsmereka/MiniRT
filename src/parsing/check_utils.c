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
	t_tuple	tuple;
	char	**vector;
	int		index;

	vector = ft_split(arg, ',');
	if (!vector)
		return (0);
	index = 0;
	while (vector[index])
		index++;
	if (index != 3)
	{
		free_array((void **)vector);
		return (0);
	}
	tuple = create_vector(atod(vector[0]), atod(vector[1]), atod(vector[2]));
	free_array((void **)vector);
	if ((tuple.x < -1 || tuple.x > 1)
		|| (tuple.y < -1 || tuple.y > 1) || (tuple.z < -1 || tuple.z > 1))
		return (0);
	if (!are_floats_equal(1, tuple_magnitude(&tuple)))
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
