/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:37:31 by gsmereka          #+#    #+#             */
/*   Updated: 2024/01/19 01:23:59 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

double	fov_to_focal_length(double fov)
{
	double	fov_in_radians;
	double	focal_length;

	fov_in_radians = fov * M_PI / 180.0;
	focal_length = 1.0 / (2.0 * tan(fov_in_radians / 2.0));
	return (focal_length);
}

t_tuple	define_front_vector(t_tuple *normalized_3d_direction)
{
	t_tuple	front;

	front = (t_tuple){0};
	pass_tuple_values(&front, normalized_3d_direction);
	return (front);
}

t_tuple	define_right_vector(t_tuple *front)
{
	t_tuple	right;
	t_tuple	arbitrary;

	arbitrary = create_vector(0, 1, 0);
	right = cross_product(front, &arbitrary);
	if (are_tuples_equal(&right, &(t_tuple){0, 0, 0, 0}))
	{
		if (front->y <= 0)
			right = create_vector(0, 0, 1);
		else
			right = create_vector(0, 0, -1);
	}
	normalize_tuple(&right);
	return (right);
}

t_tuple	define_up_vector(t_tuple *front, t_tuple *right, double aspect_ratio)
{
	t_tuple	up;

	up = cross_product(right, front);
	up = multiply_tuple(&up, aspect_ratio);
	return (up);
}

t_camera	*init_camera(t_token *token, t_data *data)
{
	t_camera	*camera;

	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		return (NULL);
	pass_tuple_values(&camera->center, &token->coordinate);
	camera->width = data->win_width;
	camera->height = data->win_height;
	camera->focal_length = fov_to_focal_length(token->fov);
	camera->aspect_ratio = (double)camera->height / (double)camera->width;
	camera->front = define_front_vector(&token->normalized_3d_direction);
	camera->right = define_right_vector(&camera->front);
	camera->up = define_up_vector(&camera->front, &camera->right,
			camera->aspect_ratio);
	return (camera);
}
