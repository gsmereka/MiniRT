/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_submatrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:08:50 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/24 21:23:33 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static double	*get_subrow(double *row, int max_cols, int col_excluded);
static double	**get_subcontent(t_matrix *matrix,
					int row_excluded, int col_excluded);

t_matrix	*get_submatrix(t_matrix *matrix, int row_excluded, int col_excluded)
{
	double		**subcontent;
	t_matrix	*submatrix;

	if (!matrix || !matrix->content)
		return (NULL);
	if (row_excluded < 0 || col_excluded < 0)
		return (NULL);
	if (matrix->rows < row_excluded || matrix->cols < col_excluded)
		return (NULL);
	if (matrix->rows != matrix->cols)
		return (NULL);
	subcontent = get_subcontent(matrix, row_excluded, col_excluded);
	if (!subcontent)
		return (NULL);
	submatrix = create_matrix(subcontent, matrix->cols - 1);
	return (submatrix);
}

static double	**get_subcontent(t_matrix *matrix,
				int row_excluded, int col_excluded)
{
	int		row;
	int		skip;
	double	**subcontent;

	row = 0;
	skip = 0;
	subcontent = ft_calloc(matrix->rows, sizeof(double *));
	if (!subcontent)
		return (NULL);
	while (row < matrix->rows - 1)
	{
		if (row == row_excluded)
			skip = 1;
		subcontent[row] = get_subrow(matrix->content[row + skip],
				matrix->cols, col_excluded);
		if (!subcontent[row])
		{
			free_array((void **)subcontent);
			return (NULL);
		}
		row++;
	}
	return (subcontent);
}

static double	*get_subrow(double *row, int max_cols, int col_excluded)
{
	int		col;
	int		skip;
	double	*new_row;

	new_row = ft_calloc(max_cols - 1, sizeof(double));
	if (!new_row)
		return (NULL);
	col = 0;
	skip = 0;
	while (col < max_cols - 1)
	{
		if (col == col_excluded)
			skip = 1;
		new_row[col] = row[col + skip];
		col++;
	}
	return (new_row);
}
