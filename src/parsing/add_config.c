/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:41:28 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/30 19:16:32 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	add_ambient_lighting(char **args, t_data *data)
{
	(void)data;
	if (args && ft_strcmp(args[0], "A") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	return (0);
}

int	add_light(char **args, t_data *data)
{
	(void)data;
	if (args && ft_strcmp(args[0], "L") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	return (0);
}

int	add_camera(char **args, t_data *data)
{
	(void)data;
	if (args && ft_strcmp(args[0], "C") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	return (0);
}
