/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:13:32 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/06 21:56:29 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	is_new_line(char **args);

void	get_scene_info(t_token *token, t_data *data)
{
	while (token)
	{
		if (is_camera(token->args, data))
			add_camera(token, data);
		else if (is_ambient_lighting(token->args, data))
			add_ambient_lighting(token, data);
		else if (is_light(token->args, data))
			add_light(token, data);
		else if (is_resolution(token->args, data))
			add_resolution(token->args, data);
		else if (is_cylinder(token->args, data))
			add_cylinder(token, data);
		else if (is_sphere(token->args, data))
			add_sphere(token, data);
		else if (is_plane(token->args, data))
			add_plane(token, data);
		else if (!is_new_line(token->args))
			exit_error(INVALID_LINE, 2, data);
		token = token->next;
	}
	if (!data->has_camera || !data->has_light || !data->has_ambient_lighting)
		exit_error(NEED_ALL_COMPONENTS, 2, data);
}

int	is_new_line(char **args)
{
	if (ft_strcmp(args[0], "\n") != 0)
		return (0);
	if (args[1])
		return (0);
	return (1);
}
