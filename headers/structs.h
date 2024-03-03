/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:09:51 by gsmereka          #+#    #+#             */
/*   Updated: 2024/03/03 00:58:01 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define MATRIX_SIZE 4

// ## RGB
typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef struct s_token
{
	char			**args;
	int				type;
	struct s_tuple	coordinate;
	struct s_tuple	normalized_3d_direction;
	struct s_color	color;
	double			diameter;
	double			max;
	double			min;
	double			lighting_ratio;
	double			height;
	int				fov;
	struct s_token	*next;
}	t_token;

typedef struct s_matrix
{
	double	content[MATRIX_SIZE][MATRIX_SIZE];
	double	determinant;
	int		cols;
	int		rows;
}	t_matrix;

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_camera
{
	t_tuple		center;
	t_tuple		radians_vector;
	int			width;
	int			height;
	double		focal_length;
	double		aspect_ratio;
	t_tuple		right;
	t_tuple		up;
	t_tuple		front;
	double		fov;
}	t_camera;

typedef struct s_hit
{
	t_tuple		position;
	t_token		*object;
	t_tuple		normal;
	double		distance;
}	t_hit;

typedef struct s_scene
{
	t_ray			*object_ray;
	t_ray			*light_ray;
	t_color			ambient_color;
	double			ambient_light;
	t_token			**lights;
	t_token			**objects;
}	t_scene;

typedef struct s_data
{
	t_matrix	idmatrix_2x2;
	t_matrix	idmatrix_3x3;
	t_matrix	idmatrix_4x4;
	t_token		*tokens;
	int			scene_fd;
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_height;
	int			win_width;
	void		*img;
	char		*address_img;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			has_camera;
	int			has_light;
	int			has_ambient_lighting;
	int			lights_size;
	int			objects_size;
	t_camera	*camera;
	t_scene		*scene;
}	t_data;

#endif