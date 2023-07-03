/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:09:51 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/03 21:04:10 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_tuple
{
	int				x;
	int				y;
	int				z;
	int				c;
}	t_tuple;

typedef struct s_camera
{
	int				size;
	char			**args;
	struct s_tuple	tuple;
	struct s_camera	*next;
}	t_camera;

//typedef struct s_color                RGB

typedef struct s_light
{
	int				size;
	char			**args;
	struct s_tuple	tuple;
	struct s_light	*next;
}	t_light;

typedef struct s_cylinder
{
	int					size;
	char				**args;
	struct s_tuple		tuple;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_sphere
{
	int				size;
	char			**args;
	struct s_tuple	tuple;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	int				size;
	char			**args;
	struct s_tuple	tuple;
	struct s_plane	*next;
}	t_plane;

typedef struct s_ambient_lighting
{
	int							size;
	char						**args;
	struct s_tuple				tuple;
	struct s_ambient_lighting	*next;
}	t_ambient_lighting;

typedef struct s_token
{
	int				size;
	char			**args;
	struct s_token	*next;
}	t_token;

typedef struct s_data
{
	t_ambient_lighting	*ambient_lighting;
	t_light				*light;
	t_camera			*camera;
	t_sphere			*sphere;
	t_plane				*plane;
	t_cylinder			*cylinder;
	t_token				*tokens;
	int					scene_fd;
	void				*mlx_ptr;
	void				*win_ptr;
	int					win_height;
	int					win_width;
	void				*img;
	char				*address_img;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}	t_data;

#endif