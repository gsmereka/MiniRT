/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:09:51 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/06 22:04:49 by gsmereka         ###   ########.fr       */
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
	double	x;
	double	y;
	double	z;
	double	c;
}	t_tuple;

typedef struct s_token
{
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

typedef struct s_data
{
	t_token	*tokens;
	int		scene_fd;
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_height;
	int		win_width;
	void	*img;
	char	*address_img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		has_camera;
	int		has_light;
	int		has_ambient_lighting;
	int										debug_exit; //Enqunto fazemos os testes
}	t_data;

#endif