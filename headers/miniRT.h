/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:17:31 by gde-mora          #+#    #+#             */
/*   Updated: 2023/06/30 15:21:03 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./error_msg.h"
# include "./structs.h"
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define KEY_ESCAPE (0xff1b)

/*typedef struct s_mlx_render
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_render;*/

void	render(t_data *data);
int		read_scene_file(int argc, char *argv[], t_data *data);
int		exit_error(char *msg, int status, t_data *data);
int		exit_successful(t_data *data);
int		init_data(t_data *data);

int		free_array(void **array);

// check_shape
int		is_plane(char **args);
int		is_sphere(char **args);
int		is_cylinder(char **args);

// check_config
int		is_ambient_lighting(char **args);
int		is_light(char **args);
int		is_camera(char **args);
int		is_resolution(char **args);

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
