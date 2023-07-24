/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix_with_tuple.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:45:50 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/21 19:44:53 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static double	multiply_row_with_tuple(double *row, t_tuple *tuple);

t_tuple	*multiply_matrix_with_tuple(t_matrix *matrix, t_tuple *tuple)
{
	t_tuple	*new_tuple;

	if (!matrix || !tuple)
		return (NULL);
	if (!matrix->content)
		return (NULL);
	if ((matrix->rows != 4) || (matrix->cols != 4))
		return (NULL);
	if (!matrix->content[0] || !matrix->content[1]
		|| !matrix->content[2] || !matrix->content[3])
		return (NULL);
	new_tuple = ft_calloc(1, sizeof(t_tuple));
	if (!new_tuple)
		return (NULL);
	new_tuple->x = multiply_row_with_tuple(matrix->content[0], tuple);
	new_tuple->y = multiply_row_with_tuple(matrix->content[1], tuple);
	new_tuple->z = multiply_row_with_tuple(matrix->content[2], tuple);
	new_tuple->w = multiply_row_with_tuple(matrix->content[3], tuple);
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