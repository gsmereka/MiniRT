/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:16:42 by gde-mora          #+#    #+#             */
/*   Updated: 2023/06/28 21:30:39 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	main(int argc, char **argv)
{
	t_data data;

	ft_bzero(&data, sizeof(data));
	validate_scene_file(argc, argv);
	render(&data);
	return (0);
}
