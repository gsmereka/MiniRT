/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:59:18 by gde-mora          #+#    #+#             */
/*   Updated: 2023/07/31 18:54:42 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

double cofactor(t_matrix *matrix, int row, int col) //mudar nome pra get_cofactor
{
	double		cofactor;
	int			signal;
	t_matrix	*submatrix;

	signal = (row + col) % 2;
	cofactor = 0;
	if (signal == 1)
		signal = -1;
	else
		signal = 1;
	submatrix = get_submatrix(matrix, row, col);
	if (!submatrix)
		return (0); //?
	cofactor = get_determinant(submatrix) * signal;
	if (cofactor == -0)
		cofactor = 0;
	free_matrix(submatrix);
	return (cofactor);
}
