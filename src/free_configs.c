/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_configs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:03:01 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/05 00:42:22 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	free_light(t_object *light)
{
	if (light->next)
		free_light(light->next);
	free(light);
	light = NULL;
	return (0);
}
