/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_normalized_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:12:47 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/03 22:24:10 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

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
