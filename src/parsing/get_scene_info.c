/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:13:32 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/05 00:46:38 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	is_new_line(char **args);

int	get_scene_info(t_data *data)
{
	t_gnl_token	*gnl_token;

	gnl_token = data->gnl_tokens;
	while (gnl_token)
	{
		if (is_camera(gnl_token->args, data))
			add_camera(gnl_token->args, data);
		else if (is_ambient_lighting(gnl_token->args, data))
			add_ambient_lighting(gnl_token->args, data);
		else if (is_light(gnl_token->args, data))
			add_light(gnl_token->args, data);
		else if (is_resolution(gnl_token->args, data))
			add_resolution(gnl_token->args, data);
		else if (is_cylinder(gnl_token->args, data))
			add_cylinder(gnl_token->args, data);
		else if (is_sphere(gnl_token->args, data))
			add_sphere(gnl_token->args, data);
		else if (is_plane(gnl_token->args, data))
			add_plane(gnl_token->args, data);
		else if (!is_new_line(gnl_token->args))
			exit_error(INVALID_LINE, 2, data);
		gnl_token = gnl_token->next;
	}
	if (!data->camera || !data->light || !data->ambient_lighting)
		exit_error("Error\nYou need light, camera and ambient lighting!\n", 2, data);
	return (0);
}

int	is_new_line(char **args)
{
	if (ft_strcmp(args[0], "\n") != 0)
		return (0);
	if (args[1])
		return (0);
	return (1);
}
