/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:59:18 by gde-mora          #+#    #+#             */
/*   Updated: 2023/07/24 23:10:18 by gde-mora         ###   ########.fr       */
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
	free_matrix(submatrix);
	return (cofactor);
}
