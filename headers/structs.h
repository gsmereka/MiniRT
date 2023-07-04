/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:09:51 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/03 23:45:54 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// ## RGB
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_tuple
{
	int				x;
	int				y;
	int				z;
	int				c;
}	t_tuple;

typedef struct s_ambient_lighting
{
	double						ratio;
	t_color						color;
}	t_ambient_lighting;

typedef struct s_camera
{
	struct s_tuple	coordinate;
	struct s_tuple	normalized_vector;
	int				fov;
}	t_camera;             

typedef struct s_light
{
	struct s_tuple	coordinate;
	struct s_tuple	normalized_vector;
	struct s_color	color;
	double			brightness;
	struct s_light	*next;
}	t_light;

typedef struct s_cylinder
{
	struct s_tuple		coordinate;
	struct s_tuple		normalized_vector;
	double				diameter;
	double				height;
	struct s_color		color;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_sphere
{
	struct s_tuple		coordinate;
	double				diameter;
	struct s_color		color;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	struct s_tuple		coordinate;
	struct s_tuple		normalized_vector;
	struct s_color		color;
	struct s_plane		*next;
}	t_plane;

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