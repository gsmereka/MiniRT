/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:20:57 by gsmereka          #+#    #+#             */
/*   Updated: 2023/10/31 23:21:16 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_ray init_ray(t_tuple *origin, t_tuple *direction)
{
	t_ray ray;

	pass_tuple_values(&ray.direction, direction);
	normalize_tuple(&ray.direction);
	pass_tuple_values(&ray.origin, origin);
	return (ray);
}
