/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix_with_tuple.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:45:50 by gsmereka          #+#    #+#             */
/*   Updated: 2023/08/13 16:06:08 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static double	multiply_row_with_tuple(double *row, t_tuple *tuple);

t_tuple	multiply_matrix_with_tuple(t_matrix *matrix, t_tuple *tuple) // alterado
{
	t_tuple	new_tuple;

	if (!matrix || !tuple)
		return ((t_tuple){0});
	if ((matrix->rows != 4) || (matrix->cols != 4))
		return ((t_tuple){0});
	if (!(double **)matrix->content[0] || !(double **)matrix->content[1]
		|| !(double **)matrix->content[2] || !(double **)matrix->content[3])
		return ((t_tuple){0});
	new_tuple.x = multiply_row_with_tuple((double *)matrix->content[0], tuple);
	new_tuple.y = multiply_row_with_tuple((double *)matrix->content[1], tuple);
	new_tuple.z = multiply_row_with_tuple((double *)matrix->content[2], tuple);
	new_tuple.w = multiply_row_with_tuple((double *)matrix->content[3], tuple);
	return (new_tuple);
}

static double	multiply_row_with_tuple(double *row, t_tuple *tuple)
{
	double	result;

	result = 0;
	result += row[0] * tuple->x;
	result += row[1] * tuple->y;
	result += row[2] * tuple->z;
	result += row[3] * tuple->w;
	return (result);
}