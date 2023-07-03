/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:00:06 by gde-mora          #+#    #+#             */
/*   Updated: 2023/07/03 23:52:08 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

double	aux_fractional_part(double result, const char *str, int i)
{
	double	fractional;

	fractional = 0.1;
	if (result && str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result += fractional * (str[i] - '0');
			fractional *= 0.1;
			i++;
		}
	}
	return (result);
}

double	atod(const char *str)
{
	int		i;
	int		signal;
	double	result;

	i = 0;
	signal = 1;
	result = 0.0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10.0) + (str[i] - '0');
		i++;
	}
	result = aux_fractional_part(result, str, i);
	return (result * signal);
}
