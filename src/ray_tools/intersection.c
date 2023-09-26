/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:41:19 by gsmereka          #+#    #+#             */
/*   Updated: 2023/09/22 23:03:54 by gde-mora         ###   ########.fr       */
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

void	add_sorted_node(t_intersection **inter_list, t_intersection *new_node)
{
	t_intersection *aux;

	aux = *inter_list;
	while (aux->next)
	{
		if (aux->next->time >= new_node->time)
		{
			new_node->next = aux->next;
			aux->next = new_node;
			return ;
		}
		aux = aux->next;
	}
	if (aux->time >= new_node->time)
	{
		new_node->next = aux;
		new_node->size_list_first_node_only = (*inter_list)->size_list_first_node_only;
		*inter_list = new_node;
	}
	else
		aux->next = new_node;
} 

void	add_intersection(t_intersection **inter_list, double time, \
	t_token *object)
{
	t_intersection	*new_node;            //ou a lista é no intersect? aí seria add intersect. pq la tem intersect times...

	if (!*inter_list)
		*inter_list = create_intersection(time, object);
	else
	{
		new_node = create_intersection(time, object); //dps alterar para add em ordem
		add_sorted_node(inter_list, new_node);
	}
	(*inter_list)->size_list_first_node_only++;
}

t_intersect	intersections_xs(t_intersection *inter_list)
{
	t_intersect	xs;
	
	xs = (t_intersect){0};
	xs.objects = ft_calloc(inter_list->size_list_first_node_only, sizeof(t_token *));
	if (!xs.objects)
		return ((t_intersect){0});
	xs.intersect_times = ft_calloc(inter_list->size_list_first_node_only, sizeof(double));
	if (!xs.intersect_times)
		return ((t_intersect){0});
	while (inter_list)
	{
		xs.intersect_times[xs.count] = inter_list->time;
		xs.objects[xs.count] = (inter_list->object); //isso funciona?
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
