/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:17:31 by gde-mora          #+#    #+#             */
/*   Updated: 2024/02/03 22:19:25 by gde-mora         ###   ########.fr       */
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

# ifndef EPSILON
#  define EPSILON 0.00001
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
# include "../src/ray_tools/ray.h"
# include "../src/matrix_tools/matrix_tools.h"
# include "../src/matrix_transformations/matrix_transformations.h"
# include "../src/parsing/parsing.h"
# include "../src/render/render.h"
# include "../src/tools/tools.h"
# include "../src/tuple_tools/tuple_tools.h"

// main functions
int			validate_scene_file(int argc, char *argv[], t_data *data);
int			read_scene_file(char *file, t_data *data);
void		get_scene_info(t_token *tokens, t_data *data);

// exit and utils
int			exit_error(char *msg, int status, t_data *data);
int			exit_successful(t_data *data);

#endif
