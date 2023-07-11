/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:04:09 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/10 22:04:58 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	handle_esc(int key, t_data *data)
{
	if (key == KEY_ESCAPE)
		exit_successful(data);
	return (0);
}

int	handle_x(t_data *data)
{
	exit_successful(data);
	return (0);
}
