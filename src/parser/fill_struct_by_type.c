/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_by_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:11:58 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/27 22:30:09 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define SET_DEFAULT_LIGHT_COLOR "255,255,255"

static t_item	*line2alight(char **line, t_item	*item)
{
	int	error;

	error = (get_array_size(line) != 3);
	item->type = ALIGHT;
	if (!error)
		error += try_set_atof(&item->brightness, line[1], 0.0, 1.0);
	if (!error)
		error += try_set_color(&item->color, line[2]);
	if (error)
		ft_free((void **) &item);
	return (item);
}

static t_item	*line2camera(char **line, t_item	*item)
{
	int	error;

	error = (get_array_size(line) != 4);
	item->type = CAMERA;
	if (!error)
		error += try_set_coords(&item->loc, line[1], MIN_PARSED_SIZE, \
				MAX_PARSED_SIZE);
	if (!error)
		error += try_set_coords(&item->orient, line[2], -1.0, 1.0);
	if (!error)
		error += try_set_atof(&item->fov, line[3], 0.0, 180.0);
	if (error)
		ft_free((void **) &item);
	return (item);
}

static t_item	*line2light(char **line, t_item	*item)
{
	int	error;

	error = (get_array_size(line) != 4);
	item->type = LIGHT;
	if (!error)
		error += try_set_coords(&item->loc, line[1], MIN_PARSED_SIZE, \
				MAX_PARSED_SIZE);
	if (!error)
		error += try_set_atof(&item->brightness, line[2], 0.0, 1.0);
	if (!error)
		error += try_set_color(&item->color, line[3]);
	if (DEFAULT_LIGHT_COLOR)
		item->color = set_color(SET_DEFAULT_LIGHT_COLOR);
	if (error)
		ft_free((void **) &item);
	return (item);
}

static t_item	*line2blackhole(char **line, t_item	*item)
{
	int	error;

	error = (!ENABLE_EXTRA_ITEMS || get_array_size(line) != 2);
	item->type = BLACK_HOLE;
	if (!error)
		error += try_set_coords(&item->loc, line[1], MIN_PARSED_SIZE, \
				MAX_PARSED_SIZE);
	item->brightness = -1.0;
	item->color = set_color("255,255,255");
	if (error)
		ft_free((void **) &item);
	return (item);
}

t_item	*fill_struct_by_type(char **line)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	if (!item)
		return (NULL);
	item = init_new_item(item);
	if (!ft_strcmp(line[0], "A"))
		item = line2alight(line, item);
	else if (!ft_strcmp(line[0], "C"))
		item = line2camera(line, item);
	else if (!ft_strcmp(line[0], "L"))
		item = line2light(line, item);
	else if (!ft_strcmp(line[0], "bh"))
		item = line2blackhole(line, item);
	else
		ft_free((void **) &item);
	return (item);
}
