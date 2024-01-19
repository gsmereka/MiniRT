/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ray_direction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:21:55 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/22 14:28:22 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	calculate_direction(t_ray *ray,
	t_camera *camera, double j, double i)
{
	t_tuple	front;
	t_tuple	up;
	t_tuple	right;

	front = multiply_tuple(&camera->front, camera->focal_length);
	right = multiply_tuple(&camera->right, (j / (double)camera->width - 0.5));
	up = multiply_tuple(&camera->up, camera->aspect_ratio);
	up = multiply_tuple(&up, (i / (double)camera->height - 0.5));
	ray->direction = sum_tuples(&ray->direction, &front);
	ray->direction = sum_tuples(&ray->direction, &right);
	ray->direction = sum_tuples(&ray->direction, &up);
}

t_tuple negate_tuple(const t_tuple *tuple)
{
    t_tuple result;
    result.x = -tuple->x;
    result.y = -tuple->y;
    result.z = -tuple->z;
    result.w = -tuple->w;
    return result;
}

void calculate_direction2(t_ray *ray, t_camera *camera, double j, double i)
{
	double fov = 170;

    // Calcula os componentes do vetor de direção sem considerar o FOV
    t_tuple front = camera->front;
    t_tuple right = multiply_tuple(&camera->right, (j / (double)camera->width - 0.5));
    t_tuple up = multiply_tuple(&camera->up, (i / (double)camera->height - 0.5));

    // Calcula a componente horizontal baseada no ângulo de FOV
    double horizontal_factor = tan(fov * 0.5);
    right = multiply_tuple(&right, horizontal_factor);

    // Calcula a componente vertical baseada no ângulo de FOV
    double vertical_factor = (double)camera->height / (double)camera->width * tan(fov * 0.5);
    up = multiply_tuple(&up, vertical_factor);

    // Soma os vetores calculados para obter a direção final do raio
    ray->direction = sum_tuples(&ray->direction, &front);
    ray->direction = sum_tuples(&ray->direction, &right);
    ray->direction = sum_tuples(&ray->direction, &up);
}

void	calculate_ray_direction(t_ray *ray,
	t_camera *camera, double j, double i)
{
	double	pixel_center_coord[2];

	if (!camera)
		return ;
	pixel_center_coord[0] = camera->width - j - 0.5;	// se não a imagem fica invertida
	pixel_center_coord[1] = camera->height - i - 0.5; // se não a imagem fica de cabeça pra baixo
	pass_tuple_values(&ray->direction, &(t_tuple){0,0,0,0});
	calculate_direction(ray, camera,
		pixel_center_coord[0], pixel_center_coord[1]);
	normalize_ray(ray, &camera->center, &ray->direction);
}
