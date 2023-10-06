/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:14:23 by gsmereka          #+#    #+#             */
/*   Updated: 2023/10/06 18:50:49 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	test_hits(t_data *data)
{
	t_token			*sphere;
	double			time;
	t_intersection	*inter_list;
	t_intersection	*result;
	t_intersect		xs;
	t_tuple			origin;
	t_tuple			direction;
	t_ray			ray;
	t_intersection	*aux;

	(void)aux;
	(void)result;
	(void)sphere;
	(void)time;
	(void)inter_list;
	(void)xs;
	(void)origin;
	(void)direction;
	(void)ray;
	(void)data;
	
	
	// 1 Scenario: The hit, when all intersections have positive t
	// sphere = data->tokens;
	// while (sphere->type != SPHERE)
	// 	sphere = sphere->next;

	// inter_list = NULL;
	// add_intersection(&inter_list, 1, sphere);  // i1 ← intersection(1, s)
	// add_intersection(&inter_list, 2, sphere);  // i2 ← intersection(2, s)
	// xs = intersections_xs(inter_list); // return intersect struct
	// result = hit(&xs); //            result é o i1
	// printf("%lf %lf\n", inter_list->time, result->time);
	// if (inter_list->object->type == 3)
	// 	printf("i1 0 is SPHERE\n");
	// if (result->object->type == 3)
	// 	printf("result 1 is SPHERE\n");
	// free_intersection_list(result);	



	// // 2 Scenario: The hit, when some intersections have negative t
	// sphere = data->tokens;
	// while (sphere->type != SPHERE)
	// 	sphere = sphere->next;

	// inter_list = NULL;
	// add_intersection(&inter_list, -1, sphere);  // i1 ← intersection(-1, s)
	// add_intersection(&inter_list, 1, sphere);  // i2 ← intersection(1, s)
	// xs = intersections_xs(inter_list); //return intersect struct
	// result = hit(&xs); // result é o i2
	// aux = inter_list;
	// while (aux->time < 0)
	// 	aux = aux->next;
	// if (aux)
	// {	
	// 	printf("%lf %lf\n", aux->time, result->time);
	// 	if (aux->object->type == 3)
	// 		printf("i2 0 is SPHERE\n");
	// 	if (result->object->type == 3)
	// 		printf("result 1 is SPHERE\n");
	// }
	// free_intersection_list(result);	





	// // 3 Scenario: The hit, when all intersections have negative t
	sphere = data->tokens;
	while (sphere->type != SPHERE)
		sphere = sphere->next;

	inter_list = NULL;
	add_intersection(&inter_list, -2, sphere);  // i1 ← intersection(-2, s)
	add_intersection(&inter_list, -1, sphere);  // i2 ← intersection(-1, s)
	xs = intersections_xs(inter_list); //return intersect struct
	result = hit(&xs); // result é o i2
	aux = inter_list;
	while (aux && aux->time < 0)
	 	aux = aux->next;
	if (!result)
		printf("sem result\n");
	if (aux && result)
	{	
		printf("%lf %lf\n", aux->time, result->time);
		if (aux->object->type == 3)
			printf("i2 0 is SPHERE\n");
		if (result->object->type == 3)
			printf("result 1 is SPHERE\n");
		free_intersection_list(result);	
	}
	



	// // 4 Scenario: The hit is always the lowest nonnegative intersection
	// sphere = data->tokens;
	// while (sphere->type != SPHERE)
	// 	sphere = sphere->next;

	// inter_list = NULL;
	// add_intersection(&inter_list, 5, sphere);  // i1 ← intersection(5, s)
	// add_intersection(&inter_list, 7, sphere);  // i2 ← intersection(7, s)
	// add_intersection(&inter_list, -3, sphere);  // i3 ← intersection(-3, s)
	// add_intersection(&inter_list, 2, sphere);  // i4 ← intersection(2, s)
	// xs = intersections(inter_list); //return intersect struct

	// // And xs ← intersections(i1, i2, i3, i4)
	// // When i ← hit(xs)
	// Then i = i4
	free(xs.intersect_times);
	free(xs.objects);
	free_intersection_list(inter_list);
}
