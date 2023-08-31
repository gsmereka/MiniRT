/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:47:08 by gsmereka          #+#    #+#             */
/*   Updated: 2023/08/13 15:47:59 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_matrix	translation(double x, double y, double z, t_data *data) // alterada
{
	t_matrix	identidy;

	identidy = copy_matrix(&data->idmatrix_4x4);
	identidy.content[0][3] = x;
	identidy.content[1][3] = y;
	identidy.content[2][3] = z;
	identidy.determinant = get_determinant(&identidy);
	return (identidy);
}
