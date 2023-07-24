/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_determinant.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:49:07 by gde-mora          #+#    #+#             */
/*   Updated: 2023/07/24 22:40:58 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static double	determinant_2x2(t_matrix *matrix)
{
	double	a;
	double	b;
	double	determinant;

	if (!matrix || !matrix->content)
		return (-1);
	determinant = 0;
	if (matrix->rows == 2 && matrix->cols == 2)
	{
		a = matrix->content[0][0] * matrix->content[1][1];
		b = matrix->content[0][1] * matrix->content[1][0];
		determinant = a - b;
	}
	return (determinant);
}

static double cofactor(double factor, t_matrix *submatrix, int signal)
{
	double	cofactor;

	cofactor = factor * determinant_2x2(submatrix) * signal;
	free_matrix(submatrix);
	return (cofactor);
}

static double	determinant_3x3(t_matrix *matrix)
{
	double	determinant;
	int		multiplicator;
	int		j;

	j = 0;
	multiplicator = 1;
	determinant = 0;
	while (j < matrix->cols)
	{
		determinant += cofactor(matrix->content[0][j], get_submatrix(matrix, 0, j), multiplicator);
		multiplicator *= -1;
		j++;
	}
	return (determinant);
}

static double	determinant_4x4(t_matrix *matrix)
{
	t_matrix	*aux_matrix;
	double	determinant;
	int		multiplicator;
	int		j;

	j = 0;
	multiplicator = 1;
	determinant = 0;
	aux_matrix = NULL;
	while (j < matrix->cols)
	{
		aux_matrix = get_submatrix(matrix, 0, j);
		determinant += determinant_3x3(aux_matrix) * multiplicator * matrix->content[0][j];
		free_matrix(aux_matrix);
		multiplicator *= -1;
		j++;
	}
	return (determinant);
}

double	get_determinant(t_matrix *matrix)
{
	if (!matrix || !matrix->content)
		return (-1);
	if (matrix->rows == 2)
		return (determinant_2x2(matrix));
	else if (matrix->rows == 3)
		return (determinant_3x3(matrix));
	else
		return (determinant_4x4(matrix));
}
