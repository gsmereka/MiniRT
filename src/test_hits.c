/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:14:23 by gsmereka          #+#    #+#             */
/*   Updated: 2023/09/23 02:27:05 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	test_hits(t_data *data)
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


	// 1 Scenario: The hit, when all intersections have positive t
	sphere = data->tokens;
	while (sphere->type != SPHERE)
		sphere = sphere->next;

	inter_list = NULL;
	add_intersection(&inter_list, 1, sphere);  // i1 ← intersection(1, s)
	add_intersection(&inter_list, 2, sphere);  // i2 ← intersection(2, s)
	xs = intersections_xs(inter_list); //return intersect struct

	printf("Esste teste (./test_hits.c) está na pagina 85/286\n");
	// When i ← hit(xs) o que essa função hit significa ?????
	// Then i = i1





	// // 2 Scenario: The hit, when some intersections have negative t
	// sphere = data->tokens;
	// while (sphere->type != SPHERE)
	// 	sphere = sphere->next;

	// inter_list = NULL;
	// add_intersection(&inter_list, -1, sphere);  // i1 ← intersection(-1, s)
	// add_intersection(&inter_list, 1, sphere);  // i2 ← intersection(1, s)
	// xs = intersections(inter_list); //return intersect struct

	// // When i ← hit(xs)
	// // Then i = i2





	// // 3 Scenario: The hit, when all intersections have negative t
	// sphere = data->tokens;
	// while (sphere->type != SPHERE)
	// 	sphere = sphere->next;

	// inter_list = NULL;
	// add_intersection(&inter_list, -2, sphere);  // i1 ← intersection(-2, s)
	// add_intersection(&inter_list, -1, sphere);  // i2 ← intersection(-1, s)
	// xs = intersections(inter_list); //return intersect struct

	// // When i ← hit(xs)
	// // Then i is nothing



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

	free_intersection_list(inter_list);
}
