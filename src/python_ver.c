/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   python_ver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:42:37 by gsmereka          #+#    #+#             */
/*   Updated: 2023/10/28 03:25:21 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

// import pygame
// import math
// import glm
// from glm import vec3


t_RAY init_RAY(t_tuple *origin, t_tuple *direction)
{
	t_RAY ray;

	pass_tuple_values(&ray.direction, direction);
	normalize_tuple(&ray.direction);
	pass_tuple_values(&ray.origin, origin);
	return (ray);
}

t_tuple RAY_position(t_RAY *ray, double time)
{
	t_tuple direction;
	t_tuple position;

	direction = multiply_tuple(&ray->direction, time);
	position = sum_tuples(&direction, &ray->origin);
	return (position);
}


// void multiplyMatrix(int x, int y, int z, int w, int matrix[4][4], int result[4]) {
//     result[0] = x * matrix[0][0] + y * matrix[1][0] + z * matrix[2][0] + w * matrix[3][0];
//     result[1] = x * matrix[0][1] + y * matrix[1][1] + z * matrix[2][1] + w * matrix[3][1];
//     result[2] = x * matrix[0][2] + y * matrix[1][2] + z * matrix[2][2] + w * matrix[3][2];
//     result[3] = x * matrix[0][3] + y * matrix[1][3] + z * matrix[2][3] + w * matrix[3][3];
// }

t_CAMERA	init_CAMERA(t_token *token, t_data *data)
{
	t_CAMERA camera;

	camera = (t_CAMERA){0};
	pass_tuple_values(&camera.center, &token->coordinate);
	camera.width = data->win_width;
	camera.height = data->win_height;
	camera.radians_vector.x = 2.0 * asin(sqrt(token->normalized_vector.x * token->normalized_vector.x + token->normalized_vector.y * token->normalized_vector.y));
	camera.radians_vector.y = atan2(token->normalized_vector.y, token->normalized_vector.x);
	camera.radians_vector.z = asin(token->normalized_vector.z);
	// camera.focal_length = focal_length;
	camera.focal_length = 0.7;
	camera.fov = token->fov;
	camera.direction = copy_matrix(&data->idmatrix_4x4);
	// self.right  = glm.vec4(1, 0, 0, 1) * matrix
	// self.up     = glm.vec4(0, 1, 0, 1) * matrix
	// self.front  = glm.vec4(0, 0, 1, 1) * matrix
	return (camera);
}

// class Camera():
//     def __init__(self, center, euler_angles, width, height, focal_length):
//         self.center = center
//         self.width  = width
//         self.height = height
//         self.focal_length = focal_length
//         euler_angles = glm.radians(euler_angles)
//         matrix = glm.mat4()
//         matrix = glm.rotate(matrix, euler_angles.x, vec3(1, 0, 0))
//         matrix = glm.rotate(matrix, euler_angles.y, vec3(0, 1, 0))
//         matrix = glm.rotate(matrix, euler_angles.z, vec3(0, 0, 1))
//         self.right  = glm.vec4(1, 0, 0, 1) * matrix
//         self.up     = glm.vec4(0, 1, 0, 1) * matrix
//         self.front  = glm.vec4(0, 0, 1, 1) * matrix

//     def get_ray(self, j, i):
//         direction  = self.front * self.focal_length
//         direction += self.right*(j/self.width - 0.5)
//         direction += self.up*(self.height/self.width)*(i/self.height - 0.5)
//         return Ray(self.center, vec3(direction))

t_RAY	get_RAY(t_CAMERA *camera, size_t j, size_t i)
{
	t_RAY	new_ray;

	// new_ray.direction = camera->front *camera.focal_length; // funções erradas
	// new_ray.direction += camera.right * (j / camera.width - 0.5);  // funções erradas
	// new_ray.direction += camera.up * (camera.height / camera.width) * (i / camera.height - 0.5); // funções erradas
	return (init_RAY(&camera->center, &new_ray.direction));
}

t_HIT	init_HIT(t_token *object, t_tuple *normal, size_t distance, t_tuple *position)
{
	t_HIT hit;

	pass_tuple_values(&hit.position, position);
	pass_tuple_values(&hit.normal, normal);
	hit.object = object;
	hit.distance = distance;
	return (hit);
}

t_HIT	intersect_SPHERE(t_token *sphere, t_RAY *ray)
{
	t_HIT	hit;
	size_t	a;
	size_t	b;
	size_t	c;
	size_t	delta;
	t_tuple	s0_p0;
	size_t	sqrt_delta;
	size_t	bhaskara_1;
	size_t	bhaskara_2;
	size_t	bhaskara_result;
	double	distance;
	t_tuple	hit_point;
	t_tuple	normal;

	hit = (t_HIT){0};
	a = dot_product(&ray->direction, &ray->direction);
	s0_p0 = subtract_tuples(&ray->origin, &sphere->coordinate);
	b = 2.0 * dot_product(&ray->direction, &s0_p0);
	c = dot_product(&s0_p0, &s0_p0) - (sphere->ratio * sphere->ratio);
	delta = (b * b) - 4.0 *a * c;
	if (delta > 0)
	{
		sqrt_delta = sqrt(delta);
		bhaskara_1 = (-b + sqrt_delta)/(2.0 * a);
		bhaskara_2 = (-b - sqrt_delta)/(2.0 * a);
		if (bhaskara_1 < bhaskara_2)
			bhaskara_result = bhaskara_1;
		else
			bhaskara_result = bhaskara_2;
		if(bhaskara_result > 0)
		{
			distance = bhaskara_result;
			hit_point = RAY_position(ray, distance);
			normal = subtract_tuples(&hit_point, &sphere->coordinate);
			normalize_tuple(&normal);
			hit = init_HIT(sphere, &normal, distance, &hit_point);
			hit.valid = 1;
			return (hit);
		}
	}
	return (hit);
}

t_POINTLIGHT create_POINTLIGHT(t_tuple *position, size_t intensity)
{
	t_POINTLIGHT	light;

	pass_tuple_values(&light.position, position);
	light.intensity = intensity;
	return (light);
}

size_t LIGHT_at(t_POINTLIGHT *light, t_HIT *hit)
{
	t_tuple	direction;
	size_t	distance;
	size_t	cos_theta;
	size_t	result;

	direction = subtract_tuples(&light->position, &hit->position);
	distance = tuple_magnitude(&direction);
	normalize_tuple(&direction);
	cos_theta = dot_product(&direction, &hit->normal);
	result = light->intensity * (cos_theta / (distance * distance));
	if (are_floats_equal(0, result))
		return (result);
	if (result < 0);
		return (0);
	return (result);
}


t_SCENE	create_SCENE(t_tuple *background, size_t ambient_light)
{
	t_SCENE	scene;

	scene = (t_SCENE){0};
	pass_tuple_values(&scene.background, background);
	scene.ambient_light = ambient_light;
	return (scene);
}

t_HIT	CLOSEST_HIT(t_SCENE *scene, t_RAY *ray)
{
	t_HIT	hit;
	t_HIT	closest_hit;
	int		limit;
	int		i;

	i = 0;
	closest_hit = (t_HIT){0};
	limit = scene->objetos_a_definir;
	while (i < limit)
	{
		hit = intersect_SPHERE(&scene->objects[i], ray);
		if (!hit.valid || !closest_hit.valid || hit.distance < closest_hit.distance)
			closest_hit = hit;
		i++;
	}
	return (closest_hit);
}

t_tuple	trace_COLOR(t_SCENE *scene, t_RAY *ray)
{
	t_HIT			closest_hit;
	t_RAY			light_ray;
	t_HIT			light_hit;
	t_tuple			result;
	t_tuple			light_position;
	t_tuple			tuple_subtraction;
	size_t			intensity;
	int				i;

	closest_hit = CLOSEST_HIT(scene, ray);
	if (closest_hit.valid)
	{
		intensity = scene->ambient_light;
		i = 0;
		while (i < scene->luzes_a_definir) // numero a definir
		{
			light_position = scene->lights[i].position;
			tuple_subtraction = subtract_tuples(&closest_hit.position, &scene->lights[i].position);
			light_ray = init_RAY(&light_position, &tuple_subtraction);
			light_hit = CLOSEST_HIT(scene, &light_ray);
			if (light_hit.valid && &light_hit.object == &closest_hit.object)
				intensity += LIGHT_at(&scene->lights[i], &closest_hit);
			if (intensity < 1)
				intensity = 1;
			result.x = closest_hit.object->color.r * intensity;
			result.y = closest_hit.object->color.g * intensity;
			result.z = closest_hit.object->color.b * intensity;
			i++;
		}
		return (result);
	}
	return (scene->background);
}

void	RENDER_MASTER(t_SCENE *scene, t_CAMERA *camera, t_data *data)
{
	int				i;
	int				j;
	t_RAY			aux_ray;
	t_tuple			color;
	unsigned int	final_color;
	int				pixel_coord[2];

	i = 0;
	while (i < camera->height)
	{
		j = 0;
		while (j < camera->width)
		{
			pixel_coord[0] = j + 0.5;
			pixel_coord[1] = camera->height - 0.5 - i;
			aux_ray = get_RAY(camera, pixel_coord[0], pixel_coord[1]);
			color = trace_COLOR(scene, &aux_ray);
			final_color = 0;
			final_color |= ((int)color.x & 0xFF) << 16;  // Adiciona o valor de r ao componente vermelho.
			final_color |= ((int)color.y & 0xFF) << 8;   // Adiciona o valor de g ao componente verde.
			final_color |= ((int)color.z & 0xFF);        // Adiciona o valor de b ao componente azul
			paint_pixel(pixel_coord[0], pixel_coord[1], final_color, data);
			j++;
		}
		i++;
	}
}

void	definir_esfera(t_token *esfera, t_tuple *center, double raio, t_color *color)
{
	pass_tuple_values(&esfera->coordinate, center);
	esfera->color.r = color->r;
	esfera->color.g = color->g;
	esfera->color.b = color->b;
	esfera->ratio = raio;
}

void	define_SCENE(t_data *data)
{
	t_SCENE			scene;
	t_CAMERA		camera;
	t_token			camera_token;
	t_token			esfera_1;
	t_token			esfera_2;
	t_token			esfera_3;
	t_token			esfera_4;
	t_token			esfera_0;

	scene = create_SCENE(&(t_tuple){26, 27, 33, 0}, 0.12);
	scene.luzes_a_definir = 1; // numero a definir;
	scene.objetos_a_definir = 5; // numero a definir;
	camera_token = (t_token){0};
	camera_token.coordinate = (t_tuple){0, 5, -8, 0};
	camera_token.normalized_vector = (t_tuple){-10, 5, 0, 0};
	camera = init_CAMERA(&camera_token, data);
	scene.lights[0] = create_POINTLIGHT(&(t_tuple){-1.3, 8.4, 0, 0}, 20);
	definir_esfera(&esfera_0, &(t_tuple){2.5, 2.8, 5.15, 0}, 2.8, &(t_color){83, 221, 108});
	definir_esfera(&esfera_1, &(t_tuple){0.6, 5.6, 3.6, 0}, 0.6, &(t_color){128, 117, 255});
	definir_esfera(&esfera_2, &(t_tuple){-3.1, 1.4, 0.06, 0}, 1.4, &(t_color){128, 117, 255});
	definir_esfera(&esfera_3, &(t_tuple){-4.2, 5.4, 4.2, 0}, 0.9, &(t_color){83, 221, 108});
	definir_esfera(&esfera_4, &(t_tuple){0, -1000000, 0, 0}, 1000000, &(t_color){234, 234, 234});
	scene.objects[0] = esfera_0;
	scene.objects[1] = esfera_1;
	scene.objects[2] = esfera_2;
	scene.objects[3] = esfera_3;
	scene.objects[4] = esfera_4;
	data->camera = camera;
	data->scene = scene;
}




//     sphere1 = Sphere(vec3(2.5, 2.8, 5.15), 2.8, vec3(83, 221, 108))
//     scene.objects.append(sphere1)

//     sphere2 = Sphere(vec3(0.6, 5.6, 3.6), 0.6, vec3(128, 117, 255))
//     scene.objects.append(sphere2)

//     sphere3 = Sphere(vec3(-3.1, 1.4, 0.06), 1.4, vec3(128, 117, 255))
//     scene.objects.append(sphere3)

//     sphere4 = Sphere(vec3(-4.2, 5.4, 4.2), 0.9, vec3(83, 221, 108))
//     scene.objects.append(sphere4)

//     sphere5 = Sphere(vec3(0, -1000000, 0), 1000000, vec3(234, 234, 234))
//     scene.objects.append(sphere5)

//     render(scene, camera)