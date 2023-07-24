/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:45:03 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/21 17:50:12 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_matrix	*create_matrix(double **content, int cols)
{
	int			rows;
	t_matrix	*matrix;

	if (!content)
		return (NULL);
	matrix = ft_calloc(1, sizeof(t_matrix));
	if (!matrix)
		return (NULL);
	matrix->content = content;
	rows = 0;
	while (content[rows])
		rows++;
	matrix->rows = rows;
	matrix->cols = cols;
	return (matrix);
}
