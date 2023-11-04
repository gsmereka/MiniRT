/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:57:29 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/04 14:57:43 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/miniRT.h"

t_HIT	*init_HIT(t_token *object,
		t_tuple *normal, double distance, t_tuple *position)
{
	t_HIT	*hit;

	hit = ft_calloc(1, sizeof(t_HIT));
	pass_tuple_values(&hit->position, position);
	pass_tuple_values(&hit->normal, normal);
	hit->object = object;
	hit->distance = distance;
	return (hit);
}
