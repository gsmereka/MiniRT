/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:14:23 by gsmereka          #+#    #+#             */
/*   Updated: 2023/09/22 22:11:25 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	test_intersection(t_data *data)
{
	t_token			*sphere;
	double			time;
	t_intersection	*inter_list;
	t_intersect		xs;

	(void)sphere;
	(void)time;
	(void)inter_list;
	(void)xs;

	// teste 1
	
	// sphere = data->tokens;
	// while (sphere->type != 3)
	// 	sphere = sphere->next;
	// time = 3.5;
	// inter_list = create_intersection(time, sphere);
	// printf("%lf\n", inter_list->time);
	// if (inter_list->object->type == 3)
	// 	printf("ESFERA!\n");
	// else
	// 	printf("ERROU\n");
	// free_intersection_list(inter_list);

	// teste 2
	sphere = data->tokens;
	while (sphere->type != 3)
		sphere = sphere->next;
	inter_list = NULL;
	add_intersection(inter_list, 1, sphere); //lista de interseções para passar p o intersections  (em ordem?)
	add_intersection(inter_list, 2, sphere);

	xs = intersections(inter_list); //return intersect struct
	printf("%d\n", xs.count);
	printf("%lf\n", xs.intersect_times[0]);
	printf("%lf\n", xs.intersect_times[1]);
	//free_intersection_list(inter_list);
}
