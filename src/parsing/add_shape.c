/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:42:10 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/30 15:18:54 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	add_shape(t_token *token)
{
	if (is_cylinder(token->args))
	{
		ft_printf("is_cylinder\n");
	}
	if (is_sphere(token->args))
	{
		ft_printf("is_sphere\n");
	}
	if (is_plane(token->args))
	{
		ft_printf("is_plane\n");
	}
	return (0);
}
