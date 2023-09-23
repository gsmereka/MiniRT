/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:23:16 by gsmereka          #+#    #+#             */
/*   Updated: 2023/09/23 01:33:08 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

// token utils
t_token		*create_token(char **args);
t_token		*token_last(t_token *token);
void		add_token(t_token **tokens, char **args);
void		token_clear(t_token **tokens);

// check_shape
int			is_plane(char **args, t_data *data);
int			is_sphere(char **args, t_data *data);
int			is_cylinder(char **args, t_data *data);

// check_config
int			is_ambient_lighting(char **args, t_data *data);
int			is_light(char **args, t_data *data);
int			is_camera(char **args, t_data *data);
int			is_resolution(char **args, t_data *data);

// check_utils
int			is_coordinate(char *arg);
int			is_normalized_vector(char *arg);
int			is_color(char *arg);

// add shape
int			add_plane(t_token *token, t_data *data);
int			add_sphere(t_token *token, t_data *data);
int			add_cylinder(t_token *token, t_data *data);

// add config
int			add_ambient_lighting(t_token *token, t_data *data);
int			add_light(t_token *token, t_data *data);
int			add_camera(t_token *token, t_data *data);
int			add_resolution(char	**args, t_data *data);

#endif
