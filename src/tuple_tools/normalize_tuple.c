/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_tuple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:46:18 by gsmereka          #+#    #+#             */
/*   Updated: 2024/02/28 04:12:15 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	normalize_tuple(t_tuple *tuple)
{
	double	magnitude;

	magnitude = tuple_magnitude(tuple);
	// if (magnitude == 0.0) //necessário?
	// 	return ;
	tuple->x = tuple->x / magnitude;
	tuple->y = tuple->y / magnitude;
	tuple->z = tuple->z / magnitude;
	tuple->w = tuple->w / magnitude;
}
