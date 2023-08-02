/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:24:07 by gde-mora          #+#    #+#             */
/*   Updated: 2023/08/02 20:57:44 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

static double **copy_content(t_matrix *src)
{
	int		i;
	int		j;
	double **content;

	content = ft_calloc(src->rows + 1, sizeof(double *));
	if (!content)
		return (NULL);
	i = -1;
	while (++i < src->rows)
	{
		j = -1;
		content[i] = ft_calloc(src->cols, sizeof(double));
		while (++j < src->cols)
			content[i][j] = src->content[i][j];
	}
	content[i] = NULL; //???
	return (content);
}

t_matrix	*copy_matrix(t_matrix *src)
{
	t_matrix	*dest;

	if (!src)
		return (NULL);
	if (!src->content)
		return (NULL);
	dest = ft_calloc(1, sizeof(t_matrix));
	if (!dest)
		return (NULL);
	dest->content = copy_content(src);
	if (!dest->content)
		return (NULL);
	dest->rows = src->rows;
	dest->cols = src->cols;
	dest->determinant = src->determinant;
	return (dest);
}
