/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:13:32 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/30 15:27:20 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	add_config_and_shapes(t_data *data);

int	get_scene_info(t_data *data)
{
	add_config_and_shapes(data);
	return (0);
}

int	add_config_and_shapes(t_data *data)
{
	t_token	*token;

	token = data->tokens;
	while (token)
	{
		add_config(token);
		add_shape(token);
		token = token->next;
	}
	return (0);
}
