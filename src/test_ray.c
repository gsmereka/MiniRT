/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:57:01 by gde-mora          #+#    #+#             */
/*   Updated: 2023/08/09 22:25:11 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

typedef struct s_sphere
{
	struct	s_tuple *origin;
	double	raio;
}	t_sphere;

typedef struct s_intersect
{
	int		count;
	double	intersect_times[2];
}	t_intersect;

// t_intersect intersect(t_sphere *sphere, t_ray *ray)
// {
// 	int		i;
// 	t_tuple	*point;
	
	// 0 0 -1
	// 0 0 1
	//(void)sphere;
	//(void)ray;
	// while (i < 10)
	// {
	// 	point = position(ray, i);
	// 	if (are_tuples_equal()
	// }
// }

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
	
	// r = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	// sphere.origin = create_point(0, 0, 0);
	// sphere.raio = 1;
	
	// xs = intersect(sphere, r);
	// printf("%d\n", xs.count); // = 2
	// printf("%lf ", xs.intersect_times[0]); // = 4.0
	// printf("%lf\n", xs.intersect_times[1]); // = 6.0
	// free(r.origin);
	// free(r.direction);
	exit_error("", 0, data);
}
