/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_configs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:57:27 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/30 18:48:17 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	is_ambient_lighting(char **args)
{
	if (args && ft_strcmp(args[0], "A") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	return (0);
}

int	is_light(char **args)
{
	if (args && ft_strcmp(args[0], "L") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	return (0);
}

int	is_camera(char **args)
{
	if (args && ft_strcmp(args[0], "C") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	return (0);
}

int	is_resolution(char **args)
{
	if (args && ft_strcmp(args[0], "R") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	return (0);
}
