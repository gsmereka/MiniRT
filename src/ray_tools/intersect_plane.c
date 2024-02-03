/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:53:06 by gsmereka          #+#    #+#             */
/*   Updated: 2024/02/03 23:08:16 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

double	calculate_plane_distance(t_token *plane, t_ray *ray) //sera?
{
	t_tuple	plane_to_ray;
	double	numerator;
	double	denominator;
	double	distance;

	plane_to_ray = subtract_tuples(&ray->origin, &plane->coordinate);
	numerator = dot_product(&plane_to_ray, &plane->normalized_3d_direction);
	denominator = dot_product(&ray->direction, &plane->normalized_3d_direction);
	if (fabs(denominator) < EPSILON) //aq ja checa o 0
		return (0);
	distance = -(numerator/denominator);
	if (distance < 0)
		return (0);
	return (distance);
}

t_hit	*intersect_plane(t_token *plane, t_ray *ray) //esse primeiro   // e se ficar fininho de lado???? aparece oq //e plano infinito? tem?
{
	double	distance;
	t_tuple	hit_point;
	t_tuple	normal;
	t_tuple	reverse_normal;
	t_hit	*hit;

	distance = calculate_plane_distance(plane, ray);
	if (!distance)
		return (NULL);
	hit_point = ray_position(ray, distance);
	// normal = subtract_tuples(&hit_point, &plane->coordinate); //oq isso significa? //ou a normal seria só a coordenada normalizada do plano?
	// normalize_tuple(&normal); //precisa? testar sem   
	normal = plane->normalized_3d_direction;
	if (dot_product(&normal, &ray->direction) > 0)
	{
		reverse_normal = reverse_tuple(&normal); //n precisa normalizar dnv né?
		hit = init_hit(plane, &reverse_normal, distance, &hit_point);
	}
	else
		hit = init_hit(plane, &normal, distance, &hit_point);
	return (hit);
}
