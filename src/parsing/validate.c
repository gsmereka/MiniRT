/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:36:42 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/29 13:12:15 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int	validate_scene_file(int argc, char *argv[], t_data *data)
{
	(void)data;
	if (argc != 2)
		exit_error(COUNT_ERROR, 2, NULL);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3) != 0)
		exit_error(FILE_EXTENSION_ERROR, 2, NULL);
	// ler todo o arquivo com a gnl, dessa forma não vai vazar memoria.
	ft_printf("Validando\n");
	return (0);
}
