/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:41:19 by gsmereka          #+#    #+#             */
/*   Updated: 2023/09/22 22:26:49 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_intersection	*create_intersection(double time, t_token *object)
{
	t_intersection	*intersection;

	intersection = ft_calloc(1, sizeof(t_intersection));
	intersection->time = time;
	intersection->object = object;
	intersection->next = NULL;
	return (intersection);
}

t_intersection	*intersection_last(t_intersection *inter_list)
{
	t_intersection	*aux;

	aux = inter_list;
	if (!inter_list)
		return(inter_list);
	while (aux->next)
		aux = aux->next;
	return (aux);
}

void	add_intersection(t_intersection **inter_list, double time, \
	t_token *object)
{
	t_intersection	*last_node;
	t_intersection	*new_node;            //ou a lista é no intersect? aí seria add intersect. pq la tem intersect times...

	if (!*inter_list)
		*inter_list = create_intersection(time, object);
	else
	{
		last_node = intersection_last(*inter_list);
		new_node = create_intersection(time, object); //dps alterar para add em ordem
		last_node->next = new_node;
	}
}

t_intersect	intersections(t_intersection *inter_list)
{
	t_intersect	xs;
	
	xs = (t_intersect){0};
	while (inter_list)
	{
		xs.intersect_times[xs.count] = inter_list->time;
		xs.count++;
		inter_list = inter_list->next;
	}
	return (xs);
}

void	free_intersection_list(t_intersection *inter_list)
{
	if (inter_list)
	{
		free_intersection_list(inter_list->next);
		free(inter_list);
	}
}
