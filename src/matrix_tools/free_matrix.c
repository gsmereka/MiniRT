/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:09:17 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/21 20:13:10 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

void	free_matrix(t_matrix *matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	if (!matrix->content)
	{
		free(matrix);
		return ;
	}
	while (matrix->content[i])
	{
		free(matrix->content[i]);
		i++;
	}
	free(matrix->content);
	free(matrix);
}