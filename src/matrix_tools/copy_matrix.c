/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:24:07 by gde-mora          #+#    #+#             */
/*   Updated: 2023/11/03 20:42:52 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static void	copy_content(t_matrix *src, t_matrix *dest)
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

t_matrix	copy_matrix(t_matrix *src)
{
	t_matrix	dest;

	if (!src)
		return ((t_matrix){0});
	copy_content(src, &dest);
	dest.rows = src->rows;
	dest.cols = src->cols;
	dest.determinant = src->determinant;
	return (dest);
}
