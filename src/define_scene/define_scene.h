/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:42:19 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/22 18:42:26 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_SCENE_H
# define DEFINE_SCENE_H
# include "../../headers/miniRT.h"

void        define_scene(t_data *data);
t_hit	    *closest_hit(t_scene *scene, t_ray *ray);
void	    calculate_ray_direction(t_ray *ray, t_camera *camera, double j, double i);
t_hit	    *intersect_sphere(t_token *sphere, t_ray *ray);
void	    normalize_ray(t_ray *ray, t_tuple *origin, t_tuple *direction);
t_camera	*init_camera(t_token *token, t_data *data);

#endif
