/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/17 23:20:24 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "dtos.h"

t_item		*fill_struct_by_type(char **line);
t_item		*init_new_item(t_item	*item);
t_item		*fill_struct_by_type_figures(char **line);

void		get_items(t_item **list, char *argv);
t_corners	set_corners(t_item item);
t_coords	**set_cam_vectors(t_corners corn);
void		free_array_coords(t_coords ***list);
int			try_set_atof(float *out, char *nbr, long min, long max);
int			try_set_color(t_colors *out, const char *rgb);
int			try_set_coords(t_coords *out, const char *coords, long min, \
				long max);

#endif
