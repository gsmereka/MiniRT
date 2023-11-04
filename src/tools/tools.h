/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:23:16 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/04 15:28:20 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

// tools
int		dtoi(double num);
int		are_floats_equal(double one, double two);
int		are_tuples_equal(t_tuple *one, t_tuple *two);
int		free_array(void **array);
double	atod(const char *str);
t_ray	create_ray(t_tuple *origin, t_tuple *direction);
t_tuple	position(t_ray *ray, double time);

#endif
