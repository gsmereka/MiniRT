/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_magnitude.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:46:18 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/30 18:22:44 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

double	tuple_magnitude(t_tuple *tuple)
{
	double	x;
	double	y;
	double	z;
	double	w;
	double	magnitude;

	x = pow(tuple->x, 2);
	y = pow(tuple->y, 2);
	z = pow(tuple->z, 2);
	w = pow(tuple->w, 2);
	magnitude = sqrt(x + y + z + w);
	return (magnitude);
}
