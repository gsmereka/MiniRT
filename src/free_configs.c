/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_configs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:03:01 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/04 00:09:30 by gsmereka         ###   ########.fr       */
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

int	free_light(t_light *light)
{
	// if (light->next)
	// 	free_light(next);
	free(light);
	light = NULL;
	return (0);
}
