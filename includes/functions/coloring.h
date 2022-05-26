/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:01:43 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/26 21:38:09 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORING_H
# define COLORING_H
# include "dtos.h"

int				**set_color_matrix(t_item *items, t_coords **v_matrix, \
						t_item cam);
void			free_array_colors(int ***list);
int				check4collisions(t_coords vector, t_item *items, \
				t_item cam);
t_figure_point	get_closest_fig_point(t_vectors ray, t_item *items);
int				touches_sphere(t_vectors ray, t_item sphere);
int				touches_cylinder(t_vectors ray, t_item cylinder);
int				touches_plane(t_vectors ray, t_item plane);
t_colors		light2fig(t_colors fig_color, t_colors light_color, \
						float light_brightness);
void			calculate_reflection(t_figure_point *point, t_item *items, \
t_item item_alight, t_vectors ray);
t_colors		color_sum(t_colors color1, float bright1, t_colors color2, \
						float bright2);
int				find_light_interruption(t_item light, t_figure_point target, \
						t_item *items);
float			specular_reflection(t_item light, t_figure_point object, \
t_vectors ray);

#endif
