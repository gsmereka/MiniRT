/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:07:48 by gsmereka          #+#    #+#             */
/*   Updated: 2023/12/04 21:25:28 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct s_intersect
{
	double	a;
	double	b;
	double	c;
	double	solutions[2];
}	t_intersect;

t_hit			*closest_hit(t_scene *scene, t_ray *ray);
void			calculate_ray_direction(t_ray *ray, t_camera *camera, double j, double i);
void			normalize_ray(t_ray *ray, t_tuple *origin, t_tuple *direction);
t_hit			*intersect_sphere(t_token *sphere, t_ray *ray);
t_hit			*intersect_cylinder(t_token *cylinder, t_ray *ray);
t_hit			*intersect_plane(t_token *plane, t_ray *ray);
t_tuple			ray_position(t_ray *ray, double time);
t_hit			*init_hit(t_token *object,
					t_tuple *normal, double distance, t_tuple *position);
double			light_at(t_token *light, t_hit *hit);
t_color			trace_ray(t_scene *scene, t_ray *object_ray, t_ray *light_ray);

#endif