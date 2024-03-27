/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:53:06 by gsmereka          #+#    #+#             */
/*   Updated: 2024/03/26 18:44:57 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static double	calculate_distance_to_hit_cylinder(t_token *cylinder,
					t_ray *ray);
static double	calculate_discriminant(t_intersect *intersect,
					t_token *cylinder, t_ray *ray);
static	t_tuple	normalize_cylinder(t_token *cylinder, t_ray *ray, \
					t_tuple *hit_point);
static float	cylinder_hipotenuse(t_token *cylinder);

t_hit	*intersect_cylinder(t_token *cylinder, t_ray *ray)
{
	double		distance;
	t_tuple		hit_point;
	t_tuple		normal;
	t_hit		*hit;

	distance = calculate_distance_to_hit_cylinder(cylinder, ray);
	if (!distance)
	{
		hit = intersect_cap(cylinder, ray);
		return (hit);
	}
	hit_point = ray_position(ray, distance);
	if ((distance_two_points(&hit_point, &cylinder->coordinate)
			- cylinder_hipotenuse(cylinder)) >= EPSILON)
	{
		hit = intersect_cap(cylinder, ray);
		return (hit);
	}
	normal = normalize_cylinder(cylinder, ray, &hit_point);
	hit = init_hit(cylinder, &normal, distance, &hit_point);
	return (hit);
}

static double	calculate_distance_to_hit_cylinder(t_token *cylinder,
	t_ray *ray)
{
	t_intersect	intersect;
	double		discriminant;
	double		distance;

	intersect = (t_intersect){0};
	discriminant = calculate_discriminant(&intersect, cylinder, ray);
	if (discriminant <= EPSILON || intersect.a < EPSILON)
		return (0);
	intersect.solutions[0]
		= (-intersect.b - sqrt(discriminant)) / (2 * intersect.a);
	intersect.solutions[1]
		= (-intersect.b + sqrt(discriminant)) / (2 * intersect.a);
	if (intersect.solutions[0] < EPSILON && intersect.solutions[1] < EPSILON)
		return (0);
	if (intersect.solutions[0] < intersect.solutions[1])
		distance = intersect.solutions[0];
	else
		distance = intersect.solutions[1];
	return (distance);
}

static double	calculate_discriminant(t_intersect *intersect,
	t_token *cylinder, t_ray *ray)
{
	double	d;
	t_tuple	distance_to_center;

	intersect->a = dot_product(&ray->direction, &ray->direction) - \
		pow(dot_product(&ray->direction,
				&cylinder->normalized_3d_direction), 2);
	distance_to_center = subtract_tuples(&ray->origin, &cylinder->coordinate);
	intersect->b = 2 * (dot_product(&ray->direction, \
			&distance_to_center) - \
			dot_product(&ray->direction, &cylinder->normalized_3d_direction) * \
			dot_product(&distance_to_center,
				&cylinder->normalized_3d_direction));
	intersect->c = dot_product(&distance_to_center, &distance_to_center) - \
		pow(dot_product(&distance_to_center,
				&cylinder->normalized_3d_direction), 2) - \
				cylinder->radius * cylinder->radius;
	d = (intersect->b * intersect->b) - (4 * intersect->a * intersect->c);
	return (d);
}

static	t_tuple	normalize_cylinder(t_token *cylinder,
	t_ray *ray, t_tuple *hit_point)
{
	t_tuple	normal;
	t_tuple	distance;
	t_tuple	v_multiply_by_m;
	double	t;
	double	m;

	t = distance_two_points(hit_point, &ray->origin);
	distance = subtract_tuples(&ray->origin, &cylinder->coordinate);
	m = dot_product(&ray->direction, &cylinder->normalized_3d_direction) * t + \
		dot_product(&distance, &cylinder->normalized_3d_direction);
	distance = subtract_tuples(hit_point, &cylinder->coordinate);
	v_multiply_by_m = multiply_tuple(&cylinder->normalized_3d_direction, m);
	normal = subtract_tuples(&distance, &v_multiply_by_m);
	normalize_tuple(&normal);
	return (normal);
}

static float	cylinder_hipotenuse(t_token *cylinder)
{
	float	c1;
	float	c2;
	float	result;

	c1 = (cylinder->height / 2) * (cylinder->height / 2);
	c2 = (cylinder->radius * cylinder->radius);
	result = sqrt(c1 + c2);
	return (result);
}
