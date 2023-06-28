/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:06:05 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/28 16:19:06 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	exit_error(int error, int status, t_data *data)
{
	error_msg(error);
	(void)data;
	// free_data(data)
	exit(status);
}
