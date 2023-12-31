/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:24:17 by gde-mora          #+#    #+#             */
/*   Updated: 2023/08/13 15:48:14 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_matrix	scaling(t_data *data, double x, double y, double z) // alterada
{
	t_matrix	matrix;

	matrix = copy_matrix(&data->idmatrix_4x4);
	matrix.content[0][0] = x;
	matrix.content[1][1] = y;
	matrix.content[2][2] = z;
	matrix.determinant = get_determinant(&matrix);
	return (matrix);
}
