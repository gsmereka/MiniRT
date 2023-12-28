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

static t_tuple	multiply_tuple_by_matrix(t_tuple *tuple, t_matrix *matrix);
static void update_projection_matrix(t_camera *camera);

double fov_to_focal_length(double fov)
{
    if (fov < 0.0 || fov > 180.0) {
        // Lidar com valores fora do intervalo permitido
        return -1.0; // Ou escolha um valor apropriado para indicar erro
    }

    // Converter FOV para radianos
    double fov_in_radians = fov * M_PI / 180.0;

    // Calcular Distância Focal
    double focal_length = 1.0 / (2.0 * tan(fov_in_radians / 2.0));

    return focal_length;
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
	camera->focal_length = fov_to_focal_length(token->fov);
	token->normalized_3d_direction.x *= (M_PI / 2); // achei esse M_PI / 2 na pura tentativa e erro
	token->normalized_3d_direction.y *= (M_PI / 2);
	token->normalized_3d_direction.z *= (M_PI / 2);
	rot_x = rotation_x(data, token->normalized_3d_direction.x);
	rot_y = rotation_y(data, token->normalized_3d_direction.y);
	rot_z = rotation_z(data, token->normalized_3d_direction.z);
	camera->direction = multiply_matrices(&rot_x, &rot_y);
	camera->direction = multiply_matrices(&rot_z, &camera->direction);
	camera->right = multiply_tuple_by_matrix(&(t_tuple){1, 0, 0, 1}, &camera->direction);
	camera->up = multiply_tuple_by_matrix(&(t_tuple){0, 1, 0, 1}, &camera->direction);
	camera->front = multiply_tuple_by_matrix(&(t_tuple){0, 0, 1, 1}, &camera->direction);
	return (camera);
}

static t_tuple	multiply_tuple_by_matrix(t_tuple *tuple, t_matrix *matrix)
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
