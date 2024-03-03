/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:16:42 by gde-mora          #+#    #+#             */
/*   Updated: 2024/03/03 03:31:44 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	print_matrix(t_matrix *matrix_struct) // Retirar depois  //aviso: tem comentario em portugues no makefile
{
	int		i;
	int		j;

	i = 0;
	printf("linhas e colunas: %d, %d\n",
		matrix_struct->rows, matrix_struct->cols);
	while (i < matrix_struct->rows)
	{
		j = 0;
		while (j < matrix_struct->cols)
		{
			printf("[ %lf ]", matrix_struct->content[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("Determinant: %lf\n\n", matrix_struct->determinant);
}

void	print_tuple(t_tuple *tuple) // retirar depois
{
	if (!tuple)
	{
		printf("No Tuple\n");
		return ;
	}
	printf("(%lf, %lf, %lf, %lf)\n", tuple->x, tuple->y, tuple->z, tuple->w);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){0};
	ft_printf("Iniciando\n"); // remover depois
	validate_scene_file(argc, argv, &data);
	read_scene_file(argv[1], &data);
	get_scene_info(data.tokens, &data);
	define_scene(&data);
	render(&data);
	exit_error("", 0, &data);
	return (0);
}
