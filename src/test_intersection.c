/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:14:23 by gsmereka          #+#    #+#             */
/*   Updated: 2023/09/23 01:24:25 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	test_intersection(t_data *data)
{
	t_token			*sphere;
	double			time;
	t_intersection	*inter_list;
	t_intersect		xs;
	t_tuple			origin;
	t_tuple			direction;
	t_ray			ray;

	(void)sphere;
	(void)time;
	(void)inter_list;
	(void)xs;
	(void)origin;
	(void)direction;
	(void)ray;
	(void)data;

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
	
	// sphere = data->tokens;
	// while (sphere->type != 3)
	// 	sphere = sphere->next;
	// inter_list = NULL;
	// add_intersection(&inter_list, 1, sphere); //lista de interseções para passar p o intersections  (em ordem?)
	// add_intersection(&inter_list, 2, sphere);

	// xs = intersections(inter_list); //return intersect struct
	// printf("%d\n", xs.count);
	// printf("%lf\n", xs.intersect_times[0]);
	// printf("%lf\n", xs.intersect_times[1]);
	// free_intersection_list(inter_list);

	
	// teste 3
	
	// origin = create_point(0, 0, -5);
	// direction = create_vector(0, 0, 1);
	// ray = create_ray(&origin, &direction);
	// sphere = data->tokens;
	// while (sphere->type != 3)
	// 	sphere = sphere->next;
	// xs = intersect(sphere, &ray);
	// printf("%d\n", xs.count);
	// printf("%lf\n", xs.intersect_times[0]);
	// printf("%lf\n", xs.intersect_times[1]);
	// if (xs.objects[0].type == 3)
	// 	printf("XS 0 is SPHERE\n");
	// if (xs.objects[1].type == 3)
	// 	printf("XS 1 is SPHERE\n");


	// teste especial

	sphere = data->tokens;
	while (sphere->type != 3)
		sphere = sphere->next;
	inter_list = NULL;
	
	add_intersection(&inter_list, 2, sphere);
	add_intersection(&inter_list, 1, sphere);
	
	 //lista de interseções para passar p o intersections  (em ordem?)
	

	xs = intersections(inter_list); //return intersect struct
	printf("%ld\n", inter_list->size_list_first_node_only);
	// printf("%d\n", xs.count);
	// printf("%lf\n", xs.intersect_times[0]);
	// printf("%lf\n", xs.intersect_times[1]); // Caso so exista uma intersect, o valor de um dos tempos vai ser 0. ISSO PODE DAR PROBLEMA ????
	// if (xs.objects[0].type == 3)
	// 	printf("XS 0 is SPHERE\n");
	// if (xs.objects[1].type == 3)
	// 	printf("XS 1 is SPHERE\n");
	free_intersection_list(inter_list);
}
