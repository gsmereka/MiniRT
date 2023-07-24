/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:18:21 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/21 17:28:45 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static int		filling_matrix_content(double **new_content,
					double **a, double **b, int max_cols);
static double	*create_row(double **a, double **b, int row, int max_cols);

t_matrix	*multiply_matrices(t_matrix *a, t_matrix *b)
{
	t_matrix	*new_matrix;
	double		**new_content;
	int			new_rows;
	int			new_cols;

	if (!a || !b)
		return (NULL);
	else if (!a->content || !b->content)
		return (NULL);
	else if (!a->cols || !b->cols)
		return (NULL);
	else if (a->cols != b->rows)
		return (NULL);
	new_rows = a->rows;
	new_cols = b->cols;
	new_content = ft_calloc(new_rows + 1, sizeof(double *));
	if (!new_content)
		return (NULL);
	if (!filling_matrix_content(new_content, a->content, b->content, new_cols))
		return (NULL);
	new_matrix = create_matrix(new_content, new_cols);
	return (new_matrix);
}

static int	filling_matrix_content(double **new_content,
	double **a, double **b, int max_cols)
{
	int	row;

	row = 0;
	while (a[row])
	{
		new_content[row] = create_row(a, b, row, max_cols);
		if (!new_content[row])
		{
			free_array((void **)new_content);
			return (0);
		}
		row++;
	}
	return (1);
}

static double	*create_row(double **a, double **b, int row, int max_cols)
{
	double	*new_row;
	int		col;
	int		element;

	new_row = ft_calloc(max_cols, sizeof(double));
	if (!new_row)
		return (NULL);
	col = 0;
	while (col < max_cols)
	{
		element = 0;
		while (b[element])
		{
			new_row[col] += (a[row][element] * b[element][col]);
			element++;
		}
		col++;
	}
	return (new_row);
}