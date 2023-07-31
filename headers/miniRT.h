/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:17:31 by gde-mora          #+#    #+#             */
/*   Updated: 2023/07/31 19:19:25 by gsmereka         ###   ########.fr       */
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
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"

// Shape Types
# define KEY_ESCAPE (0xff1b)
# define CYLINDER 1
# define PLANE 2
# define SPHERE 3
# define CAMERA 4
# define LIGHT 5
# define AMBIENT_LIGHTING 6

// Colors
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

void		test_matrices_operations(int argc, char **argv, t_data *data); // Retirar depois, do Makefile tb

// main functions
int			validate_scene_file(int argc, char *argv[], t_data *data);
int			read_scene_file(char *file, t_data *data);
void		get_scene_info(t_token *tokens, t_data *data);

// exit and utils
int			exit_error(char *msg, int status, t_data *data);
int			exit_successful(t_data *data);

// check_shape
int			is_plane(char **args, t_data *data);
int			is_sphere(char **args, t_data *data);
int			is_cylinder(char **args, t_data *data);

// check_config
int			is_ambient_lighting(char **args, t_data *data);
int			is_light(char **args, t_data *data);
int			is_camera(char **args, t_data *data);
int			is_resolution(char **args, t_data *data);

// check_utils
int			is_coordinate(char *arg);
int			is_normalized_vector(char *arg);
int			is_color(char *arg);

// add shape
int			add_plane(t_token *token, t_data *data);
int			add_sphere(t_token *token, t_data *data);
int			add_cylinder(t_token *token, t_data *data);

// add config
int			add_ambient_lighting(t_token *token, t_data *data);
int			add_light(t_token *token, t_data *data);
int			add_camera(t_token *token, t_data *data);
int			add_resolution(char	**args, t_data *data);

// render
void		render(t_data *data);
void		paint_pixel(int x, int y, unsigned int color, t_data *data);
int			handle_esc(int key, t_data *data);
int			handle_x(t_data *data);

// tools
int		are_floats_equal(double one, double two);
int		are_tuples_equal(t_tuple *one, t_tuple *two);
int		free_array(void **array);
double	atod(const char *str);
void	pass_tuple_values(t_tuple *dest, t_tuple *src);

// tuples operations
t_tuple	*sum_tuples(t_tuple *one, t_tuple *two);
t_tuple	*subtract_tuples(t_tuple *one, t_tuple *two);
t_tuple	*reverse_tuple(t_tuple *tuple);
t_tuple	*multiply_tuple(t_tuple *tuple, double factor);
t_tuple	*divide_tuple(t_tuple *tuple, double factor);
void	normalize_tuple(t_tuple *tuple);
double	tuple_magnitude(t_tuple *tuple);
double	dot_product(t_tuple *one, t_tuple *two);
t_tuple	*cross_product(t_tuple *one, t_tuple *two);

// color operations
t_color	*sum_colors(t_color *one, t_color *two);
t_color	*subtract_colors(t_color *one, t_color *two);
t_color	*multiply_color_scalar(t_color *color, double factor);
t_color	*multiply_color_x_color(t_color *one, t_color *two);

// matrix_tools
void		init_idmatrices(t_data *data);
t_matrix	*str_to_matrix(char *str);
t_matrix	*create_matrix(double **content, int cols);
void		print_matrix(t_matrix *matrix_struct); // retirara depois
void		free_matrix(t_matrix *matrix);
int			matrices_have_diff(t_matrix *a, t_matrix *b);
t_matrix	*multiply_matrices(t_matrix *a, t_matrix *b);
t_matrix	*transposing_matrix(t_matrix *mat);
t_tuple		*multiply_matrix_with_tuple(t_matrix *matrix, t_tuple *tuple);
t_matrix	*get_submatrix(t_matrix *matrix, int row, int col);
double		get_determinant(t_matrix *matrix);
double		get_cofactor(t_matrix *matrix, int row, int col);
t_matrix	*inverting_matrix(t_matrix *matrix);

// token utils
t_token		*create_token(char **args);
t_token		*token_last(t_token *token);
void		add_token(t_token **tokens, char **args);
void		token_clear(t_token **tokens);

#endif
