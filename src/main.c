/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:16:42 by gde-mora          #+#    #+#             */
/*   Updated: 2024/03/03 03:31:44 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){0};
	validate_scene_file(argc, argv, &data);
	read_scene_file(argv[1], &data);
	get_scene_info(data.tokens, &data);
	define_scene(&data);
	render(&data);
	exit_error("", 0, &data);
	return (0);
}
