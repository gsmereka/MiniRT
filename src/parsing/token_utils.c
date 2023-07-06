/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_token_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 01:53:31 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/06 20:22:55 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_token	*create_token(char **args);
t_token	*token_last(t_token *token);
void	add_token(t_token **tokens, char **args);
void	token_clear(t_token **tokens);

t_token	*create_token(char **args)
{
	t_token	*new_node;

	new_node = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!new_node)
		return (NULL);
	new_node->args = args;
	return (new_node);
}

t_token	*token_last(t_token *token)
{
	t_token	*last_token;

	last_token = token;
	if (!token)
		return (token);
	while (last_token->next)
		last_token = last_token->next;
	return (last_token);
}

void	add_token(t_token **tokens, char **args)
{
	t_token	*last_node;
	t_token	*new_node;

	if (!*tokens)
		*tokens = create_token(args);
	else
	{
		last_node = token_last(*tokens);
		new_node = create_token(args);
		last_node->next = new_node;
	}
}

void	token_clear(t_token **tokens)
{
	if (*tokens)
	{
		token_clear(&(*tokens)->next);
		if ((*tokens)->args)
			free_array((void **)(*tokens)->args);
		free(*tokens);
		*tokens = NULL;
	}
}
