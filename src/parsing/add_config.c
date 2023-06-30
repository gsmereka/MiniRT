/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:41:28 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/30 15:18:13 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	add_config(t_token *token)
{
	if (is_camera(token->args))
	{
		ft_printf("is_camera\n");
	}
	if (is_ambient_lighting(token->args))
	{
		ft_printf("is_ambient_lighting\n");
	}
	if (is_light(token->args))
	{
		ft_printf("is_light\n");
	}
	if (is_resolution(token->args))
	{
		ft_printf("is_resolution\n");
	}
	return (0);
}
