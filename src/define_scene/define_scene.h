/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:42:37 by gsmereka          #+#    #+#             */
/*   Updated: 2023/10/31 23:21:30 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PYTHON_VER_H
# define PYTHON_VER_H
#include "../../headers/miniRT.h"

// import pygame
// import math
// import glm
// from glm import vec3

t_HIT	closest_hit(t_SCENE *scene, t_ray *ray);
void	render_scene(t_SCENE *scene, t_CAMERA *camera, t_data *data);
t_ray	*get_ray(t_CAMERA *camera, double j, double i);
t_tuple	trace_color(t_SCENE *scene, t_ray *ray);
t_HIT	intersect_sphere(t_token *sphere, t_ray *ray);
double  LIGHT_at(t_POINTLIGHT *light, t_HIT *hit);
t_ray   init_ray(t_tuple *origin, t_tuple *direction);

#endif