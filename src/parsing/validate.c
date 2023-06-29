/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:36:42 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/29 14:38:56 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	validate_scene_file(int argc, char *argv[], t_data *data)
{
	int		fd;
	char	*file_last_three_chars;
	int		file_last_three_chars_index;

	if (argc != 2)
		exit_error(COUNT_ERROR, 2, data);
	file_last_three_chars_index = ft_strlen(argv[1]) - 3;
	if (file_last_three_chars_index < 0)
		exit_error(FILE_EXTENSION_ERROR, 2, data);
	file_last_three_chars = argv[1] + file_last_three_chars_index;
	if (ft_strncmp(file_last_three_chars, ".rt", 3) != 0)
		exit_error(FILE_EXTENSION_ERROR, 2, data);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		exit_error(OPEN_FILE_ERROR, 2, data);
	// ler todo o arquivo com a gnl, dessa forma não vai vazar memoria.
	ft_printf("Validando\n");
	return (0);
}
