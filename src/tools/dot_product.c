/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:46:18 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/10 15:58:13 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

// função ponto (a, b)
// Retorna ax * bx +
// ay * por +
// az * bz +
// aw * bw
// função final

double	dot_product(t_tuple *one, t_tuple *two)
{
	double	dot_product;

	dot_product = 0;
	dot_product += one->x * two->x;
	dot_product += one->y * two->y;
	dot_product += one->z * two->z;
	dot_product += one->w * two->w;
	return (dot_product);
}
