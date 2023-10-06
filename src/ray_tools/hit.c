/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:09:29 by gsmereka          #+#    #+#             */
/*   Updated: 2023/10/06 22:20:20 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_intersection	*hit(t_intersect *xs)
{
	int				i;
	t_intersection	*i1;

	i = 0;
	while (i < xs->count)
	{
		if (xs->intersect_times[i] > 0)
		{
			i1 = create_intersection(xs->intersect_times[i], xs->objects[i]);
			return (i1);
		}
		i++;
	}
	return (NULL);
}
