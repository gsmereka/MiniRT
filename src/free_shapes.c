/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:03:04 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/04 10:52:17 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	free_cylinder(t_cylinder *cylinder)
{
	if (cylinder->next)
		free_cylinder(cylinder->next);
	free(cylinder);
	cylinder = NULL;
	return (0);
}

int	free_sphere(t_sphere *sphere)
{
	if (sphere->next)
		free_sphere(sphere->next);
	free(sphere);
	sphere = NULL;
	return (0);
}

int	free_plane(t_plane *plane)
{
	if (plane->next)
		free_plane(plane->next);
	free(plane);
	plane = NULL;
	return (0);
}
