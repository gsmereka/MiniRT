/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverting_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:31:11 by gde-mora          #+#    #+#             */
/*   Updated: 2023/07/31 18:33:39 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_matrix *inverting_matrix(t_matrix *matrix)
{
    t_matrix    *new_matrix;
    double      **new_content;
    int			rows;
	int			cols;
    double      cofact; //mudar nome pra cofactor

    if (!matrix)
        return (NULL);
    if (are_floats_equal(matrix->determinant, 0.0))
        return (NULL);
    new_content = ft_calloc(matrix->rows + 1, sizeof(double *));
	if (!new_content)
		return (NULL);
    rows = -1;
    while (++rows < matrix->rows)
    {
        cols = -1;
        while (++cols < matrix->cols)
        {
            cofact = cofactor(matrix, rows, cols);
            new_content[cols][rows] = cofact / matrix->determinant;
        }
    }
    new_matrix = create_matrix(new_content, matrix->cols);
    return (new_matrix);
}
