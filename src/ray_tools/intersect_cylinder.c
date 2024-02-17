/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:53:06 by gsmereka          #+#    #+#             */
/*   Updated: 2024/02/17 19:35:52 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

double	calculate_discriminant(t_intersect *intersect,
	t_token *cylinder, t_ray *ray)
{
	double	d;
	t_tuple	distance_to_center;
	t_tuple	cylinder_center;

	cylinder_center = cylinder->coordinate;
	distance_to_center = subtract_tuples(&ray->origin, &cylinder_center);
	intersect->a = dot_product(&ray->direction, &ray->direction) - \
		pow(dot_product(&ray->direction, &cylinder->normalized_3d_direction), 2);
	intersect->b = 2.0 * dot_product(&distance_to_center, &ray->direction) - \
		dot_product(&ray->direction, &cylinder->normalized_3d_direction) * \
		dot_product(&distance_to_center, &cylinder->normalized_3d_direction); //ao contrario as tuplas no 1 dot product?
	intersect->c = dot_product(&distance_to_center, &distance_to_center) - \
		pow(dot_product(&distance_to_center, &cylinder->normalized_3d_direction), 2) - \
		pow(cylinder->diameter/2, 2);
	d = (intersect->b * intersect->b) - (4 * intersect->a * intersect->c);
	return (d);
}

double	calculate_cylinder_distance(t_token *cylinder, t_ray *ray)
{
	t_intersect	intersect;
	double		discriminant;
	double		distance;

	intersect = (t_intersect){0};
	discriminant = calculate_discriminant(&intersect, cylinder, ray);
	if (discriminant <= 0)
		return (0);
	intersect.solutions[0]
		= (-intersect.b - sqrt(discriminant)) / (2 * intersect.a);
	intersect.solutions[1]
		= (-intersect.b + sqrt(discriminant)) / (2 * intersect.a);

	//fmin e fmax?

	if (intersect.solutions[0] <= 0 && intersect.solutions[1] <= 0)
		return (0);
	// if (intersect.solutions[0] < intersect.solutions[1])
	// 	distance = intersect.solutions[0];
	// else
	// 	distance = intersect.solutions[1];
	if (intersect.solutions[0] >= 0)
		distance = intersect.solutions[0];
	else
		distance = intersect.solutions[1];
	return (distance);
}

t_tuple	calculate_cylinder_normal(t_token *cylinder, t_tuple *hit_point)
{
	t_tuple	oc;
	t_tuple	direction;
	t_tuple	projection;
	t_tuple	on_cylinder;

	oc = subtract_tuples(hit_point, &cylinder->coordinate);
	direction = cylinder->normalized_3d_direction;
	projection = multiply_tuple(&direction, dot_product(&oc, &direction));
	on_cylinder = subtract_tuples(&oc, &projection);
	normalize_tuple(&on_cylinder);
	return (on_cylinder);
}

t_hit	*intersect_cylinder(t_token *cylinder, t_ray *ray)
{
	double	distance;
	t_tuple	hit_point;
	t_tuple	normal;
	t_hit	*hit;

	distance = calculate_cylinder_distance(cylinder, ray);
	if (!distance)
		return (NULL);
	hit_point = ray_position(ray, distance);  
	normal = calculate_cylinder_normal(cylinder, &hit_point);
	hit = init_hit(cylinder, &normal, distance, &hit_point);
	return (hit);
}
