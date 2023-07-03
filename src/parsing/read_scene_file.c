/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:36:42 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/30 18:52:16 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	read_scene_file(char *file, t_data *data)
{
	char	*line;
	char	**args;

	data->scene_fd = open(file, O_RDWR);
	if (data->scene_fd < 0)
		exit_error(OPEN_FILE_ERROR, 2, data);
	line = get_next_line(data->scene_fd);
	while (line)
	{
		args = ft_split(line, ' ');
		free(line);
		if (args)
			add_token(&data->tokens, args);
		line = get_next_line(data->scene_fd);
	}
	close(data->scene_fd);
	return (0);
}
