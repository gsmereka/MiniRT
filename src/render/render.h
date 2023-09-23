/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:23:16 by gsmereka          #+#    #+#             */
/*   Updated: 2023/09/23 01:30:38 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// render
int			test_render(t_data	*data); // SO PRA TESTES
void		render(t_data *data);
void		paint_pixel(int x, int y, unsigned int color, t_data *data);
int			handle_esc(int key, t_data *data);
int			handle_x(t_data *data);

#endif
