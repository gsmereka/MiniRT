/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tuple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:45:26 by gde-mora          #+#    #+#             */
/*   Updated: 2023/08/13 17:46:31 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_tuple	create_point(double x, double y, double z) // alterada
{
	t_tuple	new_tuple;

	new_tuple.x = x;
	new_tuple.y = y;
	new_tuple.z = z;
	new_tuple.w = 1;
	return (new_tuple);
}

t_tuple	create_vector(double x, double y, double z) // alterada
{
	t_tuple	new_tuple;

	new_tuple.x = x;
	new_tuple.y = y;
	new_tuple.z = z;
	new_tuple.w = 0;
	return (new_tuple);
}
