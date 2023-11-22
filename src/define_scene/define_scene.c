/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:42:37 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/22 12:30:59 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_scene	*create_scene(t_color *background, double ambient_light)
{
	t_scene	*scene;

	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->object_ray = ft_calloc(1, sizeof(t_ray));
	scene->light_ray = ft_calloc(1, sizeof(t_ray));
	if (!scene->object_ray || !scene->object_ray)
	{
		free(scene->object_ray);
		free(scene->light_ray);
		free(scene);
		return (NULL);
	}
	scene->background.r = background->r;
	scene->background.g = background->g;
	scene->background.b = background->b;
	scene->ambient_light = ambient_light;
	return (scene);
}

void	adicionar_esfera(t_token **list, t_tuple *center, double raio, t_color *color)
{
	t_token	*esfera;
	t_tuple	point;
	t_token	*aux;
	static	int	id;

	aux = *list;
	while (aux && aux->next)
		aux = aux->next;
	esfera = ft_calloc(1, sizeof(t_token));
	point = create_point(center->x, center->y, center->z);
	pass_tuple_values(&esfera->coordinate, &point);
	esfera->color.r = color->r;
	esfera->color.g = color->g;
	esfera->color.b = color->b;
	esfera->ratio = raio;
	esfera->type = SPHERE;
	esfera->id = id;
	id++;
	aux->next = esfera;
}

void	adicionar_luz(t_token **list, t_tuple *coordinate, double brightness)
{
	t_token *luz;
	t_token	*aux;

	aux = *list;
	while (aux && aux->next)
		aux = aux->next;
	luz = ft_calloc(1, sizeof(t_token));
	luz->type = 5;
	luz->brightness = brightness;
	pass_tuple_values(&luz->coordinate, coordinate);
	luz->coordinate.w = 1;
	aux->next = luz;
}

void	trocar_lista_original_pela_versao_python(t_data *data)
{
	t_token			*camera_token;

	data->test = 1;
	data->win_width = 800;
	data->win_height = 600;
	token_clear(&data->tokens);
	camera_token = ft_calloc(1, sizeof(t_token));
	if (!camera_token)
		exit_error("Error at create scene\n", 4, data);
	pass_tuple_values(&camera_token->coordinate, &(t_tuple){0.0, 5.0, -8.0, 1});
	pass_tuple_values(&camera_token->normalized_vector, &(t_tuple){-10, 5, 0, 0});
	camera_token->type = CAMERA;
	data->tokens = camera_token;
	adicionar_esfera(&data->tokens, &(t_tuple){0, 0, 20, 0}, 4, &(t_color){255, 125, 125});
	adicionar_esfera(&data->tokens, &(t_tuple){2.5, 2.8, 5.15, 0}, 2.8, &(t_color){83, 221, 108});
	adicionar_esfera(&data->tokens, &(t_tuple){0.6, 5.6, 3.6, 0}, 1.5, &(t_color){128, 117, 255});
	adicionar_esfera(&data->tokens, &(t_tuple){-3.1, 1.4, 0.06, 0}, 1.4, &(t_color){128, 117, 255});
	adicionar_esfera(&data->tokens, &(t_tuple){-4.2, 5.4, 4.2, 0}, 1.9, &(t_color){83, 221, 108});
	adicionar_esfera(&data->tokens, &(t_tuple){0, -1000000, 0, 0}, 1000000, &(t_color){234, 234, 234});
	adicionar_luz(&data->tokens, &(t_tuple){-1.3, 8.4, 0}, 20);
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
			// printf("aaaaaa\n");
			// print_tuple(&aux->coordinate);
			(*scene)->objects[objects] = aux;
			objects++;
		}
		else if (aux->type == 4)
		{
			// pass_tuple_values(&aux->coordinate, &(t_tuple){0.0, 5.0, -8.0, 1});
			// pass_tuple_values(&aux->normalized_vector, &(t_tuple){-10, 5, 0, 0});
			// data->test = 1;
			data->camera = init_camera(aux, data);
			print_tuple(&aux->coordinate);
			print_tuple(&aux->normalized_vector);
		}
		else if (aux->type == 5)
		{
			(*scene)->lights[lights] = aux;
			lights++;
		}
		else if (aux->type == 6)
		{
			// (*scene)->background = aux->color;
			(*scene)->ambient_light = aux->brightness;
		}
		aux = aux->next;
	}
}

void	define_scene(t_data *data)
{
	t_scene			*scene;

	data->win_width = 800;
	data->win_height = 600;
	adicionar_luz(&data->tokens, &(t_tuple){-1.3, 8.4, 0}, 20);
	// trocar_lista_original_pela_versao_python(data);
	scene = create_scene(&(t_color){26, 27, 33}, 0.12);
	if (!scene)
		exit_error("Error at create scene\n", 4, data);
	scene->luzes_a_definir = 5; // numero a definir;
	scene->objetos_a_definir = 12; // numero a definir;
	scene->lights = (t_token **)ft_calloc(scene->luzes_a_definir + 1, sizeof(t_token *));
	scene->objects = (t_token **)ft_calloc(scene->objetos_a_definir + 1, sizeof(t_token *));
	define_objects(&scene, data);
	data->scene = scene;
	printf("%d %d %d\n", scene->background.r, scene->background.g, scene->background.b);
}
