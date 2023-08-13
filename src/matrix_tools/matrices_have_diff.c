/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_have_diff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:01:47 by gsmereka          #+#    #+#             */
/*   Updated: 2023/08/13 17:43:46 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static int	comparing_content(double **a, double **b, int max_cols);

int	matrices_have_diff(t_matrix *a, t_matrix *b) // alterada
{
	int	result;

	if (!a || !b)
		return (-1);
	else if (!a->content && !b->content)
		return (0);
	else if (!a->content && b->content)
		return (1);
	else if (a->content && !b->content)
		return (1);
	else if (a->cols != b->cols)
		return (1);
	else if (a->rows != b->rows)
		return (1);
	result = comparing_content((double **)a->content, (double **)b->content, a->cols);
	return (result);
}

static int	comparing_content(double **a, double **b, int max_cols)
{
	int	i;
	int	j;

	i = 0;
	while (a[i] && b[i])
	{
		j = 0;
		while (j < max_cols)
		{
			if (!are_floats_equal(a[i][j], b[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	if (!a[i] && !b[i])
		return (0);
	return (1);
}
