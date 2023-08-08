/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:09:42 by gsmereka          #+#    #+#             */
/*   Updated: 2023/08/08 18:10:25 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

int dtoi(double num)
{
	int 	inum;
	double	aux;

	inum = (int)num;
	aux = num - inum;
	if (aux > 0.5)
		inum++;
	return (inum);
}
