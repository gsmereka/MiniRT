/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_floats_equal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:35:10 by gsmereka          #+#    #+#             */
/*   Updated: 2024/02/03 22:18:22 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

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
