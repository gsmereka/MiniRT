/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:07:48 by gsmereka          #+#    #+#             */
/*   Updated: 2023/09/22 22:59:06 by gde-mora         ###   ########.fr       */
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
	t_token	objects[2];
	double	intersect_times[2];
}	t_intersect;

typedef struct s_intersection
{
	double					time;
	t_token					*object;
	struct s_intersection	*next;
}	t_intersection;

t_intersect 	intersect(t_token *token, t_ray *ray);
t_intersection	*create_intersection(double time, t_token *object);
void			add_intersection(t_intersection **inter_list, double time, \
	t_token *object);
t_intersect	intersections(t_intersection *inter_list);
void	free_intersection_list(t_intersection *inter_list);

#endif