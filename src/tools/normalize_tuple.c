/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_tuple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:46:18 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/10 15:58:23 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	normalize_tuple(t_tuple *tuple) // Criar ou não nova tupla ?
{
	double	magnitude;

	magnitude = tuple_magnitude(tuple);
	tuple->x = tuple->x / magnitude;
	tuple->y = tuple->y / magnitude;
	tuple->z = tuple->z / magnitude;
	tuple->w = tuple->w / magnitude;
}
