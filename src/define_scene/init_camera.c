/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:37:31 by gsmereka          #+#    #+#             */
/*   Updated: 2023/12/04 19:47:03 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

// static t_tuple	multiply_tuple_by_matrix(t_tuple *tuple, t_matrix *matrix);

double	fov_to_focal_length(double fov)
{
	double	fov_in_radians;
	double	focal_length;

	fov_in_radians = fov * M_PI / 180.0;
	focal_length = 1.0 / (2.0 * tan(fov_in_radians / 2.0));
	return (focal_length);
}

// double	degrees_to_radians(double degree)
// {
// 	return ((degree / 180) * M_PI);
// }

t_camera	*init_camera(t_token *token, t_data *data)
{
	t_camera	*camera;
	t_tuple		arbitrary;

	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		return (NULL);
	pass_tuple_values(&camera->center, &token->coordinate);
	camera->width = data->win_width;
	camera->height = data->win_height;
	camera->focal_length = fov_to_focal_length(token->fov);
	pass_tuple_values(&camera->front, &token->normalized_3d_direction);
	arbitrary = create_vector(0, 1, 0);
	camera->right = cross_product(&camera->front, &arbitrary);
	if (are_tuples_equal(&camera->right, &(t_tuple){0,0,0,0}))
	{
		if (camera->front.y <= 0)
			camera->right = create_vector(0, 0, 1);
		else
			camera->right = create_vector(0, 0, -1);
	}	
	normalize_tuple(&camera->right);
	camera->up = cross_product(&camera->right, &camera->front);
	return (camera);
}
	// t_tuple	arbitrary;

	// arbitrary = create_vector(0, 1, 0);
	// pass_tuple_values(&camera->front, &token->normalized_3d_direction);
	// camera->right = cross_product(&camera->front, &arbitrary);
	// if (camera->right.x == 0 && camera->right.y == 0 && camera->right.z == 0)
	// {
	// 	camera->right.x += 1;
	// 	camera->right.y += 1;
	// 	camera->right.z += 1;
	// }
	// normalize_tuple(&camera->right);
	// camera->up = cross_product(&camera->right, &camera->front);
	// print_tuple(&camera->up);
	// if (camera->up.x == 1 || camera->up.x == -1)
	// 	camera->up.x *= -1;


	// t_tuple	arbitrary;

	// pass_tuple_values(&camera->front, &token->normalized_3d_direction);
	// if (camera->front.y == 1)
	// 	arbitrary = create_vector(0,0, -1);
	// else if (camera->front.y == -1)
	// 	arbitrary = create_vector(0, 0, 1);
	// else
	// 	arbitrary = create_vector(0, 1, 0);
	// camera->right = cross_product(&camera->front, &arbitrary);
	// normalize_tuple(&camera->right);
	// camera->up = cross_product(&camera->right, &camera->front);

	// t_tuple	arbitrary;

	// arbitrary = create_vector(0, 1, 0);
	// pass_tuple_values(&camera->front, &token->normalized_3d_direction);
	// if (camera->front.y == 1)
	// 	camera->right = create_vector(0,0, -1);
	// else if (camera->front.y == -1)
	// 	camera->right = create_vector(0, 0, 1);
	// else
	// 	camera->right = cross_product(&camera->front, &arbitrary);
	// camera->right = cross_product(&camera->front, &arbitrary);
	// normalize_tuple(&camera->right);
	// camera->up = cross_product(&camera->right, &camera->front);
	// return (camera);

// t_camera	*init_camera2(t_token *token, t_data *data)
// {
// 	t_camera	*camera;
// 	t_matrix	rot_x;
// 	t_matrix	rot_y;
// 	t_matrix	rot_z;

// 	camera = ft_calloc(1, sizeof(t_camera));
// 	if (!camera)
// 		return (NULL);
// 	pass_tuple_values(&camera->center, &token->coordinate);
// 	camera->width = data->win_width;
// 	camera->height = data->win_height;
// 	camera->focal_length = fov_to_focal_length(token->fov);
// 	// prepare_vector(&token->normalized_3d_direction); // como implementar esta função ?
// 	// arbitrary = create_vector(0, -1, 0);
// 	rot_x = rotation_x(data, token->normalized_3d_direction.x);
// 	rot_y = rotation_y(data, token->normalized_3d_direction.y);
// 	rot_z = rotation_z(data, token->normalized_3d_direction.z);
// 	camera->direction = multiply_matrices(&rot_x, &rot_y);
// 	camera->direction = multiply_matrices(&rot_z, &camera->direction);
// 	camera->right = multiply_tuple_by_matrix(&(t_tuple){1, 0, 0, 1}, &camera->direction);
// 	camera->up = multiply_tuple_by_matrix(&(t_tuple){0, 1, 0, 1}, &camera->direction);
// 	camera->front = multiply_tuple_by_matrix(&(t_tuple){0, 0, 1, 1}, &camera->direction);
// 	return (camera);
// }
	// token->normalized_3d_direction.x = degrees_to_radians(token->normalized_3d_direction.x);
	// token->normalized_3d_direction.y = degrees_to_radians(token->normalized_3d_direction.y);
	// token->normalized_3d_direction.z = degrees_to_radians(token->normalized_3d_direction.z);
	// token->normalized_3d_direction.x *= (M_PI / 2);
	// token->normalized_3d_direction.y *= (M_PI / 2);
	// token->normalized_3d_direction.z *= (M_PI / 2);

// t_camera	*init_camera3(t_token *token, t_data *data)
// {
// 	t_camera	*camera;

// 	camera = ft_calloc(1, sizeof(t_camera));
// 	if (!camera)
// 		return (NULL);
// 	pass_tuple_values(&camera->center, &token->coordinate);
// 	camera->width = data->win_width;
// 	camera->height = data->win_height;
// 	camera->focal_length = fov_to_focal_length(token->fov);
// 	t_tuple arbitrary;

// 	arbitrary = create_vector(0, 1, 0);
// 	pass_tuple_values(&camera->front, &token->normalized_3d_direction);

// 	// Verifica se a câmera está apontando diretamente para cima
// 	if (camera->front.y == 1.0)
// 	{
// 		camera->right = create_vector(1, 0, 0);
// 	}
// 	// Verifica se a câmera está apontando diretamente para baixo
// 	else if (camera->front.y == -1.0)
// 	{
// 		// camera->front.y *= -1;  // Inverte a direção
// 		camera->right = create_vector(-1, 0, 0);
// 	}
// 	else
// 	{
// 		camera->right = cross_product(&camera->front, &arbitrary);
// 		normalize_tuple(&camera->right);  // Normaliza apenas se front.y não for -1 ou 1
// 	}

// 	// Normaliza a tupla da camera->up usando o produto vetorial entre camera->right e camera->front
// 	camera->up = cross_product(&camera->right, &camera->front);
// 	return (camera);
// }

// t_camera	*init_camera2(t_token *token, t_data *data)
// {
// 	t_camera	*camera;
// 	// t_matrix	rot_x;
// 	// t_matrix	rot_y;
// 	// t_matrix	rot_z;

// 	camera = ft_calloc(1, sizeof(t_camera));
// 	if (!camera)
// 		return (NULL);
// 	pass_tuple_values(&camera->center, &token->coordinate);
// 	camera->width = data->win_width;
// 	camera->height = data->win_height;
// 	camera->focal_length = fov_to_focal_length(token->fov);
// 	// multiply_tuple(&token->normalized_3d_direction, (M_PI / 2));
// 	// rot_x = rotation_x(data, token->normalized_3d_direction.x);
// 	// rot_y = rotation_y(data, token->normalized_3d_direction.y);
// 	// rot_z = rotation_z(data, token->normalized_3d_direction.z);
// 	// camera->direction = multiply_matrices(&rot_x, &rot_y);
// 	// camera->direction = multiply_matrices(&rot_z, &camera->direction);
// 	// camera->right
// 	// 	= multiply_tuple_by_matrix(&(t_tuple){1, 0, 0, 1}, &camera->direction);
// 	// camera->up
// 	// 	= multiply_tuple_by_matrix(&(t_tuple){0, 1, 0, 1}, &camera->direction);
// 	// camera->front
// 	// 	= multiply_tuple_by_matrix(&(t_tuple){0, 0, 1, 1}, &camera->direction);

// 	t_tuple	arbitrary;

// 	arbitrary = create_vector(0, 1, 0);
// 	pass_tuple_values(&camera->front, &token->normalized_3d_direction);
// 	camera->right = cross_product(&camera->front, &arbitrary);
// 	normalize_tuple(&camera->right);
// 	camera->up = cross_product(&camera->right, &camera->front);
// 	// camera->up.y *= -1.0;

// 	return (camera);
// }

// static t_tuple	multiply_tuple_by_matrix(t_tuple *tuple, t_matrix *matrix)
// {
// 	t_tuple	result;

// 	result.x = tuple->x * matrix->content[0][0]
// 		+ tuple->y * matrix->content[1][0]
// 		+ tuple->z * matrix->content[2][0] + tuple->w * matrix->content[3][0];
// 	result.y = tuple->x * matrix->content[0][1]
// 		+ tuple->y * matrix->content[1][1]
// 		+ tuple->z * matrix->content[2][1] + tuple->w * matrix->content[3][1];
// 	result.z = tuple->x * matrix->content[0][2]
// 		+ tuple->y * matrix->content[1][2]
// 		+ tuple->z * matrix->content[2][2] + tuple->w * matrix->content[3][2];
// 	result.w = tuple->x * matrix->content[0][3]
// 		+ tuple->y * matrix->content[1][3]
// 		+ tuple->z * matrix->content[2][3] + tuple->w * matrix->content[3][3];
// 	return (result);
// }
