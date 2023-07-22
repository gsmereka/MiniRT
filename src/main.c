/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:16:42 by gde-mora          #+#    #+#             */
/*   Updated: 2023/07/21 21:55:12 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

#					 include <signal.h> //Enqunto fazemos os testes
t_data	*g_aux_data; //Enqunto fazemos os testes

static void	test_handler(int signal); //Enqunto fazemos os testes
static void	test_matrices(int argc, char **argv, t_data *data); // Retirar depois

void	signals_handling(t_data *data) //Enqunto fazemos os testes
{
	struct sigaction	test;

	g_aux_data = data;
	ft_bzero(&test, sizeof(struct sigaction));
	test.sa_handler = test_handler;
	sigaction(SIGTERM, &test, NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	init_idmatrices(&data);
	test_matrices(argc, argv, &data); // retirar depois
	ft_printf("Iniciando\n"); //
	signals_handling(&data); // //Enqunto fazemos os testes
	validate_scene_file(argc, argv, &data); //
	read_scene_file(argv[1], &data); //
	get_scene_info(data.tokens, &data);
	render(&data);
	return (0);
}

static void	test_matrices(int argc, char **argv, t_data *data) // Retirar depois
{
	char		*str1;
	t_matrix	*matrix;
	t_matrix	*matrix_a;
	t_matrix	*matrix_b;

	matrix = NULL;
	matrix_a = NULL;
	matrix_b = NULL;
	str1 = NULL;
	(void)argc;
	(void)argv;
	(void)matrix;
	(void)matrix_a;
	(void)matrix_b;
	(void)str1;

	/// Testando a função get_submatrix
	printf("Testando a função get_submatrix\n");

	str1  = "1,2,3,4|2,2,3,4|3,3,3,4|4,4,4,4";

	matrix = str_to_matrix(str1);
	printf("Matriz original 4x4:\n");
	print_matrix(matrix);
	printf("Submatriz tirando linha 4 e coluna 4:\n\n");
	matrix_a = get_submatrix(matrix, 3, 3);
	if (matrix_a)
		print_matrix(matrix_a);
	printf("\nSubmatriz da submatriz tirando linha 3 e coluna 3:\n");
	matrix_b = get_submatrix(matrix_a, 2, 2);
	if (matrix_b)
		print_matrix(matrix_b);
	free_matrix(matrix);
	free_matrix(matrix_a);
	free_matrix(matrix_b);
	matrix = NULL;
	matrix_a = NULL;
	matrix_b = NULL;
	exit_error("", 0, data);

	/// Testando multiplicar matrizes por tuplas
	printf("Testando multiplicar matrizes por tuplas\n");
	str1  = "1,2,3,4|5,6,7,8|9,10,11,12|13,14,15,16";

	t_tuple *tuple;
		
	
	tuple = ft_calloc(1, sizeof(t_tuple));
	tuple->x = -1;
	tuple->y = 1;
	tuple->z = -1;
	tuple->w = 1;

	matrix = str_to_matrix(str1);

	t_tuple	*new_tuple = multiply_matrix_with_tuple(matrix, tuple);

	printf("Tupla inicial\nx:%lf\ny:%lf\nz:%lf\nw:%lf\n\n", tuple->x, tuple->y, tuple->z, tuple->w);
	print_matrix(matrix);
	printf("\nTupla  final\nx:%lf\ny:%lf\nz:%lf\nw:%lf\n\n", new_tuple->x, new_tuple->y, new_tuple->z, new_tuple->w);
	free(tuple);
	free(new_tuple);
	free_matrix(matrix);
	matrix = NULL;
	exit_error("", 0, data);



	/// Testando Multiplicação de matrizes
	// str1 = "-1|-1|-1|-1|-1|-1";
	str1 = "-1,2|2,5";
	matrix_a = str_to_matrix(str1);
	if (matrix_a)
	{
		printf("\nMatriz A: %s\n", str1);
		print_matrix(matrix_a);
	}
	else
		printf("Matriz A falhou\n");

	// str1 = "-1,-1,-1,-1,-1,-1";
	str1 = "2,-9|2,6";
	matrix_b = str_to_matrix(str1);
	if (matrix_b)
	{
		printf("\nMatriz B: %s\n", str1);
		print_matrix(matrix_b);
	}
	else
		printf("Matriz B falhou\n");

	matrix = multiply_matrices(matrix_a, matrix_b);
	if (matrix)
	{
		printf("\nAxB:\n");
		print_matrix(matrix);
	}
	else
		printf("Matriz AxB falhou\n");

	// str1 = "3,3,2|2,";
	// matrix_a = str_to_matrix(str1);
	// if (matrix_a)
	// {
	// 	printf("\nMatriz A: %s", str1);
	// 	printf("\nLinhas:%d\nColunas:%d\n", matrix_a->rows, matrix_a->cols);
	// 	print_matrix(matrix_a);
	// }
	if (matrix_b)
		free_matrix(matrix_b);
	matrix_b = NULL;

	// str1 = "3,3|2,2|1,1";
	// matrix_b = str_to_matrix(str1);
	// printf("\nMatriz B: %s", str1);
	// printf("\nLinhas:%d\nColunas:%d\n", matrix_b->rows, matrix_b->cols);
	// print_matrix(matrix_b);
	if (matrix_b)
		free_matrix(matrix_b);
	matrix_b = NULL;

	// // matrix = multiply_matrices(matrix_a, matrix_b);
	// printf("\nAxB:\n");
	// // print_matrix(matrix);
	if (matrix)
		free_matrix(matrix);
	matrix = NULL;

	// str1 = "0.0,0.2,0.4|1.222,3.34,4|1.2,1.3,1.4";
	// matrix = str_to_matrix(str1);
	// printf("\nOriginal line: %s\n", str1);
	// print_matrix(matrix);
	if (matrix)
		free_matrix(matrix);
	matrix = NULL;

	// str1 = "1,2,3|4,5,6|7,8,9";
	// matrix = str_to_matrix(str1);
	// printf("\nOriginal line: %s\n", str1);
	// print_matrix(matrix);
	if (matrix)
		free_matrix(matrix);
	matrix = NULL;

	// str1 = "1,2|3,4";
	// matrix = str_to_matrix(str1);
	// printf("\nOriginal line: %s\n", str1);
	// print_matrix(matrix);

	if (matrix_a)
		free_matrix(matrix_a);
	matrix_a = NULL;
	if (matrix_b)
		free_matrix(matrix_b);
	matrix_b = NULL;
	if (matrix)
		free_matrix(matrix);
	matrix = NULL;
	exit (0);
}

void	print_matrix(t_matrix *matrix_struct) // Retirar depois
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

static void	test_handler(int signal) //Enqunto fazemos os testes
{
	(void)signal;
	g_aux_data->debug_exit = 1;
}
