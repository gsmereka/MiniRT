/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_tuples_equal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:48:07 by gde-mora          #+#    #+#             */
/*   Updated: 2023/08/02 22:01:42 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

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
