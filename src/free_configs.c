/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_configs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:03:01 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/04 00:05:14 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	free_camera(t_camera *camera)
{
	// if (camera->next)
	// 	free_camera(next);
	free(camera);
	camera = NULL;
	return (0);
}
