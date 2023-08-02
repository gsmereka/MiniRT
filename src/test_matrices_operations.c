/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrices_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:01:46 by gsmereka          #+#    #+#             */
/*   Updated: 2023/08/02 19:19:55 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

/*static void	test_submatrix(t_data *data);
static void	test_multiply_matrix_with_tuple(t_data *data);
static void	test_multiply_matrices(t_data *data);
static void	test_transposing_matrix(t_data *data);*/
static void	test_determinant(t_data *data);


void	putting_it_together(t_data *data) // Da pagina 63
{
	t_matrix	*matrix;
	t_matrix	*matrix_2;
	t_matrix	*matrix_3;
	t_matrix	*matrix_4;
	t_matrix	*matrix_5;
	t_tuple		*tuple;
	t_tuple		*tuple_2;
	t_tuple		*tuple_3;

	(void)data;
	(void)matrix;
	(void)matrix_2;
	(void)matrix_3;
	(void)matrix_4;
	(void)matrix_5;
	(void)tuple;
	(void)tuple_2;
	(void)tuple_3;

	// printf("1. What happens when you invert the identity matrix?\n");
	
	// printf("Matriz Identidade: \n");
	// print_matrix(data->idmatrix_4x4);
	// printf("\ninvertendo a matriz:\n");
	// matrix = inverting_matrix(data->idmatrix_4x4);
	// print_matrix(matrix);
	// free_matrix(matrix);




	// printf("2. What do you get when you multiply a matrix by its inverse?\n");

	// matrix = str_to_matrix("1,2,3,4|2,2,3,4|3,3,3,4|4,4,4,4");
	// if (!matrix)
	// 	return ;

	// printf("%lf\n", matrix->determinant);
	// printf("Matriz Original:\n");
	// print_matrix(matrix);

	// matrix_2 = inverting_matrix(matrix);
	// if (!matrix_2)
	// {
	// 	free_matrix(matrix);
	// 	return ;
	// }
	// printf("Inversa da Matriz:\n");
	// print_matrix(matrix_2);

	// matrix_3 = multiply_matrices(matrix, matrix_2);
	// if (!matrix_3)
	// {
	// 	free_matrix(matrix);
	// 	free_matrix(matrix_2);
	// 	return ;
	// }
	// printf("Multiplicação da matriz pela sua inversa:\n");
	// print_matrix(matrix_3);

	// free_matrix(matrix);
	// free_matrix(matrix_2);
	// free_matrix(matrix_3);


	// printf("3. Is there any difference between the inverse of the transpose of a matrix, and the transpose of the inverse?\n");
	
	// matrix = str_to_matrix("1,2,-3,-4|5,6,-7,8|9,10,-11,12|-13,14,15,16");

	// printf("Matriz Original:\n");
	// print_matrix(matrix);

	// matrix_2 = transposing_matrix(matrix);
	// printf("Matriz Transposta:\n");
	// print_matrix(matrix_2);

	// matrix_3 = inverting_matrix(matrix);
	// printf("Matriz Inversa:\n");
	// print_matrix(matrix_3);

	// matrix_4 = multiply_matrices(matrix_2, matrix_3);
	// printf("Transposta multiplicada pela inversa:\n");
	// print_matrix(matrix_4);

	// matrix_5 = multiply_matrices(matrix_3, matrix_2);
	// printf("Inversa multiplicada Pela Transposta\n:");
	// print_matrix(matrix_5);

	// free_matrix(matrix);
	// free_matrix(matrix_2);
	// free_matrix(matrix_3);
	// free_matrix(matrix_4);
	// free_matrix(matrix_5);




	/*
	printf("4. Remember how multiplying the identity matrix by a tuple gives you the tuple, unchanged? Now, try changing any single element of the identity matrix to a different num\n");

	printf("Matriz Identidade: \n");
	print_matrix(data->idmatrix_4x4);

	tuple = ft_calloc(1, sizeof(t_tuple));
	tuple->x = 5;
	tuple->y = 6;
	tuple->z = 7;
	tuple->w = 8;
	printf("Tupla:\n");
	print_tuple(tuple);

	printf("Multiplicando Matriz identidade pela tupla:\n");
	tuple_2	= multiply_matrix_with_tuple(data->idmatrix_4x4, tuple);
	print_tuple(tuple_2);
	printf("Alterando Valores da matriz identidade:\n");
	matrix = str_to_matrix("0,0,0,0|0,1,0,0|0,0,1,0|0,0,0,1");
	print_matrix(matrix);
	printf("Multiplicando a mesma tupla pela identidade modificada:\n");
	tuple_3 = multiply_matrix_with_tuple(matrix, tuple);
	print_tuple(tuple_3);
	free(tuple);
	free(tuple_2);
	free(tuple_3);
	free_matrix(matrix);*/

	
	/*printf("5. Test copy matrix");
	matrix = str_to_matrix("1,2,3,4|2,2,3,4|3,3,3,4|4,4,4,4");
	if (!matrix)
	 	return ;
	matrix_2 = copy_matrix(matrix);
	printf("\nMatrix:\n");
	print_matrix(matrix);
	printf("\nMatrix 2:\n");
	print_matrix(matrix_2);
	free_matrix(matrix);
	free_matrix(matrix_2);*/


	printf("6. Scaling transformation");
	matrix = scaling(data, 2, 3, 4);
	printf("\nMatrix:\n");
	print_matrix(matrix);
	matrix_2 = inverting_matrix(matrix);
	printf("\nMatrix 2:\n");
	print_matrix(matrix_2);
	tuple = create_vector(-4, 6, 8);
	tuple_2 = multiply_matrix_with_tuple(matrix_2, tuple);
	print_tuple(tuple_2);
	free_matrix(matrix);
	free_matrix(matrix_2);
	free(tuple);
	free(tuple_2);
}

void	test_inversion(t_data	*data)
{
	t_matrix	*matrix;
	t_matrix	*matrix_2;
	t_matrix	*matrix_3;

	(void)data;
	(void)matrix;
	(void)matrix_2;
	(void)matrix_3;
	matrix = inverting_matrix(data->idmatrix_4x4);
	print_matrix(data->idmatrix_4x4);
	if (matrix)
	{
		print_matrix(matrix);
		free_matrix(matrix);
	}
}

void	tests_translations(t_data *data)
{
	t_matrix	*translation_matrix;
	t_matrix	*inverse;
	t_tuple		*point;
	t_tuple		*point_2;

	(void)data;
	(void)translation_matrix;
	(void)point;
	(void)point_2;
	(void)inverse;

	// printf("Translação de ponto simples\n");
	// translation_matrix = translation(5, -3, 2, data);
	// point = ft_calloc(1, sizeof(t_tuple));
	// point->x = -3;
	// point->y = 4;
	// point->z = 5;
	// point->w = 1;
	// point_2 = multiply_matrix_with_tuple(translation_matrix, point);
	// print_tuple(point_2);
	// free(point);
	// free(point_2);
	// free_matrix(translation_matrix);


	// printf("Translação de ponto reversa\n");
	// translation_matrix = translation(5, -3, 2, data);
	// print_matrix(translation_matrix);
	// inverse = inverting_matrix(translation_matrix);
	// print_matrix(inverse);
	// point = ft_calloc(1, sizeof(t_tuple));
	// point->x = -3;
	// point->y = 4;
	// point->z = 5;
	// point->w = 1;
	// point_2 = multiply_matrix_with_tuple(inverse, point);
	// print_tuple(point_2);
	// free(point);
	// free(point_2);
	// free_matrix(translation_matrix);
	// free_matrix(inverse);


	// printf("Translação de vetores\n");
	// translation_matrix = translation(5, -3, 2, data);
	// point = ft_calloc(1, sizeof(t_tuple));
	// point->x = -3;
	// point->y = 4;
	// point->z = 5;
	// point->w = 0;
	// point_2 = multiply_matrix_with_tuple(translation_matrix, point);
	// print_tuple(point_2);
	// free(point);
	// free(point_2);
	// free_matrix(translation_matrix);

	printf("Translação de ponto reversa\n");
	translation_matrix = translation(5, -3, 2, data);
	print_matrix(translation_matrix);
	inverse = inverting_matrix(translation_matrix);
	print_matrix(inverse);
	point = ft_calloc(1, sizeof(t_tuple));
	point->x = -3;
	point->y = 4;
	point->z = 5;
	point->w = 0;
	point_2 = multiply_matrix_with_tuple(inverse, point);
	print_tuple(point_2);
	free(point);
	free(point_2);
	free_matrix(translation_matrix);
	free_matrix(inverse);
}

void	tests_shearing(t_data *data)
{
	t_matrix	*shearing_matrix;
	t_matrix	*inverse;
	t_tuple		*point;
	t_tuple		*point_2;
	double		proportions[6] = {0,0,0,0,0,0};

	(void)proportions;
	(void)data;
	(void)shearing_matrix;
	(void)point;
	(void)point_2;
	(void)inverse;

	printf("A shearing transformation moves x in proportion to y\n");
	proportions[0] = 1;
	shearing_matrix = shearing(proportions, data);
	point = create_point(2,3,4);
	point_2 = multiply_matrix_with_tuple(shearing_matrix, point);
	print_tuple(point_2);
	free(point);
	free(point_2);
	free_matrix(shearing_matrix);
	ft_bzero(&proportions, sizeof(proportions));

	printf("A shearing transformation moves x in proportion to z\n");
	proportions[1] = 400;
	shearing_matrix = shearing(proportions, data);
	point = create_point(2,3,4);
	point_2 = multiply_matrix_with_tuple(shearing_matrix, point);
	print_tuple(point_2);
	free(point);
	free(point_2);
	free_matrix(shearing_matrix);
	ft_bzero(&proportions, sizeof(proportions));

	printf("A shearing transformation moves y in proportion to x\n");
	proportions[2] = 1;
	shearing_matrix = shearing(proportions, data);
	point = create_point(2,3,4);
	point_2 = multiply_matrix_with_tuple(shearing_matrix, point);
	print_tuple(point_2);
	free(point);
	free(point_2);
	free_matrix(shearing_matrix);
	ft_bzero(&proportions, sizeof(proportions));

	printf("A shearing transformation moves y in proportion to z\n");
	proportions[3] = 1;
	shearing_matrix = shearing(proportions, data);
	point = create_point(2,3,4);
	point_2 = multiply_matrix_with_tuple(shearing_matrix, point);
	print_tuple(point_2);
	free(point);
	free(point_2);
	free_matrix(shearing_matrix);
	ft_bzero(&proportions, sizeof(proportions));

	printf("A shearing transformation moves z in proportion to x\n");
	proportions[4] = 1;
	shearing_matrix = shearing(proportions, data);
	point = create_point(2,3,4);
	point_2 = multiply_matrix_with_tuple(shearing_matrix, point);
	print_tuple(point_2);
	free(point);
	free(point_2);
	free_matrix(shearing_matrix);
	ft_bzero(&proportions, sizeof(proportions));

	printf("A shearing transformation moves z in proportion to ys\n");
	proportions[5] = 1;
	shearing_matrix = shearing(proportions, data);
	point = create_point(2,3,4);
	point_2 = multiply_matrix_with_tuple(shearing_matrix, point);
	print_tuple(point_2);
	free(point);
	free(point_2);
	free_matrix(shearing_matrix);
	ft_bzero(&proportions, sizeof(proportions));

	// printf("shearing de ponto reversa\n");
	// shearing_matrix = shearing(5, -3, 2, data);
	// inverse = inverting_matrix(shearing_matrix);
	// point = ft_calloc(1, sizeof(t_tuple));
	// point->x = -3;
	// point->y = 4;
	// point->z = 5;
	// point->w = 1;
	// point_2 = multiply_matrix_with_tuple(inverse, point);
	// print_tuple(point_2);
	// free(point);
	// free(point_2);
	// free_matrix(shearing_matrix);
	// free_matrix(inverse);


	// printf("shearing de vetores\n");
	// shearing_matrix = shearing(5, -3, 2, data);
	// point = ft_calloc(1, sizeof(t_tuple));
	// point->x = -3;
	// point->y = 4;
	// point->z = 5;
	// point->w = 0;
	// point_2 = multiply_matrix_with_tuple(shearing_matrix, point);
	// print_tuple(point_2);
	// free(point);
	// free(point_2);
	// free_matrix(shearing_matrix);
}

void	chaining_transformations(t_data *data)
{
	t_matrix	*translation_matrix;
	t_matrix	*inverse_matrix;
	t_matrix	*scaling_matrix;
	t_matrix	*rotation_x_matrix;
	t_matrix	*shearing_matrix;
	t_matrix	*ultimate_transformation;
	t_tuple		*point;
	t_tuple		*point_2;
	t_tuple		*point_3;
	t_tuple		*point_4;
	t_tuple		*point_5;
	t_tuple		*point_6;
	t_matrix	*matrix_1;
	t_matrix	*matrix_2;
	t_matrix	*matrix_3;

	(void)data;
	(void)translation_matrix;
	(void)point;
	(void)point_2;
	(void)point_3;
	(void)point_4;
	(void)point_5;
	(void)point_6;
	(void)translation_matrix;
	(void)inverse_matrix;
	(void)rotation_x_matrix;
	(void)shearing_matrix;
	(void)scaling_matrix;
	(void)ultimate_transformation;
	(void)matrix_1;
	(void)matrix_2;
	(void)matrix_3;

	point = create_point(1, 0, 1);
	// rotation_x_matrix = rotation(M_PI / 2, data);
	scaling_matrix = scaling(data, 5, 5, 5);
	translation_matrix = translation(10, 5, 7, data);



	printf("Scenario: Individual transformations are applied in sequence\n");

		printf("Aplicando Rotação Primeiro:\n");
		// point_2 = multiply_matrix_with_tuple(rotation_x_matrix, point);
		// print_tuple(point_2);

		printf("Aplicando scaling em seguida:\n");
		// point_3 = multiply_matrix_with_tuple(scaling_matrix, point_2);
		point_3 = multiply_matrix_with_tuple(scaling_matrix, point);
		print_tuple(point_3);

		printf("Aplicando translação em seguida:\n");
		point_4 = multiply_matrix_with_tuple(translation_matrix, point_3);
		print_tuple(point_4);

		free(point);
		// free(point_2);
		free(point_3);
		free(point_4);
		free_matrix(scaling_matrix);
		free_matrix(translation_matrix);
		// free_matrix(rotation_x_matrix);
	
	
	// printf(" Chained transformations must be applied in reverse order\n");
	
	// 	matrix_1 = multiply_matrices(translation_matrix, scaling_matrix);
	// 	ultimate_transformation = multiply_matrices(matrix_1, rotation_x_matrix);
	// 	point_2 = multiply_matrix_with_tuple(ultimate_transformation, point);

	// 	print_tuple(point_2);

	// 	free(point_2)
	// 	free(point);
	// 	free_matrix(scaling_matrix);
	// 	free_matrix(translation_matrix);
	// 	free_matrix(ultimate_transformation);
	// 	free_matrix(matrix_1);
	// 	free_matrix(rotation_x_matrix);
}

void	test_matrices_operations(int argc, char **argv, t_data *data) // Retirar depois, do makefile tb
{
	(void)argc;
	(void)argv;
	(void)data;
	/*test_multiply_matrices(data);
	//exit_error("", 0, data);
	test_multiply_matrix_with_tuple(data);
	//exit_error("", 0, data);
	test_submatrix(data);
	//exit_error("", 0, data);
	test_transposing_matrix(data);
	//exit_error("", 0, data);*/
	tests_translations(data);
	exit_error("", 0, data);
	putting_it_together(data);
	exit_error("", 0, data);
	test_inversion(data);
	exit_error("", 0, data);
	test_determinant(data);
	exit_error("", 0, data);
}

/*static void	test_submatrix(t_data *data)
{
	char		*str1;
	t_matrix	*matrix;
	t_matrix	*matrix_a;
	t_matrix	*matrix_b;

	matrix = NULL;
	matrix_a = NULL;
	matrix_b = NULL;
	str1 = NULL;
	(void)data;
	(void)matrix;
	(void)matrix_a;
	(void)matrix_b;
	(void)str1;

	// Testando a função get_submatrix
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
}

static void	test_multiply_matrix_with_tuple(t_data *data)
{
	char		*str1;
	t_matrix	*matrix;
	t_matrix	*matrix_a;
	t_matrix	*matrix_b;
	t_tuple *tuple;

	matrix = NULL;
	matrix_a = NULL;
	matrix_b = NULL;
	str1 = NULL;
	(void)data;
	(void)matrix;
	(void)matrix_a;
	(void)matrix_b;
	(void)str1;
	// Testando a função get_submatrix
	printf("Testando multiplicar matrizes por tuplas\n");
	str1  = "1,2,3,4|5,6,7,8|9,10,11,12|13,14,15,16";
	
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
}

static void	test_multiply_matrices(t_data *data)
{
	char		*str1;
	t_matrix	*matrix;
	t_matrix	*matrix_a;
	t_matrix	*matrix_b;

	matrix = NULL;
	matrix_a = NULL;
	matrix_b = NULL;
	str1 = NULL;
	(void)data;
	(void)matrix;
	(void)matrix_a;
	(void)matrix_b;
	(void)str1;
 // Testando a função get_submatrix
	printf("Testando multiplicação de matrizes\n");
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
}

static void	test_transposing_matrix(t_data *data) // Retirar depois
{
	char		*str1;
	t_matrix	*matrix_a;
	t_matrix	*matrix;

	printf("\n\n\n");
	(void)data;
	str1 = "0,9,3,0|9,8,0,8|1,8,5,3|0,0,5,8";
	//str1 = "1,0,0,0|0,1,0,0|0,0,1,0|0,0,0,1";
	matrix_a = str_to_matrix(str1);
	matrix = transposing_matrix(matrix_a);
	if (matrix_a)
	{
		printf("\nMatriz A: %s", str1);
	 	printf("\nLinhas:%d\nColunas:%d\n", matrix_a->rows, matrix_a->cols);
	 	print_matrix(matrix_a);
		free_matrix(matrix_a);
		matrix_a = NULL;
	}
	if (matrix)
	{
		printf("\nMatriz Transposta:");
	 	printf("\nLinhas:%d\nColunas:%d\n", matrix->rows, matrix->cols);
	 	print_matrix(matrix);
		free_matrix(matrix);
		matrix = NULL;
	}
}*/

static void	test_determinant(t_data *data)
{
	char		*str1;
	char		*str2;
	char		*str3;
	t_matrix	*matrix_a;
	t_matrix	*matrix_b;
	t_matrix	*matrix_c;
	double		det;

	(void)data;
	//str1 = "1,0,0,0|0,1,0,0|0,0,1,0|0,0,0,1";
	str1 = "0,9|9,8";
	str2 = "0,9,3|9,8,0|1,8,5";
	str3 = "0,9,3,0|9,8,0,8|1,8,5,3|0,0,5,8";
	matrix_a = str_to_matrix(str1);
	matrix_b = str_to_matrix(str2);
	matrix_c = str_to_matrix(str3);
	
	if (matrix_a)
	{
		printf("\nMatriz 2x2:");
	 	printf("\nLinhas:%d\nColunas:%d\n", matrix_a->rows, matrix_a->cols);
	 	print_matrix(matrix_a);
		det = get_determinant(matrix_a);
		printf("Determinant: %lf\n", det);
		free_matrix(matrix_a);
		matrix_a = NULL;
	}
	if (matrix_b)
	{
		printf("\nMatriz 3x3:");
	 	printf("\nLinhas:%d\nColunas:%d\n", matrix_b->rows, matrix_b->cols);
	 	print_matrix(matrix_b);
		det = get_determinant(matrix_b);
		printf("Determinant: %lf\n", det);
		free_matrix(matrix_b);
		matrix_b = NULL;
	}
	if (matrix_c)
	{
		printf("\nMatriz 4x4:");
	 	printf("\nLinhas:%d\nColunas:%d\n", matrix_c->rows, matrix_c->cols);
	 	print_matrix(matrix_c);
		det = get_determinant(matrix_c);
		printf("Determinant: %lf\n", det);
		free_matrix(matrix_c);
		matrix_c = NULL;
	}
}
