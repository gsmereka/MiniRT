/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:16:42 by gde-mora          #+#    #+#             */
/*   Updated: 2023/07/19 18:22:48 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

#					 include <signal.h> //Enqunto fazemos os testes
t_data	*g_aux_data; //Enqunto fazemos os testes

static void	test_handler(int signal); //Enqunto fazemos os testes

void	signals_handling(t_data *data) //Enqunto fazemos os testes
{
	struct sigaction	test;

	g_aux_data = data;
	ft_bzero(&test, sizeof(struct sigaction));
	test.sa_handler = test_handler;
	sigaction(SIGTERM, &test, NULL);
}

static void	test_handler(int signal) //Enqunto fazemos os testes
{
	(void)signal;
	g_aux_data->debug_exit = 1;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	// t_data	data;

	// ft_bzero(&data, sizeof(data)); //
	// ft_printf("Iniciando\n"); //
	// signals_handling(&data); // //Enqunto fazemos os testes
	// validate_scene_file(argc, argv, &data); //
	// read_scene_file(argv[1], &data); //
	// get_scene_info(data.tokens, &data);
	// render(&data);

	char		*str1;
	t_matrix	*matrix;
	t_matrix	*matrix_a;
	t_matrix	*matrix_b;

	str1 = "3,3|2,2";
	matrix_a = str_to_matrix(str1);
	printf("\nMatriz A: %s\n", str1);
	print_matrix(matrix_a);

	str1 = "3,3|2,2";
	matrix_b = str_to_matrix(str1);
	printf("\nMatriz B: %s\n", str1);
	print_matrix(matrix_b);

	matrix = multiply_matrices(matrix_a, matrix_b);
	printf("\nAxB:\n");
	print_matrix(matrix);
	free_matrix(matrix_b);
	free_matrix(matrix_a);
	free_matrix(matrix);

	// str1 = "0.0,0.2,0.4|1.222,3.34,4|1.2,1.3,1.4";
	// matrix = str_to_matrix(str1);
	// printf("\nOriginal line: %s\n", str1);
	// print_matrix(matrix);
	// free_matrix(matrix);

	// str1 = "1,2,3|4,5,6|7,8,9";
	// matrix = str_to_matrix(str1);
	// printf("\nOriginal line: %s\n", str1);
	// print_matrix(matrix);
	// free_matrix(matrix);

	// str1 = "1,2|3,4";
	// matrix = str_to_matrix(str1);
	// printf("\nOriginal line: %s\n", str1);
	// print_matrix(matrix);
	// free_matrix(matrix);
	return (0);
}

void	print_matrix(t_matrix *matrix_struct)
{
	int		i;
	int		j;
	double	**matrix;

	i = 0;
	matrix = matrix_struct->content;
	printf("Resultado:\n");
	while (matrix[i])
	{
		j = 0;
		while (j < matrix_struct->cols)
		{
			printf("[ %lf ]", matrix[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}
