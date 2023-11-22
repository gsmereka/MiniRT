/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:57:29 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/22 14:28:22 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_hit	*init_hit(t_token *object,
		t_tuple *normal, double distance, t_tuple *position)
{
	t_hit	*hit;

	hit = ft_calloc(1, sizeof(t_hit));
	pass_tuple_values(&hit->position, position);
	pass_tuple_values(&hit->normal, normal);
	hit->object = object;
	hit->distance = distance;
	return (hit);
}
