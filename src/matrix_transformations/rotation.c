/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 22:47:08 by gde-mora          #+#    #+#             */
/*   Updated: 2023/08/13 15:48:26 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_matrix	rotation_x(t_data *data, double  radians) // alterada
{
	t_matrix	matrix;

	matrix = copy_matrix(&data->idmatrix_4x4);
	matrix.content[1][1] = cos(radians);
	matrix.content[1][2] = -sin(radians);
	matrix.content[2][1] = sin(radians);
	matrix.content[2][2] = cos(radians);
	matrix.determinant = get_determinant(&matrix);
	return (matrix);
}

t_matrix	rotation_y(t_data *data, double  radians) // alterada
{
	t_matrix	matrix;

	matrix = copy_matrix(&data->idmatrix_4x4);
	matrix.content[0][0] = cos(radians);
	matrix.content[0][2] = sin(radians);
	matrix.content[2][0] = -sin(radians);
	matrix.content[2][2] = cos(radians);
	matrix.determinant = get_determinant(&matrix);
	return (matrix);
}

t_matrix	rotation_z(t_data *data, double  radians) // alterada
{
	t_matrix	matrix;

	matrix = copy_matrix(&data->idmatrix_4x4);
	matrix.content[0][0] = cos(radians);
	matrix.content[0][1] = -sin(radians);
	matrix.content[1][0] = sin(radians);
	matrix.content[1][1] = cos(radians);
	matrix.determinant = get_determinant(&matrix);
	return (matrix);
}
