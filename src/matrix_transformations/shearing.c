/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:30:40 by gsmereka          #+#    #+#             */
/*   Updated: 2023/08/02 17:45:43 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_matrix	*shearing(double *proportions, t_data *data)
{
	t_matrix	*identidy;

	identidy = copy_matrix(data->idmatrix_4x4);
	if (!identidy)
		return (NULL);
	identidy->content[0][1] = proportions[0];
	identidy->content[0][2] = proportions[1];
	identidy->content[1][0] = proportions[2];
	identidy->content[1][2] = proportions[3];
	identidy->content[2][0] = proportions[4];
	identidy->content[2][1] = proportions[5];
	identidy->determinant = get_determinant(identidy);
	return (identidy);
}
