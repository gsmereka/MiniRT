/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:11:05 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/17 18:17:43 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static int		count_lines(void **array);
static int		count_cols(char *line);
static double	**extract_matrix_content(char **lines_str,
					int lines_count, int cols_count);
static double	*extract_line_numbers(char *str, int cols_count);

t_matrix	*str_to_matrix(char *str)
{
	t_matrix	*matrix;
	char		**lines_str;
	double		**matrix_content;
	int			lines_count;
	int			cols_count;

	lines_str = ft_split(str, '|');
	if (!lines_str)
		return (NULL);
	lines_count = count_lines((void **)lines_str);
	cols_count = count_cols(lines_str[0]);
	if (cols_count == 0)
		return (NULL);
	matrix_content = extract_matrix_content(lines_str, lines_count, cols_count);
	matrix = create_matrix(matrix_content, cols_count);
	free_array((void **)lines_str);
	return (matrix);
}

static double	**extract_matrix_content(char **lines_str,
	int lines_count, int cols_count)
{
	double	**matrix_content;
	int		i;

	i = 0;
	matrix_content = ft_calloc(lines_count + 1, sizeof(double *));
	if (!matrix_content)
		return (NULL);
	while (lines_str[i])
	{
		matrix_content[i] = extract_line_numbers(lines_str[i], cols_count);
		if (!matrix_content[i])
		{
			free_array((void **)lines_str);
			free_array((void **)matrix_content);
			return (NULL);
		}
		i++;
	}
	return (matrix_content);
}

static double	*extract_line_numbers(char *str, int cols_count)
{
	char	**numbers;
	double	*content;
	int		i;

	if (count_cols(str) != cols_count)
		return (NULL);
	numbers = ft_split(str, ',');
	if (!numbers)
		return (NULL);
	content = ft_calloc(cols_count, sizeof(double));
	if (!content)
	{
		free_array((void **)numbers);
		return (NULL);
	}
	i = 0;
	while (numbers[i])
	{
		content[i] = atod(numbers[i]);
		i++;
	}
	free_array((void **)numbers);
	return (content);
}

static int	count_lines(void **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

static int	count_cols(char *line)
{
	int	i;
	int	cols;

	i = 0;
	cols = 0;
	while (line[i])
	{
		if (line[i] == ',')
			cols++;
		i++;
	}
	cols++;
	return (cols);
}
