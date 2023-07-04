/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:54:11 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/03 22:10:40 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

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
