/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cofactor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:19:32 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/31 19:19:41 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

double get_cofactor(t_matrix *matrix, int row, int col) //mudar nome pra get_get_cofactor
{
	double		get_cofactor;
	int			signal;
	t_matrix	*submatrix;

	signal = (row + col) % 2;
	get_cofactor = 0;
	if (signal == 1)
		signal = -1;
	else
		signal = 1;
	submatrix = get_submatrix(matrix, row, col);
	if (!submatrix)
		return (0); //?
	get_cofactor = get_determinant(submatrix) * signal;
	if (get_cofactor == -0)
		get_cofactor = 0;
	free_matrix(submatrix);
	return (get_cofactor);
}
