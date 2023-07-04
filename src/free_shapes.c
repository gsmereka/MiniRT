/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:03:04 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/05 00:48:27 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	free_cylinder(t_object *cylinder)
{
	if (cylinder->next)
		free_cylinder(cylinder->next);
	free(cylinder);
	ft_printf("oi");
	cylinder = NULL;
	return (0);
}

int	free_sphere(t_object *sphere)
{
	if (sphere->next)
		free_sphere(sphere->next);
	free(sphere);
	sphere = NULL;
	return (0);
}

int	free_plane(t_object *plane)
{
	if (plane->next)
		free_plane(plane->next);
	free(plane);
	plane = NULL;
	return (0);
}
