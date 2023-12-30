/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:23:16 by gsmereka          #+#    #+#             */
/*   Updated: 2023/09/23 01:27:05 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_TRANSFORMATIONS_H
# define MATRIX_TRANSFORMATIONS_H

// Matrix Transformations
t_matrix	translation(double x, double y, double z, t_data *data);
t_matrix	scaling(t_data *data, double x, double y, double z);
t_matrix	rotation_x(t_data *data, double radians);
t_matrix	rotation_y(t_data *data, double radians);
t_matrix	rotation_z(t_data *data, double radians);
t_matrix	shearing(double *proportions, t_data *data);

#endif
