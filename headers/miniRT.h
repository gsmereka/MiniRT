/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:17:31 by gde-mora          #+#    #+#             */
/*   Updated: 2023/07/05 00:48:27 by gde-mora         ###   ########.fr       */
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

# include "./error_msg.h"
# include "./structs.h"
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define KEY_ESCAPE (0xff1b)

// general functions
void	render(t_data *data);
int		validate_scene_file(int argc, char *argv[], t_data *data);
int		read_scene_file(char *file, t_data *data);
int		exit_error(char *msg, int status, t_data *data);
int		exit_successful(t_data *data);
int		init_data(t_data *data);
double	atod(const char *str);
int		free_array(void **array);

//parse
int		is_coordinate(char *arg);
int		is_color(char *arg);
int		is_normalized_vector(char *arg);

// check_shape
int		is_plane(char **args, t_data *data);
int		is_sphere(char **args, t_data *data);
int		is_cylinder(char **args, t_data *data);

// check_config
int		is_ambient_lighting(char **args, t_data *data);
int		is_light(char **args, t_data *data);
int		is_camera(char **args, t_data *data);
int		is_resolution(char **args, t_data *data);

// add config
int		add_ambient_lighting(char **args, t_data *data);
int		add_light(char **args, t_data *data);
int		add_camera(char **args, t_data *data);
int		add_resolution(char	**args, t_data *data);

// add shape
int		add_plane(char **args, t_data *data);
int		add_sphere(char **args, t_data *data);
int		add_cylinder(char **args, t_data *data);

// get_scene_info
int		get_scene_info(t_data *data);
int		add_shape(t_gnl_token *gnl_token);
int		add_config(t_gnl_token *gnl_token);

// free configs
int		free_light(t_object *light);

// free shapes
int		free_cylinder(t_object *cylinder);
int		free_sphere(t_object *sphere);
int		free_plane(t_object *plane);

// gnl_token utils
t_gnl_token	*create_gnl_token(char **args);
t_gnl_token	*gnl_token_last(t_gnl_token *gnl_token);
void	add_gnl_token(t_gnl_token **gnl_tokens, char **args);
void	gnl_token_clear(t_gnl_token **gnl_tokens);

#endif
