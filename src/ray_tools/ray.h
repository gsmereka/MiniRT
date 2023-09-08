/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:07:48 by gsmereka          #+#    #+#             */
/*   Updated: 2023/09/08 19:44:20 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct s_sphere
{
	struct	s_tuple origin;
	double	raio;
}	t_sphere;

typedef struct s_intersect
{
	double	a;
	double	b;
	double	c;
	int		count;
	double	intersect_times[2];
}	t_intersect;

typedef struct s_intersection
{
	double	time;
	t_token	*object;
}	t_intersection;

t_intersect 	intersect(t_token *token, t_ray *ray);
t_intersection	intersection(double time, t_token *object);

#endif