/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:23:16 by gsmereka          #+#    #+#             */
/*   Updated: 2023/09/23 01:24:37 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_TOOLS_H
# define MATRIX_TOOLS_H

// matrix_tools
void		init_idmatrices(t_data *data);
t_matrix	str_to_matrix(char *str);
t_matrix	create_matrix(double **content, int cols);
void		print_matrix(t_matrix *matrix_struct); // retirara depois
void		print_tuple(t_tuple *tuple); // retirar depois
int			matrices_have_diff(t_matrix *a, t_matrix *b);
t_matrix	multiply_matrices(t_matrix *a, t_matrix *b);
t_matrix	transposing_matrix(t_matrix *mat);
t_tuple		multiply_matrix_with_tuple(t_matrix *matrix, t_tuple *tuple);
t_matrix	get_submatrix(t_matrix *matrix, int row, int col);
double		get_determinant(t_matrix *matrix);
double		get_cofactor(t_matrix *matrix, int row, int col);
t_matrix	inverting_matrix(t_matrix *matrix);
t_matrix	copy_matrix(t_matrix *src);

#endif
