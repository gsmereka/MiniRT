/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cofactor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:19:32 by gsmereka          #+#    #+#             */
/*   Updated: 2023/08/13 17:41:31 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

double	get_cofactor(t_matrix *matrix, int row, int col)
{
	double		cofactor;
	int			signal;
	t_matrix	submatrix;

	signal = (row + col) % 2;
	cofactor = 0;
	if (signal == 1)
		signal = -1;
	else
		signal = 1;
	submatrix = get_submatrix(matrix, row, col);
	cofactor = get_determinant(&submatrix) * signal;
	if (are_floats_equal(cofactor, -0.0))
		cofactor = 0;
	return (cofactor);
}
