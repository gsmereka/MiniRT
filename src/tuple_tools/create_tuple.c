/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tuple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:45:26 by gde-mora          #+#    #+#             */
/*   Updated: 2023/08/02 22:20:31 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_tuple	*create_point(double x, double y, double z)
{
	t_tuple	*new_tuple;

	new_tuple = ft_calloc(1, sizeof(t_tuple));
	new_tuple->x = x;
	new_tuple->y = y;
	new_tuple->z = z;
	new_tuple->w = 1;
	return (new_tuple);
}

t_tuple	*create_vector(double x, double y, double z)
{
	t_tuple	*new_tuple;

	new_tuple = ft_calloc(1, sizeof(t_tuple));
	new_tuple->x = x;
	new_tuple->y = y;
	new_tuple->z = z;
	new_tuple->w = 0;
	return (new_tuple);
}
