/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_floats_equal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:35:10 by gsmereka          #+#    #+#             */
/*   Updated: 2023/08/02 21:48:48 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"
#define EPSILON 0.00001

int	are_floats_equal(double one, double two)
{
	double	result;

	result = one - two;
	if (result < 0)
		result *= -1;
	if ((result) < EPSILON)
		return (1);
	return (0);
}
