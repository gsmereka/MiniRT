/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:42:37 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/03 09:33:46 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_tuple	multiply_tuple_by_matrix(t_tuple *tuple, t_matrix *matrix)
{
	t_tuple result;

	result.x = tuple->x * matrix->content[0][0] + tuple->y * matrix->content[1][0] + tuple->z * matrix->content[2][0] + tuple->w * matrix->content[3][0];
	result.y = tuple->x * matrix->content[0][1] + tuple->y * matrix->content[1][1] + tuple->z * matrix->content[2][1] + tuple->w * matrix->content[3][1];
	result.z = tuple->x * matrix->content[0][2] + tuple->y * matrix->content[1][2] + tuple->z * matrix->content[2][2] + tuple->w * matrix->content[3][2];
	result.w = tuple->x * matrix->content[0][3] + tuple->y * matrix->content[1][3] + tuple->z * matrix->content[2][3] + tuple->w * matrix->content[3][3];
	return (result);
}

double degrees_to_radians(double degrees)
{
    return (degrees * M_PI / 180.0);
}

t_CAMERA	*init_CAMERA(t_token *token, t_data *data)
{
	t_CAMERA	*camera;
	t_matrix	rot_x;
	t_matrix	rot_y;
	t_matrix	rot_z;

	camera = ft_calloc(1, sizeof(t_CAMERA));
	if (!camera)
		return (NULL);
	pass_tuple_values(&camera->center, &token->coordinate);
	camera->width = data->win_width;
	camera->height = data->win_height;
	// printf("%f, %f, %f\n", token->normalized_vector.x, token->normalized_vector.y, token->normalized_vector.z);
	camera->radians_vector.x = degrees_to_radians(token->normalized_vector.x);
	camera->radians_vector.y = degrees_to_radians(token->normalized_vector.y);
	camera->radians_vector.z = degrees_to_radians(token->normalized_vector.z);
	// camera->radians_vector.x = 2.0 * asin(sqrt(token->normalized_vector.x * token->normalized_vector.x + token->normalized_vector.y * token->normalized_vector.y));
	// camera->radians_vector.y = atan2(token->normalized_vector.y, token->normalized_vector.x);
	// camera->radians_vector.z = asin(token->normalized_vector.z);
	// camera->focal_length = focal_length;
	camera->focal_length = 0.7;
	camera->fov = token->fov;
	rot_x = rotation_x(data, camera->radians_vector.x);
	rot_y = rotation_y(data, camera->radians_vector.y);
	rot_z = rotation_z(data, camera->radians_vector.z);
	camera->direction = multiply_matrices(&rot_x, &rot_y);
    camera->direction = multiply_matrices(&rot_z, &camera->direction);
	// print_matrix(&camera->direction);
	camera->right  = multiply_tuple_by_matrix(&(t_tuple){1, 0, 0, 1}, &camera->direction);
	camera->up     = multiply_tuple_by_matrix(&(t_tuple){0, 1, 0, 1}, &camera->direction);
	camera->front  = multiply_tuple_by_matrix(&(t_tuple){0, 0, 1, 1}, &camera->direction);
	// print_tuple(&camera->right);
	// print_tuple(&camera->up);
	// print_tuple(&camera->front);
	return (camera);
}

t_POINTLIGHT *create_POINTLIGHT(t_tuple *position, double intensity)
{
	t_POINTLIGHT	*light;
	t_tuple			point;

	light = ft_calloc(1, sizeof(t_POINTLIGHT));
	if (!light)
		return (NULL);
	point = create_point(position->x, position->y, position->z);
	pass_tuple_values(&light->position, &point);
	light->intensity = intensity;
	return (light);
}

t_SCENE	*create_SCENE(t_tuple *background, double ambient_light)
{
	t_SCENE	*scene;

	scene = ft_calloc(1, sizeof(t_SCENE));
	if (!scene)
		return (NULL);
	pass_tuple_values(&scene->background, background);
	scene->background.w = 0;
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

void	trocar_lista_original_pela_versao_python(t_data *data)
{
	t_token			*camera_token;

	token_clear(&data->tokens);
	camera_token = ft_calloc(1, sizeof(t_token));
	if (!camera_token)
		exit_error("Error at create scene\n", 4, data);
	pass_tuple_values(&camera_token->coordinate, &(t_tuple){0.0, 5.0, -8.0, 1});
	pass_tuple_values(&camera_token->normalized_vector, &(t_tuple){-10, 5, 0, 0});
	camera_token->type = CAMERA;
	data->tokens = camera_token;
	adicionar_esfera(&data->tokens, &(t_tuple){2.5, 2.8, 5.15, 0}, 2.8, &(t_color){83, 221, 108});
	adicionar_esfera(&data->tokens, &(t_tuple){0.6, 5.6, 3.6, 0}, 0.6, &(t_color){128, 117, 255});
	adicionar_esfera(&data->tokens, &(t_tuple){-3.1, 1.4, 0.06, 0}, 1.4, &(t_color){128, 117, 255});
	adicionar_esfera(&data->tokens, &(t_tuple){-4.2, 5.4, 4.2, 0}, 0.9, &(t_color){83, 221, 108});
	adicionar_esfera(&data->tokens, &(t_tuple){0, -1000000, 0, 0}, 1000000, &(t_color){234, 234, 234});
}

void	define_objects(t_SCENE *scene, t_data *data)
{
	t_token	*aux;
	int		objects;

	aux = data->tokens;
	objects = 0;
	while (aux)
	{
		if (aux->type == 1 || aux->type == 2 || aux->type == 3)
		{
			scene->objects[objects] = aux;
			objects++;
		}
		if (aux->type == 4)
			data->camera = init_CAMERA(data->tokens, data);
		aux = aux->next;
	}
}

void	define_SCENE(t_data *data)
{
	t_SCENE			*scene;

	trocar_lista_original_pela_versao_python(data);
	scene = create_SCENE(&(t_tuple){26, 27, 33, 0}, 0.12);
	if (!scene)
		exit_error("Error at create scene\n", 4, data);
	scene->luzes_a_definir = 1; // numero a definir;
	scene->objetos_a_definir = 5; // numero a definir;
	scene->lights = (t_POINTLIGHT **)ft_calloc(scene->luzes_a_definir + 1, sizeof(t_POINTLIGHT *));
	scene->lights[0] = create_POINTLIGHT(&(t_tuple){-1.3, 8.4, 0.0, 1}, 20);
	scene->objects = (t_token **)ft_calloc(scene->objetos_a_definir + 1, sizeof(t_token *));
	define_objects(scene, data);
	data->scene = scene;
}
