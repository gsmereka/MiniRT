/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:17:31 by gde-mora          #+#    #+#             */
/*   Updated: 2023/07/03 18:59:19 by gsmereka         ###   ########.fr       */
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
int		add_shape(t_token *token);
int		add_config(t_token *token);

// token utils
t_token	*create_token(char **args);
t_token	*token_last(t_token *token);
void	add_token(t_token **tokens, char **args);
void	token_clear(t_token **tokens);

#endif
