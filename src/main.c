/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:16:42 by gde-mora          #+#    #+#             */
/*   Updated: 2023/09/08 18:54:42 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

#					 include <signal.h> //Enqunto fazemos os testes
t_data	*g_aux_data; //Enqunto fazemos os testes

static void	test_handler(int signal) //Enqunto fazemos os testes
{
	(void)signal;
	g_aux_data->debug_exit = 1;
}

void	signals_handling(t_data *data) //Enqunto fazemos os testes
{
	struct sigaction	test;

	g_aux_data = data;
	ft_bzero(&test, sizeof(struct sigaction));
	test.sa_handler = test_handler;
	sigaction(SIGTERM, &test, NULL);
}

void	print_matrix(t_matrix *matrix_struct) // Retirar depois
{
	int		i;
	int		j;

	i = 0;
	printf("linhas e colunas: %d, %d\n", matrix_struct->rows, matrix_struct->cols);
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

void	print_tuple(t_tuple *tuple)
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

  	ft_bzero(&data, sizeof(data));
	init_idmatrices(&data);
	// test_matrices_operations(argc, argv, &data); // retirar depois
	ft_printf("Iniciando\n"); //
	test_ray(&data);
	signals_handling(&data); // Enqunto fazemos os testes //retirar dps
	validate_scene_file(argc, argv, &data); //
	read_scene_file(argv[1], &data); //
	get_scene_info(data.tokens, &data);
	// render(&data);
	// test_render(&data);
	exit_error("", 0, &data);
	return (0);
}
