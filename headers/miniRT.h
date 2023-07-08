/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:17:31 by gde-mora          #+#    #+#             */
/*   Updated: 2023/07/08 00:13:19 by gsmereka         ###   ########.fr       */
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
# define CYLINDER 1
# define PLANE 2
# define SPHERE 3
# define CAMERA 4
# define LIGHT 5
# define AMBIENT_LIGHTING 6

// main functions
int		validate_scene_file(int argc, char *argv[], t_data *data);
int		read_scene_file(char *file, t_data *data);
void	get_scene_info(t_token *tokens, t_data *data);
void	render(t_data *data);

// exit and utils
int		exit_error(char *msg, int status, t_data *data);
int		exit_successful(t_data *data);

// check_shape
int		is_plane(char **args, t_data *data);
int		is_sphere(char **args, t_data *data);
int		is_cylinder(char **args, t_data *data);

// check_config
int		is_ambient_lighting(char **args, t_data *data);
int		is_light(char **args, t_data *data);
int		is_camera(char **args, t_data *data);
int		is_resolution(char **args, t_data *data);

// check_utils
int		is_coordinate(char *arg);
int		is_normalized_vector(char *arg);
int		is_color(char *arg);

// add shape
int		add_plane(t_token *token, t_data *data);
int		add_sphere(t_token *token, t_data *data);
int		add_cylinder(t_token *token, t_data *data);

// add config
int		add_ambient_lighting(t_token *token, t_data *data);
int		add_light(t_token *token, t_data *data);
int		add_camera(t_token *token, t_data *data);
int		add_resolution(char	**args, t_data *data);

// tools
int		are_floats_equal(double one, double two);
int		are_tuples_equal(t_tuple *one, t_tuple *two);
int		free_array(void **array);
double	atod(const char *str);

// tuples operations
t_tuple	*sum_tuples(t_tuple *one, t_tuple *two);
t_tuple	*subtract_tuples(t_tuple *one, t_tuple *two);
t_tuple	*reverse_tuple(t_tuple *tuple);

// token utils
t_token	*create_token(char **args);
t_token	*token_last(t_token *token);
void	add_token(t_token **tokens, char **args);
void	token_clear(t_token **tokens);

#endif
