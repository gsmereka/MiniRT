/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:42:10 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/04 10:45:51 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	set_color(char *arg, t_color *color, t_data *data);
int	set_tuple(char *arg, t_tuple *tuple, t_data *data);

int	add_plane(char **args, t_data *data)
{
	t_plane	*plane;

	plane = data->plane;
	if (plane)
	{
		plane = (t_plane *)token_last((t_token *)data->plane);
		plane = plane->next;
	}
	plane = ft_calloc(1, sizeof(t_light));
	if (!plane)
		exit_error("fail plane\n", 2, data);
	plane = (t_plane *){0};
	set_tuple(args[1], &plane->coordinate, data);
	set_tuple(args[2], &plane->normalized_vector, data);
	set_color(args[3], &plane->color, data);
	return (0);
}

int	add_sphere(char **args, t_data *data)
{
	t_sphere	*sphere;

	sphere = data->sphere;
	if (sphere)
	{
		sphere = (t_sphere *)token_last((t_token *)data->sphere);
		sphere = sphere->next;
	}
	sphere = ft_calloc(1, sizeof(t_light));
	if (!sphere)
		exit_error("fail sphere\n", 2, data);
	sphere = (t_sphere *){0};
	set_tuple(args[1], &sphere->coordinate, data);
	sphere->diameter = atod(args[2]);
	set_color(args[3], &sphere->color, data);
	return (0);
}

int	add_cylinder(char **args, t_data *data)
{
	t_cylinder	*cylinder;

	cylinder = data->cylinder;
	if (cylinder)
	{
		cylinder = (t_cylinder *)token_last((t_token *)data->cylinder);
		cylinder = cylinder->next;
	}
	cylinder = ft_calloc(1, sizeof(t_light));
	if (!cylinder)
		exit_error("fail cylinder\n", 2, data);
	cylinder = (t_cylinder *){0};
	set_tuple(args[1], &cylinder->coordinate, data);
	set_tuple(args[2], &cylinder->normalized_vector, data);
	cylinder->diameter = atod(args[3]);
	cylinder->height = atod(args[4]);
	set_color(args[5], &cylinder->color, data);
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
