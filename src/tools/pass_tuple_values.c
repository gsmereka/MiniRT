/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_tuple_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:36 by gde-mora          #+#    #+#             */
/*   Updated: 2023/07/24 20:02:20 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	pass_tuple_values(t_tuple *dest, t_tuple *src) //colocar no makefile e header
{
	dest->x = src->x;
	dest->y = src->y;
	dest->z = src->z;
	dest->w = src->w;
}
