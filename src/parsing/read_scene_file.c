/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:36:42 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/06 18:38:11 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	turn_white_spaces_on_spaces(char *line);

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
		turn_white_spaces_on_spaces(line);
		args = ft_split(line, ' ');
		free(line);
		if (args && args[0])
			add_token(&data->tokens, args);
		if (!args[0])
			free_array((void **)args);
		line = get_next_line(data->scene_fd);
	}
	close(data->scene_fd);
	return (0);
}

void	turn_white_spaces_on_spaces(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return ;
	while (line[i])
	{
		if (line[i] >= '\t' && line[i] <= '\r')
			line[i] = ' ';
		i++;
	}
}
