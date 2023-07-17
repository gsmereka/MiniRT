/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:45:03 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/17 18:11:36 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_matrix	*create_matrix(double **content, int cols)
{
	t_matrix	*matrix;

	matrix = ft_calloc(1, sizeof(t_matrix));
	matrix->content = content;
	matrix->cols = cols;
	return (matrix);
}
