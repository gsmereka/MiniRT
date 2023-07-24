/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_idmatrices.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:18:46 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/21 19:47:44 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	init_idmatrices(t_data *data)
{
	data->idmatrix_2x2 = str_to_matrix("1,0|0,1");
	data->idmatrix_3x3 = str_to_matrix("1,0,0|0,1,0|0,0,1");
	data->idmatrix_4x4 = str_to_matrix("1,0,0,0|0,1,0,0|0,0,1,0|0,0,0,1");
	if (!data->idmatrix_2x2 || !data->idmatrix_3x3 || !data->idmatrix_4x4)
		exit_error("Error\nFail at allocate identidy matrix\n", 12, data);
	// print_matrix(data->idmatrix_2x2);
	// print_matrix(data->idmatrix_3x3);
	// print_matrix(data->idmatrix_4x4);
}
