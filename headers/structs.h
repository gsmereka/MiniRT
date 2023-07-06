/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:09:51 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/05 22:37:23 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	double	c;
}	t_tuple;

typedef struct s_object
{
	char			*type;
	struct s_tuple	coordinate;
	struct s_tuple	normalized_vector;
	struct s_color	color;
	double			diameter;
	double			height;
	double			brightness;
	int				fov;
	double			ratio;
	struct s_object	*next;
}	t_object;

typedef struct s_gnl_token
{
	int					size;
	char				**args;
	struct s_gnl_token	*next;
}	t_gnl_token;

typedef struct s_data
{
	t_object	*ambient_lighting;
	t_object	*light;
	t_object	*camera;
	t_object	*sphere;
	t_object	*plane;
	t_object	*cylinder;
	t_gnl_token	*gnl_tokens;
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
	int										debug_exit; //Enqunto fazemos os testes
}	t_data;

#endif