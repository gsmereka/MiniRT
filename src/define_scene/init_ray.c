/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:20:57 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/03 16:57:43 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	init_ray(t_ray *ray, t_tuple *origin, t_tuple *direction)
{
	pass_tuple_values(&ray->direction, direction);
	normalize_tuple(&ray->direction);
	pass_tuple_values(&ray->origin, origin);
}
