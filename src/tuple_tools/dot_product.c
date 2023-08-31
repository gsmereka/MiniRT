/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:46:18 by gsmereka          #+#    #+#             */
/*   Updated: 2023/08/31 15:50:29 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

double	dot_product(t_tuple *one, t_tuple *two)
{
	double	dot_product;

	dot_product = 0;
	dot_product += one->x * two->x;
	dot_product += one->y * two->y;
	dot_product += one->z * two->z;
	return (dot_product);
}
