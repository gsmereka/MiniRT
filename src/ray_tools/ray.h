/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:07:48 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/22 12:39:35 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct s_sphere
{
	struct s_tuple	origin;
	double			raio;
}	t_sphere;

typedef struct s_intersect
{
	double	a;
	double	b;
	double	c;
	double	solutions[2];
}	t_intersect;

t_intersect		intersect(t_token *token, t_ray *ray);
t_tuple			ray_position(t_ray *ray, double time);
t_hit			*init_hit(t_token *object,
					t_tuple *normal, double distance, t_tuple *position);
double			light_at(t_token *light, t_hit *hit);
t_color			trace_ray(t_scene *scene, t_ray *object_ray, t_ray *light_ray);

#endif