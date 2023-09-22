/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:14:23 by gsmereka          #+#    #+#             */
/*   Updated: 2023/09/08 19:50:29 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	test_intersection(t_data *data)
{
	t_token			*sphere;
	double			time;
	t_intersection	inter;

	sphere = data->tokens;
	while (sphere->type != 3)
		sphere = sphere->next;
	time = 3.5;
	inter = intersection(time, sphere);
	printf("%lf\n", inter.time);
	if (inter.object->type == 3)
		printf("ESFERA!\n");
	else
		printf("ERROU\n");

}
