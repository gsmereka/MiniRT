/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:46:18 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/08 00:11:58 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_tuple	*sum_tuples(t_tuple *one, t_tuple *two)
{
	t_tuple	*new_tuple;

	new_tuple = ft_calloc(1, sizeof(t_tuple));
	new_tuple->x = one->x + two->x;
	new_tuple->y = one->y + two->y;
	new_tuple->z = one->z + two->z;
	return (new_tuple);
}

t_tuple	*subtract_tuples(t_tuple *one, t_tuple *two)
{
	t_tuple	*new_tuple;

	new_tuple = ft_calloc(1, sizeof(t_tuple));
	new_tuple->x = one->x - two->x;
	new_tuple->y = one->y - two->y;
	new_tuple->z = one->z - two->z;
	return (new_tuple);
}

t_tuple	*reverse_tuple(t_tuple *tuple)
{
	t_tuple	*new_tuple;

	new_tuple = ft_calloc(1, sizeof(t_tuple));
	new_tuple->x = tuple->x - (2 * tuple->x);
	new_tuple->y = tuple->y - (2 * tuple->y);
	new_tuple->z = tuple->z - (2 * tuple->z);
	return (new_tuple);
}
