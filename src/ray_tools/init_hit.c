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

// void	pass_hit_values(t_hit *a, t_hit *b)
// {


// }

t_hit	init_hit(t_token *object,
		t_tuple *normal, double distance, t_tuple *position)
{
	t_hit	hit;

	hit = (t_hit){0};
	pass_tuple_values(&hit.position, position);
	pass_tuple_values(&hit.normal, normal);
	hit.object = object;
	hit.distance = distance;
	return (hit);
}
