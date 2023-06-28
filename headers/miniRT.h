/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:17:31 by gde-mora          #+#    #+#             */
/*   Updated: 2023/06/28 16:18:53 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "./error_msg.h"
# include "../libft/libft.h"

typedef struct s_data
{
	int	sim;
	int	nao;
}	t_data;

int		validate_scene_file(int argc, char *argv[]);
int		exit_error(int error, int status, t_data *data);
int		error_msg(int error);

#endif
