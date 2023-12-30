/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transposing_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:03:49 by gde-mora          #+#    #+#             */
/*   Updated: 2023/08/16 20:58:56 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

/*
Example: 

0 9 3 0
9 8 0 8
1 8 5 3
0 0 5 8

0 9 1 0
9 8 8 0
3 0 5 5
0 8 3 8
*/

static	int	init_new_content(double **new_content, t_matrix *matrix)
{
	int	rows;

	rows = -1;
	while (++rows < matrix->rows)
	{
		new_content[rows] = ft_calloc(matrix->cols, sizeof(double));
		if (!new_content[rows])
		{
			free_array((void **)new_content);
			return (0);
		}
	}
	return (1);
}

static int	filling_matrix_content(double **new_content,
	t_matrix *matrix_struct, double old_content[MATRIX_SIZE][MATRIX_SIZE])
{
	int		i;
	int		j;

	i = 0;
	while (i < matrix_struct->rows)
	{
		j = 0;
		while (j < matrix_struct->cols)
		{
			new_content[i][j] = old_content[j][i];
			j++;
		}
		i++;
	}
	return (1);
}

t_matrix	transposing_matrix(t_matrix *mat)
{
	t_matrix	new_matrix;
	double		**new_content;
	int			new_rows;
	int			new_cols;

	if (!mat)
		return ((t_matrix){0});
	new_rows = mat->cols;
	new_cols = mat->rows;
	new_content = ft_calloc(new_rows + 1, sizeof(double *));
	if (!new_content)
		return ((t_matrix){0});
	if (!init_new_content(new_content, mat))
		return ((t_matrix){0});
	if (!filling_matrix_content(new_content, mat, mat->content))
		return ((t_matrix){0});
	new_matrix = create_matrix(new_content, new_cols);
	return (new_matrix);
}
