/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:42:10 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/06 21:12:30 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	set_color(char *arg, t_color *color, t_data *data);
int	set_tuple(char *arg, t_tuple *tuple, t_data *data);

int	add_plane(t_token *token, t_data *data)
{
	token->type = PLANE;
	set_tuple(token->args[1], &token->coordinate, data);
	set_tuple(token->args[2], &token->normalized_vector, data);
	set_color(token->args[3], &token->color, data);
	return (0);
}

int	add_sphere(t_token *token, t_data *data)
{
	token->type = SPHERE;
	set_tuple(token->args[1], &token->coordinate, data);
	token->diameter = atod(token->args[2]);
	set_color(token->args[3], &token->color, data);
	return (0);
}

int	add_cylinder(t_token *token, t_data *data)
{
	token->type = CYLINDER;
	set_tuple(token->args[1], &token->coordinate, data);
	set_tuple(token->args[2], &token->normalized_vector, data);
	token->diameter = atod(token->args[3]);
	token->height = atod(token->args[4]);
	set_color(token->args[5], &token->color, data);
	return (0);
}

int	set_color(char *arg, t_color *color, t_data *data)
{
	char	**color_splited;

	color_splited = ft_split(arg, ',');
	if (!color_splited)
		exit_error("fail color\n", 2, data);
	color->r = atod(color_splited[0]);
	color->g = atod(color_splited[1]);
	color->b = atod(color_splited[2]);
	free_array((void **)color_splited);
	return (0);
}

int	set_tuple(char *arg, t_tuple *tuple, t_data *data)
{
	char	**tuple_splited;

	tuple_splited = ft_split(arg, ',');
	if (!tuple_splited)
		exit_error("fail color\n", 2, data);
	tuple->x = atod(tuple_splited[0]);
	tuple->y = atod(tuple_splited[1]);
	tuple->z = atod(tuple_splited[2]);
	if (tuple_splited[3])
		tuple->c = atod(tuple_splited[3]);
	free_array((void **)tuple_splited);
	return (0);
}
