// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   intersect.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/09/08 19:09:29 by gsmereka          #+#    #+#             */
// /*   Updated: 2023/11/03 19:56:38 by gsmereka         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../headers/miniRT.h"

// t_tuple ray_position(t_ray *ray, double time)
// {
// 	t_tuple direction;
// 	t_tuple position;

// 	direction = multiply_tuple(&ray->direction, time);
// 	position = sum_tuples(&direction, &ray->origin);
// 	return (position);
// }

// t_HIT	*init_HIT(t_token *object, t_tuple *normal, double distance, t_tuple *position)
// {
// 	t_HIT *hit;

// 	hit = ft_calloc(1, sizeof(t_HIT));
// 	pass_tuple_values(&hit->position, position);
// 	pass_tuple_values(&hit->normal, normal);
// 	hit->object = object;
// 	hit->distance = distance;
// 	return (hit);
// }

// double	calculate_discriminant(t_intersect *intersect,
// 			t_token *sphere, t_ray *ray);

// t_HIT	*intersect_sphere(t_token *sphere, t_ray *ray)
// {
// 	t_intersect	intersect;
// 	double		discriminant;
// 	double		distance;
// 	t_tuple		hit_point;
// 	t_tuple		normal;
// 	t_HIT		*hit;

// 	intersect = (t_intersect){0};
// 	discriminant = calculate_discriminant(&intersect, sphere, ray);
// 	if (discriminant <= 0) // MENOR E IGUAL OU SO MENOR ?
// 		return (NULL);
// 	intersect.local_times[0]
// 		= (-intersect.b - sqrt(discriminant)) / (2 * intersect.a);
// 	intersect.local_times[1]
// 		= (-intersect.b + sqrt(discriminant)) / (2 * intersect.a);
// 	if (intersect.local_times[0] <= 0 && intersect.local_times[1] <= 0)
// 		return (NULL);
// 	if (intersect.local_times[0] < intersect.local_times[1])
// 		distance = intersect.local_times[0];
// 	else
// 		distance = intersect.local_times[1];
// 	hit_point = ray_position(ray, distance);
// 	normal = subtract_tuples(&hit_point, &sphere->coordinate);
// 	normalize_tuple(&normal);
// 	hit = init_HIT(sphere, &normal, distance, &hit_point);
// 	return (hit);
// }

// double	calculate_discriminant(t_intersect *intersect,
// 	t_token *sphere, t_ray *ray)
// {
// 	double	d;
// 	t_tuple	distance_to_center;
// 	t_tuple	sphere_center;

// 	sphere_center = sphere->coordinate;
// 	intersect->a = dot_product(&ray->direction, &ray->direction);
// 	distance_to_center = subtract_tuples(&ray->origin, &sphere_center);
// 	intersect->b = dot_product(&ray->direction, &distance_to_center) * 2.0;
// 	intersect->c = dot_product(&distance_to_center,
// 			&distance_to_center) - (sphere->ratio * sphere->ratio);
// 	d = (intersect->b * intersect->b) - (4 * intersect->a * intersect->c);
// 	return (d);
// }
