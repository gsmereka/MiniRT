/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_floating_points.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:35:10 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/10 16:48:00 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"
#define EPSILON 0.00001

// constante EPSILON ← 0,00001
// função igual (a, b)
// 	E se abdômen (a - b) <EPSILON
// 		Retorna verdade
// 	outro
// 		Retorna falso
// 	fim se
// função final

int	are_floats_equal(double one, double two)
{
	if ((one - two) < EPSILON)
		return (1);
	return (0);
}

int	are_tuples_equal(t_tuple *one, t_tuple *two)
{
	int	result;

	result = 0;
	if (are_floats_equal(one->x, two->x))
		result++;
	if (are_floats_equal(one->y, two->y))
		result++;
	if (are_floats_equal(one->z, two->z))
		result++;
	if (are_floats_equal(one->w, two->w))
		result++;
	if (result == 3)
		return (1);
	return (0);
}
