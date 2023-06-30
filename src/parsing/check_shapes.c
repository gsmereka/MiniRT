/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:57:21 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/30 15:20:10 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	is_plane(char **args)
{
	if (args && ft_strcmp(args[0], "pl") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	return (0);
}

int	is_sphere(char **args)
{
	if (args && ft_strcmp(args[0], "sp") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	return (0);
}

int	is_cylinder(char **args)
{
	if (args && ft_strcmp(args[0], "cy") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	return (0);
}
