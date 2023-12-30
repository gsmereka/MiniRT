/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:42:37 by gsmereka          #+#    #+#             */
/*   Updated: 2023/12/04 20:58:54 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_scene	*alloc_scene(int lights_size, int objects_size)
{
	t_scene	*scene;

	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->object_ray = ft_calloc(1, sizeof(t_ray));
	scene->light_ray = ft_calloc(1, sizeof(t_ray));
	scene->lights = (t_token **)ft_calloc(lights_size
			+ 1, sizeof(t_token *));
	scene->objects = (t_token **)ft_calloc(objects_size
			+ 1, sizeof(t_token *));
	if (!scene->object_ray || !scene->object_ray
		|| !scene->lights || !scene->objects)
	{
		free(scene->object_ray);
		free(scene->light_ray);
		free(scene->lights);
		free(scene->objects);
		free(scene);
		return (NULL);
	}
	return (scene);
}

void	define_ambient_ilumination(t_scene *scene, t_token *token)
{
	scene->ambient_color = normalize_color(&token->color);
	scene->ambient_light = token->lighting_ratio;
	scene->ambient_color = multiply_color_scalar(&scene->ambient_color,
			scene->ambient_light);
}

void	define_objects(t_scene *scene, t_token *token, t_data *data)
{
	int		objects;
	int		lights;

	objects = 0;
	lights = 0;
	while (token)
	{
		if (token->type == 1 || token->type == 2 || token->type == 3)
			scene->objects[objects++] = token;
		else if (token->type == 4)
			data->camera = init_camera(token, data);
		else if (token->type == 5)
			scene->lights[lights++] = token;
		else if (token->type == 6)
			define_ambient_ilumination(scene, token);
		token = token->next;
	}
}

void	define_scene(t_data *data)
{
	t_scene			*scene;

	if (!data->win_height || !data->win_width)
	{
		data->win_width = 1280;
		data->win_height = 900;
	}
	scene = alloc_scene(data->lights_size, data->objects_size);
	if (!scene)
		exit_error("Error\nAlloc scene\n", 4, data);
	define_objects(scene, data->tokens, data);
	data->scene = scene;
}
