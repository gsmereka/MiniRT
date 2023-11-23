/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_tools.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:23:16 by gsmereka          #+#    #+#             */
/*   Updated: 2023/11/23 18:25:33 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_TOOLS_H
# define TUPLE_TOOLS_H

// tuples operations
t_tuple	create_point(double x, double y, double z);
t_tuple	create_vector(double x, double y, double z);
t_tuple	sum_tuples(t_tuple *one, t_tuple *two);
t_tuple	subtract_tuples(t_tuple *one, t_tuple *two);
t_tuple	reverse_tuple(t_tuple *tuple);
t_tuple	multiply_tuple(t_tuple *tuple, double factor);
t_tuple	divide_tuple(t_tuple *tuple, double factor);
void	normalize_tuple(t_tuple *tuple);
double	tuple_magnitude(t_tuple *tuple);
double	dot_product(t_tuple *one, t_tuple *two);
t_tuple	cross_product(t_tuple *one, t_tuple *two);
void	pass_tuple_values(t_tuple *dest, t_tuple *src);

#endif
