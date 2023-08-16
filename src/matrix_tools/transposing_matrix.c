/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transposing_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:03:49 by gde-mora          #+#    #+#             */
/*   Updated: 2023/08/16 21:03:08 by gde-mora         ###   ########.fr       */
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

static int	filling_matrix_content(double **new_content, t_matrix *matrix_struct)
{
	int	i;
	int	j;
	double	**matrix;

	i = 0;
	matrix = (double **)matrix_struct->content;
	while (matrix[i]) //linha
	{
		j = 0;
		new_content[i] = ft_calloc(matrix_struct->rows, sizeof(double));
		while (j < matrix_struct->cols) //colunas
		{
			new_content[i][j] = matrix[j][i];
			//printf("[ %lf ]", matrix[j][i]); //invés de printar, devo salvar
			j++;
		}
		i++;
		//printf("\n");
	}
	return (1);
}

t_matrix	transposing_matrix(t_matrix *mat) // alterada
{
	t_matrix	new_matrix;
	double		**new_content;
	int			new_rows;
	int			new_cols;

	if (!mat)
		return ((t_matrix){0});
	// else if (!mat->content)
	// 	return ((t_matrix){0}); //mais uma verficação aqui?
	new_rows = mat->cols;
	new_cols = mat->rows;
	new_content = ft_calloc(new_rows + 1, sizeof(double *));
	if (!new_content)
		return ((t_matrix){0});
	if (!filling_matrix_content(new_content, mat))
		return ((t_matrix){0});
	new_matrix = create_matrix(new_content, new_cols);
	return (new_matrix);
}
