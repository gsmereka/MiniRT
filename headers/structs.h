/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:09:51 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/03 18:51:37 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define MATRIX_SIZE 4

// ## RGB
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
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
	int				id;
	int				size;
	char			**args;
	int				type;
	struct s_tuple	coordinate;
	struct s_tuple	normalized_vector;
	struct s_color	color;
	double			diameter;
	double			height;
	double			brightness;
	int				fov;
	double			ratio;
	struct s_token	*next;
}	t_token;

typedef struct s_matrix
{
	double	content[MATRIX_SIZE][MATRIX_SIZE];
	double	determinant;
	int		cols;
	int		rows;
}	t_matrix;

////////////////////////////////////////////// teste

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_CAMERA
{
	t_tuple		center;
	t_tuple		radians_vector;
	int			width;
	int			height;
	double		focal_length;
	t_matrix	direction;
	t_tuple		right;
	t_tuple		up;
	t_tuple		front;
	double		fov;
}  t_CAMERA;

typedef struct s_HIT
{
	t_tuple		position;
	t_token		*object;
	t_tuple		normal;
	double		distance;
}  t_HIT;

typedef struct s_POINTLIGHT
{
	t_tuple		position;
	double		intensity;
}  t_POINTLIGHT;

typedef struct s_SCENE
{
	t_ray			*object_ray;
	t_ray			*light_ray;
	t_tuple			background;
	double			ambient_light;
	int				luzes_a_definir; // numero a definir;
	int				objetos_a_definir; // numero a definir
	t_POINTLIGHT	**lights; // numero a definir
	t_token			**objects; // numero a definir		
}  t_SCENE;

///////////////////////////////////////////////////////////////////////////

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
	int										debug_exit; //Enqunto fazemos os testes

	t_CAMERA	*camera; // teste
	t_SCENE		*scene; // teste
}	t_data;

#endif