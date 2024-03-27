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

static t_tuple	get_cap_position(t_token *cylinder, int cap_signal);
static t_token	get_cap_token(t_token *cylinder, t_ray *ray);

t_hit	*intersect_cap(t_token *cylinder, t_ray *ray)
{
	t_token		final_cap;
	t_hit		*hit;
	double		distance;

	final_cap = get_cap_token(cylinder, ray);
	hit = intersect_plane(&final_cap, ray);
	if (hit)
	{
		distance = distance_two_points(&hit->position, &final_cap.coordinate);
		if ((distance - cylinder->radius) <= EPSILON)
		{
			hit->object = cylinder;
			return (hit);
		}
		free(hit);
	}
	return (NULL);
}

static t_token	get_cap_token(t_token *cylinder, t_ray *ray)
{
	double		distance;
	double		distance2;
	t_tuple		cap;
	t_tuple		cap2;
	t_token		final_cap;

	cap = get_cap_position(cylinder, 1);
	cap2 = get_cap_position(cylinder, -1);
	distance = distance_two_points(&cap, &ray->origin);
	distance2 = distance_two_points(&cap2, &ray->origin);
	final_cap = (t_token){0};
	if (distance <= distance2)
		pass_tuple_values(&final_cap.coordinate, &cap);
	else
		pass_tuple_values(&final_cap.coordinate, &cap2);
	pass_tuple_values(&final_cap.normalized_3d_direction,
		&cylinder->normalized_3d_direction);
	return (final_cap);
}

static t_tuple	get_cap_position(t_token *cylinder, int cap_signal)
{
	t_tuple	cap;
	double	x;
	double	y;
	double	z;

	x = (cylinder->normalized_3d_direction.x
			* cap_signal * cylinder->height / 2) + cylinder->coordinate.x;
	y = (cylinder->normalized_3d_direction.y * cap_signal
			* cylinder->height / 2) + cylinder->coordinate.y;
	z = (cylinder->normalized_3d_direction.z
			* cap_signal * cylinder->height / 2) + cylinder->coordinate.z;
	cap = create_point(x, y, z);
	return (cap);
}
