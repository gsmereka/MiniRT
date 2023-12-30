/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_determinant.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:49:07 by gde-mora          #+#    #+#             */
/*   Updated: 2023/08/16 21:04:06 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

double	get_determinant(t_matrix *matrix)
{
	double	a;
	double	b;
	double	determinant;
	int		j;

	if (!matrix)
		return (0);
	determinant = 0;
	if (matrix->rows == 2 && matrix->cols == 2)
	{
		a = matrix->content[0][0] * matrix->content[1][1];
		b = matrix->content[0][1] * matrix->content[1][0];
		determinant = a - b;
	}
	else
	{
		j = -1;
		while (++j < matrix->cols)
			determinant += get_cofactor(matrix, 0, j) * matrix->content[0][j];
	}
	return (determinant);
}
