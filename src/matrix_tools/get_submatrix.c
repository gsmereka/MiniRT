/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_submatrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:08:50 by gsmereka          #+#    #+#             */
/*   Updated: 2023/08/13 17:43:22 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static void		get_subrow(double *dest, double *row, int max_cols, int col_excluded);
static void		get_subcontent(t_matrix *matrix,
					int row_excluded, int col_excluded, double **subcontent);

t_matrix	get_submatrix(t_matrix *matrix, int row_excluded, int col_excluded) // alterada
{
	double		subcontent[MATRIX_SIZE + 1][MATRIX_SIZE];
	t_matrix	submatrix;

	if (!matrix || !matrix->content)
		return ((t_matrix){0});
	if (row_excluded < 0 || col_excluded < 0)
		return ((t_matrix){0});
	if (matrix->rows < row_excluded || matrix->cols < col_excluded)
		return ((t_matrix){0});
	if (matrix->rows != matrix->cols)
		return ((t_matrix){0});
	get_subcontent(matrix, row_excluded, col_excluded, (double **)subcontent);
	submatrix = create_matrix((double **)subcontent, matrix->cols - 1);
	return (submatrix);
}

static void	get_subcontent(t_matrix *matrix,
				int row_excluded, int col_excluded, double **subcontent) // alterada
{
	int		row;
	int		skip;

	row = 0;
	skip = 0;
	while (row < matrix->rows - 1)
	{
		if (row == row_excluded)
			skip = 1;
		get_subrow((double *)subcontent[row], (double *)matrix->content[row + skip],
				matrix->cols, col_excluded);
		row++;
	}
}

static void get_subrow(double *dest, double *row, int max_cols, int col_excluded) // alterada
{
	int		col;
	int		skip;

	col = 0;
	skip = 0;
	while (col < max_cols - 1)
	{
		if (col == col_excluded)
			skip = 1;
		dest[col] = row[col + skip];
		col++;
	}
}
