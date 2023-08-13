/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:45:03 by gsmereka          #+#    #+#             */
/*   Updated: 2023/08/13 15:59:27 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static void copy_content(double **src, double **dest, int cols, int rows) // alterada
{
	int		i;
	int		j;

	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
			dest[i][j] = src[i][j];
	}
}

t_matrix	create_matrix(double **content, int cols) // alterada
{
	int			rows;
	t_matrix	matrix;

	if (!content)
		return ((t_matrix){0});
	rows = 0;
	while (content[rows])
		rows++;
	copy_content(content, (double **)matrix.content, cols, rows);
	matrix.rows = rows;
	matrix.cols = cols;
	matrix.determinant = get_determinant(&matrix);
	free_array((void **)content);
	return (matrix);
}
