/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:09:51 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/03 17:28:14 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_tuple
{
	int				size;
	char			**args;
	struct s_tuple	*next;
}	t_tuple;

typedef struct s_camera
{
	int				size;
	char			**args;
	struct s_camera	*next;
}	t_camera;

typedef struct s_light
{
	int				size;
	char			**args;
	struct s_light	*next;
}	t_light;

typedef struct s_cylinder
{
	int					size;
	char				**args;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_sphere
{
	int				size;
	char			**args;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	int				size;
	char			**args;
	struct s_plane	*next;
}	t_plane;

typedef struct s_ambient_lighting
{
	t_color						color;
	double						ratio;
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