/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:17:31 by gde-mora          #+#    #+#             */
/*   Updated: 2023/06/30 02:09:36 by gsmereka         ###   ########.fr       */
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
int		validate_scene_file(int argc, char *argv[], t_data *data);
int		exit_error(char *msg, int status, t_data *data);
int		exit_successful(t_data *data);
int		init_data(t_data *data);

int		free_array(void **array);

// token utils
t_token	*create_token(char **args);
t_token	*token_last(t_token *token);
void	add_token(t_token **tokens, char **args);
void	token_clear(t_token **tokens);

#endif
