/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:18:21 by gsmereka          #+#    #+#             */
/*   Updated: 2023/08/16 21:06:49 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static int		filling_matrix_content(double **new_content,
					t_matrix *a, t_matrix *b, int max_cols);
static double	*create_row(t_matrix *a, t_matrix *b, int row, int max_cols);

t_matrix	multiply_matrices(t_matrix *a, t_matrix *b) // alterada
{
	t_matrix	new_matrix;
	double		**new_content;
	int			new_rows;
	int			new_cols;

	if (!a || !b)
		return ((t_matrix){0});
	// else if (!a->content || !b->content)
	// 	return ((t_matrix){0});
	else if (!a->cols || !b->cols)
		return ((t_matrix){0});
	else if (a->cols != b->rows)
		return ((t_matrix){0});
	new_rows = a->rows;
	new_cols = b->cols;
	new_content = ft_calloc(new_rows + 1, sizeof(double *));
	if (!new_content)
		return ((t_matrix){0});
	if (!filling_matrix_content(new_content, a, b, new_cols))
		return ((t_matrix){0});
	new_matrix = create_matrix(new_content, new_cols);
	return (new_matrix);
}

static int	filling_matrix_content(double **new_content,
	t_matrix *a, t_matrix *b, int max_cols)
{
	int	row;

	row = 0;
	while (row < a->rows)
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

static double	*create_row(t_matrix *a, t_matrix *b, int row, int max_cols)
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
		while (element < b->rows)
		{
			new_row[col] += (a->content[row][element] * b->content[element][col]);
			element++;
		}
		if (are_floats_equal(new_row[col], -0.0))
			new_row[col] = 0;
		col++;
	}
	return (new_row);
}
