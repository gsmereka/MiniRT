/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:09:29 by gsmereka          #+#    #+#             */
/*   Updated: 2023/10/29 00:00:36 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

double	calculate_discriminant(t_intersect *intersect, t_token *token, t_ray *ray);

t_intersect intersect(t_token *token, t_ray *ray) //criar struct p salvar a b c
{
	t_intersect	intersect;
	double		discriminant;

	intersect = (t_intersect){0};
	discriminant = calculate_discriminant(&intersect, token, ray);
	// if (discriminant < 0.0)
	// {
		// intersect.count = 0;
		// return (intersect);
	// }
	// intersect.local_times[0] = (-intersect.b - sqrt(discriminant)) / (2 * intersect.a);
	// intersect.local_times[1] = (-intersect.b + sqrt(discriminant)) / (2 * intersect.a);
	// if (are_floats_equal(intersect.local_times[0], intersect.local_times[1]))
	// 	intersect.count = 1;
	// else
	// 	intersect.count = 2;
	// intersect.local_obj = token;
	return (intersect);
}

double	calculate_discriminant(t_intersect *intersect, t_token *token, t_ray *ray)
{
	static int	i;
	double	d;
	t_tuple	token_to_ray;
	t_tuple	point_zero;

	(void)token;
	if (!i)
	{
		printf("%f\n", &ray->direction.x);
	}
	i++;
	point_zero = token->coordinate;
	token_to_ray = subtract_tuples(&ray->origin, &point_zero);
	intersect->a = dot_product(&ray->direction, &ray->direction);
	intersect->b = dot_product(&ray->direction, &token_to_ray) * 2;
	intersect->c = dot_product(&token_to_ray, &token_to_ray) - (token->ratio * token->ratio);
	
	d = (intersect->b * intersect->b) - (4 * intersect->a * intersect->c);
	return (d);
}