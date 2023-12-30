/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:46:18 by gsmereka          #+#    #+#             */
/*   Updated: 2023/08/13 17:46:35 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_tuple	cross_product(t_tuple *one, t_tuple *two)
{
	t_tuple	cross_product;

	cross_product.x = (one->y * two->z) - (one->z * two->y);
	cross_product.y = (one->z * two->x) - (one->x * two->z);
	cross_product.z = (one->x * two->y) - (one->y * two->z);
	return (cross_product);
}
