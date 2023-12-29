/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:18:50 by gsmereka          #+#    #+#             */
/*   Updated: 2023/12/04 19:51:42 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

// cos_light_incidence calculates the incidence of light on the hit
// and needs to be divided by the square of the distance
// to represent the variation of the intensity of light with distance.

double	light_at2(t_token *light, t_hit *hit)
{
	t_tuple	direction;
	double	distance;
	double	cos_light_incidence;
	double	ilumination;

	direction = subtract_tuples(&light->coordinate, &hit->position);
	distance = tuple_magnitude(&direction);
	normalize_tuple(&direction);
	cos_light_incidence = dot_product(&direction, &hit->normal);
	ilumination = light->lighting_ratio * 20
		* (cos_light_incidence / (distance * distance));
	return (ilumination);
}

double light_at(t_token *light, t_hit *hit)
{
    t_tuple direction;
    double distance;
    double cos_light_incidence;
    double illumination;

    direction = subtract_tuples(&light->coordinate, &hit->position);
    distance = tuple_magnitude(&direction);
    normalize_tuple(&direction);
    cos_light_incidence = dot_product(&direction, &hit->normal);
    
    illumination = fmax(0, light->lighting_ratio * cos_light_incidence / (distance));

    return illumination;
}
