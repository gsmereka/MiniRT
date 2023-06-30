/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:36:42 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/29 22:16:49 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	check_file_extension(char *file, t_data *data);

int	validate_scene_file(int argc, char *argv[], t_data *data)
{
	int		fd;

	if (argc != 2)
		exit_error(COUNT_ERROR, 2, data);
	check_file_extension(argv[1], data);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		exit_error(OPEN_FILE_ERROR, 2, data);
	// ler todo o arquivo com a gnl, dessa forma não vai vazar memoria.
	ft_printf("Validando\n");
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
