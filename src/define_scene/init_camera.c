/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:37:31 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/23 18:44:17 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_tuple	multiply_tuple_by_matrix(t_tuple *tuple, t_matrix *matrix)
{
	t_tuple	result;

	result.x = tuple->x * matrix->content[0][0]
		+ tuple->y * matrix->content[1][0]
		+ tuple->z * matrix->content[2][0] + tuple->w * matrix->content[3][0];
	result.y = tuple->x * matrix->content[0][1]
		+ tuple->y * matrix->content[1][1]
		+ tuple->z * matrix->content[2][1] + tuple->w * matrix->content[3][1];
	result.z = tuple->x * matrix->content[0][2]
		+ tuple->y * matrix->content[1][2]
		+ tuple->z * matrix->content[2][2] + tuple->w * matrix->content[3][2];
	result.w = tuple->x * matrix->content[0][3]
		+ tuple->y * matrix->content[1][3]
		+ tuple->z * matrix->content[2][3] + tuple->w * matrix->content[3][3];
	return (result);
}

double	degrees_to_radians(double degrees)
{
	return (degrees * M_PI / 180.0);
}


double	vector_to_radians(double input)
{
	return (atan(input));
}


t_camera	*init_camera(t_token *token, t_data *data)
{
	t_camera	*camera;
	t_matrix	rot_x;
	t_matrix	rot_y;
	t_matrix	rot_z;

	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		return (NULL);
	pass_tuple_values(&camera->center, &token->coordinate);
	camera->width = data->win_width;
	camera->height = data->win_height;
	if (data->test)
	{
		printf("Caindo aqui init_camera.c - set_camera - test=1\n");
		camera->radians_vector.x = degrees_to_radians(token->normalized_3d_direction.x);
		camera->radians_vector.y = degrees_to_radians(token->normalized_3d_direction.y);
		camera->radians_vector.z = degrees_to_radians(token->normalized_3d_direction.z);
	}
	else
	{
		printf("Caindo aqui init_camera.c - set_camera - test=0\n");
		camera->radians_vector.x = vector_to_radians(token->normalized_3d_direction.x);
		camera->radians_vector.y = vector_to_radians(token->normalized_3d_direction.y);
		camera->radians_vector.z = vector_to_radians(token->normalized_3d_direction.z);
	}
	camera->focal_length = 0.7;
	// camera->fov = token->fov;
	rot_x = rotation_x(data, camera->radians_vector.x);
	rot_y = rotation_y(data, camera->radians_vector.y);
	rot_z = rotation_z(data, camera->radians_vector.z);
	camera->direction = multiply_matrices(&rot_x, &rot_y);
	camera->direction = multiply_matrices(&rot_z, &camera->direction);
	camera->right = multiply_tuple_by_matrix(&(t_tuple){1, 0, 0, 1}, &camera->direction);
	camera->up = multiply_tuple_by_matrix(&(t_tuple){0, 1, 0, 1}, &camera->direction);
	camera->front = multiply_tuple_by_matrix(&(t_tuple){0, 0, 1, 1}, &camera->direction);
	return (camera);
}
