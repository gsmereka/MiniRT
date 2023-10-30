/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   python_ver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:42:37 by gsmereka          #+#    #+#             */
/*   Updated: 2023/10/29 22:36:31 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

t_ray init_ray(t_tuple *origin, t_tuple *direction)
{
	t_ray ray;

	pass_tuple_values(&ray.direction, direction);
	normalize_tuple(&ray.direction);
	pass_tuple_values(&ray.origin, origin);
	return (ray);
}

t_tuple ray_position(t_ray *ray, double time)
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
	camera.direction = multiply_matrices(&rot_x, &rot_y);
    camera.direction = multiply_matrices(&rot_z, &camera.direction);
	// print_matrix(&camera.direction);
	camera.right  = multiply_tuple_by_matrix(&(t_tuple){1, 0, 0, 1}, &camera.direction);
	camera.up     = multiply_tuple_by_matrix(&(t_tuple){0, 1, 0, 1}, &camera.direction);
	camera.front  = multiply_tuple_by_matrix(&(t_tuple){0, 0, 1, 1}, &camera.direction);
	// printf("%f %f %f\n", camera.right.x, camera.right.y, camera.right.z);
	return (camera);
}

//     def get_ray(self, j, i):
//         direction  = self.front * self.focal_length
//         direction += self.right*(j/self.width - 0.5)
//         direction += self.up*(self.height/self.width)*(i/self.height - 0.5)
//         return Ray(self.center, vec3(direction))

//	   direction.x = front.x * focal_length + right.x * (j / width - 0.5) + up.x * (height / width) * (i / height - 0.5);
//     direction.y = front.y * focal_length + right.y * (j / width - 0.5) + up.y * (height / width) * (i / height - 0.5);
//     direction.z = front.z * focal_length + right.z * (j / width - 0.5) + up.z * (height / width) * (i / height - 0.5);

t_ray	*get_ray(t_CAMERA *camera, double j, double i)
{
	static int	g;
	t_ray	*new_ray;
	t_tuple	temp;
	t_tuple	aux;

	new_ray = ft_calloc(1, sizeof(t_ray));

	// direction = self.front * self.focal_length
    new_ray->direction.x = camera->front.x * camera->focal_length;
    new_ray->direction.y = camera->front.y * camera->focal_length;
    new_ray->direction.z = camera->front.z * camera->focal_length;

    // temp = self.right * (j / self.width - 0.5)
    temp.x = camera->right.x * (j / (double)camera->width - 0.50);
    temp.y = camera->right.y * (j / (double)camera->width - 0.50);
    temp.z = camera->right.z * (j / (double)camera->width - 0.50);

    // direction += temp
    new_ray->direction.x += temp.x;
    new_ray->direction.y += temp.y;
    new_ray->direction.z += temp.z;

    // temp = self.up * (self.height / self.width) * (i / self.height - 0.5)
    temp.x = camera->up.x * ((double)camera->height / (double)camera->width) * (i / (double)camera->height - 0.50);
    temp.y = camera->up.y * ((double)camera->height / (double)camera->width) * (i / (double)camera->height - 0.50);
    temp.z = camera->up.z * ((double)camera->height / (double)camera->width) * (i / (double)camera->height - 0.50);

    // direction += temp
    new_ray->direction.x += temp.x;
    new_ray->direction.y += temp.y;
    new_ray->direction.z += temp.z;

	if (!g)
	{
		// printf("new_direction %f %f %f\n", new_ray->direction.x, new_ray->direction.y, new_ray->direction.z);
		// printf("camera %f %f %f\n", camera->front.x, camera->front.y, camera->front.z);
		// printf("camera %f %f %f\n", camera->up.x, camera->up.y, camera->up.z);
		// printf("camera %f %f %f\n", camera->right.x, camera->right.y, camera->right.z);
	}
	g++;
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

t_HIT	intersect_SPHERE(t_token *sphere, t_ray *ray)
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
	// printf("%f\n", a); de vez em quando da um erro de nao inicialização
	// printf("%f\n", c);
	// printf("%f\n", b);
	delta = (b * b) - (4.0 * a * c);
	// if (delta > 0)
	// // {
	// 	sqrt_delta = sqrt(delta);
		// bhaskara_1 = (-b + sqrt_delta)/(2.0 * a);
	// 	bhaskara_2 = (-b - sqrt_delta)/(2.0 * a);
	// 	if (bhaskara_1 < bhaskara_2)
	// 		bhaskara_result = bhaskara_1;
	// 	else
	// 		bhaskara_result = bhaskara_2;
	// 	if(bhaskara_result > 0)
	// 	{
	// 		distance = bhaskara_result;
	// 		hit_point = ray_position(ray, distance);
	// 		normal = subtract_tuples(&hit_point, &sphere->coordinate);
	// 		normalize_tuple(&normal);
	// 		hit = init_HIT(sphere, &normal, distance, &hit_point);
	// 		hit.valid = 1;
	// 		return (hit);
	// 	}
	// }
	return (hit);
}

t_HIT	intersect_SPHERE2(t_token *sphere, t_ray *ray)
{
	t_intersect	*inter;
	double		closest;
	t_tuple		hit_point;
	t_tuple		normal;
	t_HIT		hit;

	hit = (t_HIT){0};
	inter = intersect_2(sphere, ray);
	free(inter);
	// if (inter.local_times[0] < inter.local_times[1])
	// 	closest = inter.local_times[0];
	// else
	// 	closest = inter.local_times[1];
	// if (closest < 0)
	// 	return (hit);
	// hit_point = ray_position(ray, closest);
	// normal = subtract_tuples(&hit_point, &sphere->coordinate);
	// normalize_tuple(&normal);
	// hit = init_HIT(sphere, &normal, closest, &hit_point);
	// hit.valid = 1;
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

t_HIT	CLOSEST_HIT(t_SCENE *scene, t_ray *ray)
{
	t_HIT	hit;
	t_HIT	closest_hit;
	int		limit;
	int		i;
	static	int g;

	i = 0;
	closest_hit = (t_HIT){0};
	limit = scene->objetos_a_definir;
	while (i < limit)
	{
		// if (!g)
		// 	printf("%f\n", ray->direction.x);
		// g++;
		hit = intersect_SPHERE(scene->objects[i], ray);
		if (!hit.valid || !closest_hit.valid || hit.distance < closest_hit.distance)
			closest_hit = hit;
		i++;
	}
	return (closest_hit);
}

t_tuple	trace_COLOR(t_SCENE *scene, t_ray *ray)
{
	t_HIT			closest_hit;
	t_ray			light_ray;
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
			light_ray = init_ray(&light_position, &tuple_subtraction);
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
	t_ray			*aux_ray;
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
			aux_ray = get_ray(camera, pixel_coord[0], pixel_coord[i]);
			color = trace_COLOR(scene, aux_ray);
			free(aux_ray);
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
	t_token			*esfera_1;
	t_token			*esfera_2;
	t_token			*esfera_3;
	t_token			*esfera_4;
	t_token			*esfera_0;

	scene = create_SCENE(&(t_tuple){26, 27, 33, 0}, 0.12);
	scene.luzes_a_definir = 1; // numero a definir;
	scene.objetos_a_definir = 5; // numero a definir;
	camera_token = (t_token){0};
	camera_token.coordinate = (t_tuple){0, 5, -8, 0};
	camera_token.normalized_vector = (t_tuple){-10, 5, 0, 0};
	camera = init_CAMERA(&camera_token, data);
	scene.lights[0] = create_POINTLIGHT(&(t_tuple){-1.3, 8.4, 0, 0}, 20);
	esfera_0 = ft_calloc(1, sizeof(t_token));
	esfera_1 = ft_calloc(1, sizeof(t_token));
	esfera_2 = ft_calloc(1, sizeof(t_token));
	esfera_3 = ft_calloc(1, sizeof(t_token));
	esfera_4 = ft_calloc(1, sizeof(t_token));
	definir_esfera(esfera_0, &(t_tuple){2.5, 2.8, 5.15, 0}, 2.8, &(t_color){83, 221, 108});
	definir_esfera(esfera_1, &(t_tuple){0.6, 5.6, 3.6, 0}, 0.6, &(t_color){128, 117, 255});
	definir_esfera(esfera_2, &(t_tuple){-3.1, 1.4, 0.06, 0}, 1.4, &(t_color){128, 117, 255});
	definir_esfera(esfera_3, &(t_tuple){-4.2, 5.4, 4.2, 0}, 0.9, &(t_color){83, 221, 108});
	definir_esfera(esfera_4, &(t_tuple){0, -1000000, 0, 0}, 1000000, &(t_color){234, 234, 234});
	scene.objects = (t_token **)ft_calloc(scene.objetos_a_definir + 1, sizeof(t_token *));
	scene.objects[0] = esfera_0;
	scene.objects[1] = esfera_1;
	scene.objects[2] = esfera_2;
	scene.objects[3] = esfera_3;
	scene.objects[4] = esfera_4;
	data->camera = camera;
	data->scene = scene;
}
