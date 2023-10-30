/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:42:37 by gsmereka          #+#    #+#             */
/*   Updated: 2023/10/29 23:08:50 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PYTHON_VER_H
# define PYTHON_VER_H
#include "../../headers/miniRT.h"

// import pygame
// import math
// import glm
// from glm import vec3

void	render_scene(t_SCENE *scene, t_CAMERA *camera, t_data *data);
t_ray	*get_ray(t_CAMERA *camera, double j, double i);
t_tuple	trace_color(t_SCENE *scene, t_ray *ray);

#endif