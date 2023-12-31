/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:24:07 by gde-mora          #+#    #+#             */
/*   Updated: 2023/08/16 21:02:54 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static void copy_content(t_matrix *src, t_matrix *dest) // alterada
{
	int		i;
	int		j;

	i = -1;
	while (++i < src->rows)
	{
		j = -1;
		while (++j < src->cols)
			dest->content[i][j] = src->content[i][j];
	}
}

t_matrix	copy_matrix(t_matrix *src) // alterada
{
	t_matrix	dest;

	if (!src)
		return ((t_matrix){0});
	// if (!src->content)
	// 	return ((t_matrix){0});
	copy_content(src, &dest);
	dest.rows = src->rows;
	dest.cols = src->cols;
	dest.determinant = src->determinant;
	return (dest);
}
