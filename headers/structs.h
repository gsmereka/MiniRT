/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:09:51 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/29 22:26:37 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_token
{
	char			*line;
	char			**args;
	struct s_token	*next;
}	t_token;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*address_img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_data;

#endif