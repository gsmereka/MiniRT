/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   python_ver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:42:37 by gsmereka          #+#    #+#             */
/*   Updated: 2023/10/28 19:46:17 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

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

t_CAMERA	init_CAMERA(t_token *token, t_data *data)
{
	t_CAMERA	camera;
	t_matrix	rot_x;
	t_matrix	rot_y;
	t_matrix	rot_z;

	camera = (t_CAMERA){0};
	pass_tuple_values(&camera.center, &token->coordinate);
	camera.width = data->win_width;
	camera.height = data->win_height;
	printf("%f, %f, %f\n", token->normalized_vector.x, token->normalized_vector.y, token->normalized_vector.z);
	camera.radians_vector.x = degrees_to_radians(token->normalized_vector.x);
	camera.radians_vector.y = degrees_to_radians(token->normalized_vector.y);
	camera.radians_vector.z = degrees_to_radians(token->normalized_vector.z);
	// camera.radians_vector.x = 2.0 * asin(sqrt(token->normalized_vector.x * token->normalized_vector.x + token->normalized_vector.y * token->normalized_vector.y));
	// camera.radians_vector.y = atan2(token->normalized_vector.y, token->normalized_vector.x);
	// camera.radians_vector.z = asin(token->normalized_vector.z);
	// camera.focal_length = focal_length;
	camera.focal_length = 0.7;
	camera.fov = token->fov;
	rot_x = rotation_x(data, camera.radians_vector.x);
	rot_y = rotation_y(data, camera.radians_vector.y);
	rot_z = rotation_z(data, camera.radians_vector.z);
	camera.direction = copy_matrix(&data->idmatrix_4x4);
    camera.direction = multiply_matrices(&rot_x, &camera.direction);
    camera.direction = multiply_matrices(&rot_y, &camera.direction);
    camera.direction = multiply_matrices(&rot_z, &camera.direction);
	// print_matrix(&camera.direction);
	camera.right  = multiply_matrix_with_tuple(&camera.direction, &(t_tuple){1, 0, 0, 1});
	camera.up     = multiply_matrix_with_tuple(&camera.direction, &(t_tuple){0, 1, 0, 1});
	camera.front  = multiply_matrix_with_tuple(&camera.direction, &(t_tuple){0, 0, 1, 1});
	// printf("%f %f %f\n", camera.right.x, camera.right.y, camera.right.z);
	return (camera);
}

//     def get_ray(self, j, i):
//         direction  = self.front * self.focal_length
//         direction += self.right*(j/self.width - 0.5)
//         direction += self.up*(self.height/self.width)*(i/self.height - 0.5)
//         return Ray(self.center, vec3(direction))

t_RAY	get_RAY(t_CAMERA *camera, double j, double i)
{
	t_RAY	new_ray;
	t_tuple	aux;

	new_ray = (t_RAY){0};
	new_ray.direction = multiply_tuple(&camera->front, camera->focal_length);
	aux = multiply_tuple(&camera->right, (j / camera->width - 0.5));
	new_ray.direction = sum_tuples(&new_ray.direction, &aux);
	aux = multiply_tuple(&camera->up, (camera->height / camera->width) * (i / camera->height - 0.5));
	new_ray.direction = sum_tuples(&new_ray.direction, &aux);
	new_ray = init_RAY(&camera->center, &new_ray.direction);
	return (new_ray);
}

t_HIT	init_HIT(t_token *object, t_tuple *normal, double distance, t_tuple *position)
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
	double	a;
	double	b;
	double	c;
	double	delta;
	t_tuple	s0_p0;
	double	sqrt_delta;
	double	bhaskara_1;
	double	bhaskara_2;
	double	bhaskara_result;
	double	distance;
	t_tuple	hit_point;
	t_tuple	normal;

	hit = (t_HIT){0};
	a = dot_product(&ray->direction, &ray->direction);
	s0_p0 = subtract_tuples(&ray->origin, &sphere->coordinate);
	b = 2.0 * dot_product(&ray->direction, &s0_p0);
	c = dot_product(&s0_p0, &s0_p0) - (sphere->ratio * sphere->ratio);
	delta = (b * b) - (4.0 * a * c);
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

t_POINTLIGHT create_POINTLIGHT(t_tuple *position, double intensity)
{
	t_POINTLIGHT	light;

	light = (t_POINTLIGHT){0};
	pass_tuple_values(&light.position, position);
	light.intensity = intensity;
	return (light);
}

double LIGHT_at(t_POINTLIGHT *light, t_HIT *hit)
{
	t_tuple	direction;
	double	distance;
	double	cos_theta;
	double	result;

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


t_SCENE	create_SCENE(t_tuple *background, double ambient_light)
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
	double			intensity;
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
	while (i < camera->width)
	{
		j = 0;
		while (j < camera->height)
		{
			pixel_coord[0] = j + 0.5;
			pixel_coord[1] = camera->height - 0.5 - i;
			aux_ray = get_RAY(camera, pixel_coord[0], pixel_coord[1]);
			color = trace_COLOR(scene, &aux_ray);
			final_color = 0;
			final_color |= ((int)color.x & 0xFF) << 16;  // Adiciona o valor de r ao componente vermelho.
			final_color |= ((int)color.y & 0xFF) << 8;   // Adiciona o valor de g ao componente verde.
			final_color |= ((int)color.z & 0xFF);        // Adiciona o valor de b ao componente azul
			// paint_pixel(i, j, RED, data);
			paint_pixel(i, j, final_color, data);
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
