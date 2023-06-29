/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:36:42 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/29 13:55:43 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	validate_scene_file(int argc, char *argv[], t_data *data)
{
	int	fd;

	(void)data;
	if (argc != 2)
		exit_error(COUNT_ERROR, 2, data);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3) != 0)
		exit_error(FILE_EXTENSION_ERROR, 2, data);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		exit_error(OPEN_FILE_ERROR, 2, data);
	// ler todo o arquivo com a gnl, dessa forma não vai vazar memoria.
	ft_printf("Validando\n");
	return (0);
}
