/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_configs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:57:27 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/03 23:47:35 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	is_ambient_lighting(char **args, t_data *data)
{
	if (args && ft_strcmp(args[0], "A") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	(void)data;
	return (0);
}

int	is_light(char **args, t_data *data)
{
	if (args && ft_strcmp(args[0], "L") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	(void)data;
	return (0);
}

int	is_camera(char **args, t_data *data)
{
	if (args && ft_strcmp(args[0], "C") == 0)
	{
		ft_printf("positive\n");
		return (1);
	}
	(void)data;
	return (0);
}

int	is_resolution(char **args, t_data *data)
{
	int	i;
	int	win_width;
	int	win_height;

	i = 0;
	if (args && ft_strcmp(args[0], "R") == 0)
	{
		while (args[i])
			i++;
		if (i < 3)
			exit_error(WRONG_RESOLUTION, 2, data);
		win_height = ft_atoi(args[2]);
		win_width = ft_atoi(args[1]);
		if (win_height <= 0 || win_height > MAX_HEIGHT)
			exit_error(MAX_RESOLUTION, 2, data);
		if (win_width <= 0 || win_width > MAX_WIDTH)
			exit_error(MAX_RESOLUTION, 2, data);
		return (1);
	}
	return (0);
}
