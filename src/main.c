/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:16:42 by gde-mora          #+#    #+#             */
/*   Updated: 2023/06/29 03:13:52 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	main(int argc, char **argv)
{
	t_data data;

	ft_bzero(&data, sizeof(data));
	init_data(&data);
	validate_scene_file(argc, argv);
	render(&data);
	return (0);
}
