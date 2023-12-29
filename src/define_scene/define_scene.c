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

void	adicionar_esfera(t_token **list, t_tuple *center, double raio, t_color *color) // remover depois
{
	t_token	*esfera;
	t_tuple	point;
	t_token	*aux;

	aux = *list;
	while (aux && aux->next)
		aux = aux->next;
	esfera = ft_calloc(1, sizeof(t_token));
	point = create_point(center->x, center->y, center->z);
	pass_tuple_values(&esfera->coordinate, &point);
	esfera->color.r = color->r;
	esfera->color.g = color->g;
	esfera->color.b = color->b;
	esfera->diameter = raio * 2;
	esfera->type = SPHERE;
	aux->next = esfera;
}

void	adicionar_luz(t_token **list, t_tuple *coordinate, double lighting_ratio)
{
	t_token *luz;
	t_token	*aux;

	aux = *list;
	while (aux && aux->next)
		aux = aux->next;
	luz = ft_calloc(1, sizeof(t_token));
	luz->type = 5;
	luz->lighting_ratio = lighting_ratio;
	pass_tuple_values(&luz->coordinate, coordinate);
	luz->coordinate.w = 1;
	aux->next = luz;
}

void	adicionar_luz_ambiente(t_token **list, t_color *color, double lighting_ratio) // remover depois
{
	t_token	*luz;
	t_token	*aux;

	aux = *list;
	while (aux && aux->next)
		aux = aux->next;
	luz = ft_calloc(1, sizeof(t_token));
	luz->type = 6;
	luz->lighting_ratio = lighting_ratio;
	luz->color.r = color->r;
	luz->color.g = color->g;
	luz->color.b = color->b;
	aux->next = luz;
}

void	trocar_lista_original_pela_versao_python(t_data *data)
{
	t_token			*camera_token;

	data->lights_size = 5;
	data->objects_size = 12;
	data->win_width = 800;
	data->win_height = 600;
	token_clear(&data->tokens);
	camera_token = ft_calloc(1, sizeof(t_token));
	if (!camera_token)
		exit_error("Error at create scene\n", 4, data);
	pass_tuple_values(&camera_token->coordinate, &(t_tuple){0.0, 5.0, -8.0, 1});
	pass_tuple_values(&camera_token->normalized_3d_direction, &(t_tuple){0, 0, 0, 1});
	camera_token->type = CAMERA;
	data->tokens = camera_token;
	adicionar_esfera(&data->tokens, &(t_tuple){0, 0, 20, 0}, 4, &(t_color){255, 125, 125});
	adicionar_esfera(&data->tokens, &(t_tuple){2.5, 2.8, 5.15, 0}, 2.8, &(t_color){83, 221, 108});
	adicionar_esfera(&data->tokens, &(t_tuple){0.6, 5.6, 3.6, 0}, 1.2, &(t_color){128, 117, 255});
	adicionar_esfera(&data->tokens, &(t_tuple){-3.1, 1.4, 0.06, 0}, 1.6, &(t_color){128, 117, 255});
	adicionar_esfera(&data->tokens, &(t_tuple){-4.2, 5.4, 4.2, 0}, 1.8, &(t_color){83, 221, 108});
	adicionar_esfera(&data->tokens, &(t_tuple){0, -1000000, 0, 0}, 1000000, &(t_color){234, 234, 234});
	adicionar_luz(&data->tokens, &(t_tuple){-1.3, 8.4, 0}, 1);
	adicionar_luz_ambiente(&data->tokens, &(t_color){26, 27, 33}, 0.2);
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

	data->win_width = 1000;
	data->win_height = 700;
	// trocar_lista_original_pela_versao_python(data);
	scene = alloc_scene(data->lights_size, data->objects_size);
	if (!scene)
		exit_error("Error at create scene\n", 4, data);
	define_objects(&scene, data);
	data->scene = scene;
}
