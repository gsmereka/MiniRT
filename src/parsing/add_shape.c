/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:42:10 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/30 19:16:17 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	add_plane(char **args, t_data *data)
{
	(void)data;
	if (args && ft_strcmp(args[0], "pl") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	return (0);
}

int	add_sphere(char **args, t_data *data)
{
	(void)data;
	if (args && ft_strcmp(args[0], "sp") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	return (0);
}

int	add_cylinder(char **args, t_data *data)
{
	(void)data;
	if (args && ft_strcmp(args[0], "cy") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	return (0);
}
