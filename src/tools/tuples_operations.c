/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:46:18 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/10 21:28:03 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_tuple	*sum_tuples(t_tuple *one, t_tuple *two) // É melhor que essas operações criem uma tupla nova ou substituam uma das tuplas anteriores ?
{
	t_tuple	*new_tuple;

	new_tuple = ft_calloc(1, sizeof(t_tuple));
	new_tuple->x = one->x + two->x;
	new_tuple->y = one->y + two->y;
	new_tuple->z = one->z + two->z;
	new_tuple->w = one->w + two->w;
	return (new_tuple);
}

t_tuple	*subtract_tuples(t_tuple *one, t_tuple *two) // É melhor que essas operações criem uma tupla nova ou substituam uma das tuplas anteriores ?
{
	t_tuple	*new_tuple;

	new_tuple = ft_calloc(1, sizeof(t_tuple));
	new_tuple->x = one->x - two->x;
	new_tuple->y = one->y - two->y;
	new_tuple->z = one->z - two->z;
	new_tuple->w = one->w - two->w;
	return (new_tuple);
}

t_tuple	*reverse_tuple(t_tuple *tuple) // É melhor que essas operações criem uma tupla nova ou substituam uma das tuplas anteriores ?
{
	t_tuple	*new_tuple;

	new_tuple = ft_calloc(1, sizeof(t_tuple));
	new_tuple->x = tuple->x * -1;
	new_tuple->y = tuple->y * -1;
	new_tuple->z = tuple->z * -1;
	new_tuple->w = tuple->w * -1;
	return (new_tuple);
}

t_tuple	*multiply_tuple(t_tuple *tuple, double factor)
{
	t_tuple	*new_tuple;

	new_tuple = ft_calloc(1, sizeof(t_tuple));
	new_tuple->x = tuple->x * factor;
	new_tuple->y = tuple->y * factor;
	new_tuple->z = tuple->z * factor;
	new_tuple->w = tuple->w * factor;
	return (new_tuple);
}

t_tuple	*divide_tuple(t_tuple *tuple, double factor)
{
	t_tuple	*new_tuple;

	new_tuple = ft_calloc(1, sizeof(t_tuple));
	new_tuple->x = tuple->x / factor;
	new_tuple->y = tuple->y / factor;
	new_tuple->z = tuple->z / factor;
	new_tuple->w = tuple->w / factor;
	return (new_tuple);
}
