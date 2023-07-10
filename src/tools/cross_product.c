/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:46:18 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/10 16:18:08 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

// function cross(a, b)
// return vector(a.y * b.z - a.z * b.y,
// 				 a.z * b.x - a.x * b.z,
// 				 a.x * b.y - a.y * b.x)
// end function


t_tuple	*cross_product(t_tuple *one, t_tuple *two)
{
	t_tuple	*cross_product;

	cross_product = ft_calloc(1, sizeof(t_tuple));
	cross_product->x = (one->y * two->z) - (one->z * two->y);
	cross_product->y = (one->z * two->x) - (one->x * two->z);
	cross_product->z = (one->x * two->y) - (one->y * two->z);
	return (cross_product);
}
