/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:09:10 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/03 09:49:34 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_tuple ray_position(t_ray *ray, double time)
{
	t_tuple direction;
	t_tuple position;

	direction = multiply_tuple(&ray->direction, time);
	position = sum_tuples(&direction, &ray->origin);
	// printf("Começa daqui\n");
	// if (ray->direction.w == 1 || ray->direction.w == 0)
	// {
	// 	print_tuple(&ray->direction);
	// 	print_tuple(&ray->origin);
	// }
	return (position);
}

t_HIT	*init_HIT(t_token *object, t_tuple *normal, double distance, t_tuple *position)
{
	t_HIT *hit;

	hit = ft_calloc(1, sizeof(t_HIT));
	pass_tuple_values(&hit->position, position);
	pass_tuple_values(&hit->normal, normal);
	hit->object = object;
	hit->distance = distance;
	return (hit);
}

t_HIT	*intersect_sphere(t_token *sphere, t_ray *ray)
{
	t_HIT	*hit;
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

	if (!ray || !sphere)
		return (NULL);
	hit = NULL;
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
		if (bhaskara_1 > 0 || bhaskara_2 > 0)
		{
			if (bhaskara_1 < bhaskara_2)
				bhaskara_result = bhaskara_1;
			else
				bhaskara_result = bhaskara_2;
			distance = bhaskara_result;
			hit_point = ray_position(ray, distance);
			normal = subtract_tuples(&hit_point, &sphere->coordinate);
			normalize_tuple(&normal);
			hit = init_HIT(sphere, &normal, distance, &hit_point);
			return (hit);
		}
	}
	return (hit);
}
