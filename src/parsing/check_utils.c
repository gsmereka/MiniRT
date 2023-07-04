/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:07:45 by gde-mora          #+#    #+#             */
/*   Updated: 2023/07/05 01:10:46 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	is_coordinate(char *arg);
int	is_normalized_vector(char *arg);
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

int	is_normalized_vector(char *arg)
{
	char	**rgb;
	int		count;
	double	axis;

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
	count = 0;
	while (rgb[count])
	{
		axis = atod(rgb[count]);
		if (axis < 0 || axis > 1)
		{
			free_array((void **)rgb);
			return (0);
		}
		count++;
	}
	free_array((void **)rgb);
	return (1);
}

int	is_color(char *arg)
{
	char	**rgb;
	double	color;
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
	count = 0;
	while (rgb[count])
	{
		color = atod(rgb[count]);
		if (color < 0 || color > 255)
		{
			free_array((void **)rgb);
			return (0);
		}
		count++;
	}
	free_array((void **)rgb);
	return (1);
}
