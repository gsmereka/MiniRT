/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_endpoints_cylinder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:43:46 by gde-mora          #+#    #+#             */
/*   Updated: 2024/02/17 19:01:25 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	set_endpoints_cylinder(t_token *cylinder)
{
	t_tuple direction1 = create_vector(1, 0, 0); // Primeira direção
    t_tuple direction2 = create_vector(0, 1, 0); // Segunda direção

    // Vamos calcular o vetor que aponta ao longo do eixo do cilindro como o produto cruzado dessas direções
    t_tuple cylinder_axis = cross_product(&direction1, &direction2);
	
    // Normalizamos o vetor do eixo do cilindro
    double length = sqrt(cylinder_axis.x * cylinder_axis.x + cylinder_axis.y * cylinder_axis.y + cylinder_axis.z * cylinder_axis.z);
    cylinder_axis.x /= length;
    cylinder_axis.y /= length;
    cylinder_axis.z /= length;

    // Agora podemos calcular as extremidades do cilindro usando o eixo calculado
    cylinder->endpoint1 = create_point(cylinder->coordinate.x - cylinder_axis.x * cylinder->height / 2, cylinder->coordinate.y - cylinder_axis.y * cylinder->height / 2, cylinder->coordinate.z - cylinder_axis.z * cylinder->height / 2);
    cylinder->endpoint2 = create_point(cylinder->coordinate.x + cylinder_axis.x * cylinder->height / 2, cylinder->coordinate.y + cylinder_axis.y * cylinder->height / 2, cylinder->coordinate.z + cylinder_axis.z * cylinder->height / 2);
}
