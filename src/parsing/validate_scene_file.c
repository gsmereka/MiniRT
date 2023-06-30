/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:36:42 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/30 18:54:01 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	check_if_is_just_one_file(int argc, t_data *data);
int	check_file_extension(char *file, t_data *data);
int	read_file(char *file, t_data *data);

int	validate_scene_file(int argc, char *argv[], t_data *data)
{
	check_if_is_just_one_file(argc, data);
	check_file_extension(argv[1], data);
	return (0);
}

int	check_if_is_just_one_file(int argc, t_data *data)
{
	if (argc != 2)
		exit_error(COUNT_ERROR, 2, data);
	return (0);
}

int	check_file_extension(char *file, t_data *data)
{
	char	*last_three_chars;
	int		last_three_chars_index;

	last_three_chars_index = ft_strlen(file) - 3;
	if (last_three_chars_index < 0)
		exit_error(FILE_EXTENSION_ERROR, 2, data);
	last_three_chars = file + last_three_chars_index;
	if (ft_strncmp(last_three_chars, ".rt", 3) != 0)
		exit_error(FILE_EXTENSION_ERROR, 2, data);
	return (0);
}
