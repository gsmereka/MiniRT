/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:57:01 by gde-mora          #+#    #+#             */
/*   Updated: 2023/09/08 19:40:08 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	test_ray(t_data *data)
{
	// t_tuple	*origin;
	// t_tuple	*direction;
	t_ray	r;
	//t_tuple	*point;

	(void)data;
	(void)r;
	// teste 1
	// origin = create_point(1, 2, 3);
	// direction = create_vector(4, 5, 6);
	// r = create_ray(origin, direction);
	
	// print_tuple(r.origin);
	// print_tuple(r.direction);
	// free(origin);
	// free(direction);

	// teste 2
	// r = create_ray(create_point(2, 3, 4), create_vector(1, 0, 0));
	
	// point = position(&r, 0); //point(2, 3, 4)
	// print_tuple(point);
	// free(point);
	
	// point = position(&r, 1); //point(3, 3, 4)
	// print_tuple(point);
	// free(point);
	
	// point = position(&r, -1); //point(1, 3, 4)
	// print_tuple(point);
	// free(point);
	
	// point = position(&r, 2.5); //point(4.5, 3, 4)
	// print_tuple(point);
	// free(point);

	// free(r.origin);
	// free(r.direction);

	
	//teste 3 -- incompleto
	// t_sphere	sphere;
	// t_intersect	xs;
	// t_tuple	point_menos_cinco;
	// t_tuple	vector_one;
	
	// vector_one = create_vector(0, 0, 1);
	// point_menos_cinco = create_point(0, 0, -5);
	// r = create_ray(&point_menos_cinco, &vector_one);
	// sphere.origin = create_point(0, 0, 0);
	// sphere.raio = 1;
	
	// xs = intersect(&sphere, &r);
	// printf("%d\n", xs.count); // = 2
	// printf("%lf ", xs.intersect_times[0]); // = 4.0
	// printf("%lf\n", xs.intersect_times[1]); // = 6.0
	// // // free(r.origin);
	// // // free(r.direction);
	// // exit_error("", 0, data);






	// teste 4
	// t_token	*sphere;
	// t_intersect	xs;
	// t_tuple	point;
	// t_tuple	vector;
	
	// sphere = data->tokens;
	// point = create_point(0, 2, -5);
	// vector = create_vector(0, 0, 1);
	// r = create_ray(&point, &vector);
	// // sphere.origin = create_point(0, 0, 0);
	// // sphere.raio = 1;
	
	// xs = intersect(sphere, &r);
	// printf("%d\n", xs.count); // = 0
	// printf("%lf ", xs.intersect_times[0]); // = 0.0
	// printf("%lf\n", xs.intersect_times[1]); // = 0.0
	// // exit_error("", 0, data);



	// test 5
	// t_token	*sphere;
	// t_intersect	xs;
	// t_tuple	point;
	// t_tuple	vector;
	
	// point = create_point(0, 0, 0);
	// vector = create_vector(0, 0, 1);
	// r = create_ray(&point, &vector);
	// // sphere.origin = create_point(0, 0, 0);
	// // sphere.raio = 1;
	
	// xs = intersect(&sphere, &r);
	// printf("%d\n", xs.count); // = 2
	// printf("%lf ", xs.intersect_times[0]); // = -1.0
	// printf("%lf\n", xs.intersect_times[1]); // = 1.0

	// test 6
	// t_token	*sphere;
	// t_intersect	xs;
	// t_tuple	point;
	// t_tuple	vector;
	
	// point = create_point(0, 0, 5);
	// vector = create_vector(0, 0, 1);
	// r = create_ray(&point, &vector);
	// // sphere.origin = create_point(0, 0, 0);
	// // sphere.raio = 1;
	
	// sphere = data->tokens;
	// xs = intersect(sphere, &r);
	// printf("%d\n", xs.count); // = 2
	// printf("%lf ", xs.intersect_times[0]); // = -6.0
	// printf("%lf\n", xs.intersect_times[1]); // = -4.0
}
