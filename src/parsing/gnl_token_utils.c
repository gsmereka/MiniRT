/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 01:53:31 by gsmereka          #+#    #+#             */
/*   Updated: 2023/06/30 03:01:16 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_gnl_token	*create_gnl_token(char **args);
t_gnl_token	*gnl_token_last(t_gnl_token *gnl_token);
void	add_gnl_token(t_gnl_token **gnl_tokens, char **args);
void	gnl_token_clear(t_gnl_token **gnl_tokens);

t_gnl_token	*create_gnl_token(char **args)
{
	t_gnl_token	*new_node;

	new_node = (t_gnl_token *)calloc(1, sizeof(t_gnl_token));
	if (!new_node)
		return (NULL);
	new_node->args = args;
	return (new_node);
}

t_gnl_token	*gnl_token_last(t_gnl_token *gnl_token)
{
	t_gnl_token	*last_gnl_token;

	last_gnl_token = gnl_token;
	if (!gnl_token)
		return (gnl_token);
	while (last_gnl_token->next)
		last_gnl_token = last_gnl_token->next;
	return (last_gnl_token);
}

void	add_gnl_token(t_gnl_token **gnl_tokens, char **args)
{
	t_gnl_token	*last_node;
	t_gnl_token	*new_node;

	if (!*gnl_tokens)
		*gnl_tokens = create_gnl_token(args);
	else
	{
		last_node = gnl_token_last(*gnl_tokens);
		new_node = create_gnl_token(args);
		last_node->next = new_node;
	}
}

void	gnl_token_clear(t_gnl_token **gnl_tokens)
{
	if (*gnl_tokens)
	{
		gnl_token_clear(&(*gnl_tokens)->next);
		if ((*gnl_tokens)->args)
			free_array((void **)(*gnl_tokens)->args);
		free(*gnl_tokens);
		*gnl_tokens = NULL;
	}
}
