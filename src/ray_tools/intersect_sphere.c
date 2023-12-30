/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:09:29 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/23 18:11:09 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static double	calculate_distance(t_token *sphere, t_ray *ray);
static double	calculate_discriminant(t_intersect *intersect,
					t_token *sphere, t_ray *ray);

t_hit	*intersect_sphere(t_token *sphere, t_ray *ray)
{
	double		distance;
	t_tuple		hit_point;
	t_tuple		normal;
	t_hit		*hit;

	distance = calculate_distance(sphere, ray);
	if (!distance)
		return (NULL);
	hit_point = ray_position(ray, distance);
	normal = subtract_tuples(&hit_point, &sphere->coordinate);
	normalize_tuple(&normal);
	hit = init_hit(sphere, &normal, distance, &hit_point);
	return (hit);
}

double	calculate_distance(t_token *sphere, t_ray *ray)
{
	t_intersect	intersect;
	double		discriminant;
	double		distance;

	intersect = (t_intersect){0};
	discriminant = calculate_discriminant(&intersect, sphere, ray);
	if (discriminant <= 0)
		return (0);
	intersect.solutions[0]
		= (-intersect.b - sqrt(discriminant)) / (2 * intersect.a);
	intersect.solutions[1]
		= (-intersect.b + sqrt(discriminant)) / (2 * intersect.a);
	if (intersect.solutions[0] <= 0 && intersect.solutions[1] <= 0)
		return (0);
	if (intersect.solutions[0] < intersect.solutions[1])
		distance = intersect.solutions[0];
	else
		distance = intersect.solutions[1];
	return (distance);
}

double	calculate_discriminant(t_intersect *intersect,
	t_token *sphere, t_ray *ray)
{
	double	d;
	t_tuple	distance_to_center;
	t_tuple	sphere_center;

	sphere_center = sphere->coordinate;
	intersect->a = dot_product(&ray->direction, &ray->direction);
	distance_to_center = subtract_tuples(&ray->origin, &sphere_center);
	intersect->b = dot_product(&ray->direction, &distance_to_center) * 2.0;
	intersect->c = dot_product(&distance_to_center, &distance_to_center)
		- ((sphere->diameter / 2.0) * (sphere->diameter / 2.0));
	d = (intersect->b * intersect->b) - (4 * intersect->a * intersect->c);
	return (d);
}
