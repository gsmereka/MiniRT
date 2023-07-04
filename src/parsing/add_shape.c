/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:42:10 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/05 00:48:27 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	set_color(char *arg, t_color *color, t_data *data);
int	set_tuple(char *arg, t_tuple *tuple, t_data *data);

int	add_plane(char **args, t_data *data)
{
	t_object	*plane;

	plane = data->plane;
	if (plane)
	{
		plane = (t_object *)gnl_token_last((t_gnl_token *)data->plane);
		plane = plane->next;
	}
	plane = ft_calloc(1, sizeof(t_object));
	if (!plane)
		exit_error("fail plane\n", 2, data);
	plane = (t_object *){0};
	set_tuple(args[1], &plane->coordinate, data);
	set_tuple(args[2], &plane->normalized_vector, data);
	set_color(args[3], &plane->color, data);
	return (0);
}

int	add_sphere(char **args, t_data *data)
{
	t_object	*sphere;

	sphere = data->sphere;
	if (sphere)
	{
		sphere = (t_object *)gnl_token_last((t_gnl_token *)data->sphere);
		sphere = sphere->next;
	}
	sphere = ft_calloc(1, sizeof(t_object));
	if (!sphere)
		exit_error("fail sphere\n", 2, data);
	sphere = (t_object *){0};
	set_tuple(args[1], &sphere->coordinate, data);
	sphere->diameter = atod(args[2]);
	set_color(args[3], &sphere->color, data);
	return (0);
}

int	add_cylinder(char **args, t_data *data)
{
	t_object	*cylinder;

	cylinder = data->cylinder;
	while (cylinder)
		cylinder = cylinder->next;
	if (!cylinder)
		cylinder = ft_calloc(1, sizeof(t_object));
	if (!cylinder)
		exit_error("fail cylinder\n", 2, data);
	if (!data->cylinder)
		data->cylinder = cylinder;
	(void)args;
	//set_tuple(args[1], &cylinder->coordinate, data);
	//set_tuple(args[2], &cylinder->normalized_vector, data);
	//cylinder->diameter = atod(args[3]);
	//cylinder->height = atod(args[4]);
	//set_color(args[5], &cylinder->color, data);
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
