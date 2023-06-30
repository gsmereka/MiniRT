/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:13:32 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/30 19:16:43 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	is_new_line(char **args);
int	add_resolution(char	**args, t_data *data);

int	get_scene_info(t_data *data)
{
	t_token	*token;

	token = data->tokens;
	while (token)
	{
		if (is_camera(token->args))
			add_camera(token->args, data);
		else if (is_ambient_lighting(token->args))
			add_ambient_lighting(token->args, data);
		else if (is_light(token->args))
			add_light(token->args, data);
		else if (is_resolution(token->args))
			add_resolution(token->args, data);
		else if (is_cylinder(token->args))
			add_cylinder(token->args, data);
		else if (is_sphere(token->args))
			add_sphere(token->args, data);
		else if (is_plane(token->args))
			add_plane(token->args, data);
		else if (!is_new_line(token->args))
			exit_error(INVALID_LINE, 2, data);
		token = token->next;
	}
	return (0);
}

int	add_resolution(char	**args, t_data *data)
{
	(void)args;
	(void)data;
	ft_printf("is resolution\n");
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
