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

void	define_objects(t_scene **scene, t_data *data)
{
	t_token	*aux;
	int		objects;
	int		lights;

	aux = data->tokens;
	objects = 0;
	lights = 0;
	while (aux)
	{
		if (aux->type == 1 || aux->type == 2 || aux->type == 3)
		{
			(*scene)->objects[objects] = aux;
			objects++;
		}
		else if (aux->type == 4)
			data->camera = init_camera(aux, data);
		else if (aux->type == 5)
		{
			(*scene)->lights[lights] = aux;
			lights++;
		}
		else if (aux->type == 6)
		{
			(*scene)->ambient_color = normalize_color(&aux->color);
			(*scene)->ambient_light = aux->lighting_ratio;
			(*scene)->ambient_color = multiply_color_scalar(&(*scene)->ambient_color, (*scene)->ambient_light); // definindo a cor ambiente.
		}
		aux = aux->next;
	}
}

void	define_scene(t_data *data)
{
	t_scene			*scene;

	if (!data->win_height || !data->win_width)
	{
		data->win_width = 1000;
		data->win_height = 700;
	}
	scene = alloc_scene(data->lights_size, data->objects_size);
	if (!scene)
		exit_error("Error at create scene\n", 4, data);
	define_objects(&scene, data);
	data->scene = scene;
}
