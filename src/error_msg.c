/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:47:18 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/28 16:00:28 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	error_msg(int error)
{
	if (error == 1)
	{
		ft_printf("Error\nOnly one file allowed\n");
	}
	if (error == 2)
	{
		ft_printf("Error\nOnly files with the '.rt' extension allowed\n");
	}
	return (0);
}
