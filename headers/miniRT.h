/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:17:31 by gde-mora          #+#    #+#             */
/*   Updated: 2023/06/28 21:09:44 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include "../libft/libft.h"

# define KEY_ESCAPE (0xff1b)

/*typedef struct s_mlx_render
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_render;*/

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

void	render(t_data *data);
int		validate_scene_file(int argc, char *argv[]);

#endif