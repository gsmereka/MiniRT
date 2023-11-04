/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:17:31 by gde-mora          #+#    #+#             */
/*   Updated: 2023/11/04 14:49:21 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef MAX_WIDTH
#  define MAX_WIDTH 3840
# endif

# ifndef MAX_HEIGHT
#  define MAX_HEIGHT 2160
# endif

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "./error_msg.h"
# include "./shape_types.h"
# include "./colors.h"
# include "./structs.h"
# include "../src/define_scene/define_scene.h"
# include "../src/render/ray_tools/ray.h"
# include "../src/matrix_tools/matrix_tools.h"
# include "../src/matrix_transformations/matrix_transformations.h"
# include "../src/parsing/parsing.h"
# include "../src/render/render.h"
# include "../src/tools/tools.h"
# include "../src/tuple_tools/tuple_tools.h"

void    	test_hits(t_data *data);
void		test_intersection(t_data *data);
void		test_matrices_operations(int argc, char **argv, t_data *data); // Retirar depois, do Makefile tb
void		test_ray(t_data *data);

// main functions
int			validate_scene_file(int argc, char *argv[], t_data *data);
int			read_scene_file(char *file, t_data *data);
void		get_scene_info(t_token *tokens, t_data *data);

// exit and utils
int			exit_error(char *msg, int status, t_data *data);
int			exit_successful(t_data *data);

// TESTE COM VERSÃO DO PYTHON
void	define_SCENE(t_data *data); // TESTE
void	render_scene(t_SCENE *scene, t_CAMERA *camera, t_data *data);

#endif
