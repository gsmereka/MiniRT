/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:23:16 by gsmereka          #+#    #+#             */
/*   Updated: 2024/03/30 01:54:26 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// render
void			render(t_data *data);
void			paint_pixel(int x, int y, unsigned int color, t_data *data);
int				handle_esc(int key, t_data *data);
int				handle_x(t_data *data);
t_color			sum_colors(t_color *one, t_color *two);
t_color			subtract_colors(t_color *one, t_color *two);
t_color			multiply_color_scalar(t_color *color, double factor);
t_color			multiply_color_x_color(t_color *one, t_color *two);
t_color			sum_light_to_color(t_color *color, double factor);
t_color			normalize_color(t_color *color);
unsigned int	color_to_int(t_color *color);
void			render_scene(t_data *data, int i, int j);

#endif
