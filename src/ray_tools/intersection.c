/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:41:19 by gsmereka          #+#    #+#             */
/*   Updated: 2023/09/08 19:43:55 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_intersection	intersection(double time, t_token *object)
{
	t_intersection	intersection;

	intersection = (t_intersection){0};
	intersection.time = time;
	intersection.object = object;
	return (intersection);
}
