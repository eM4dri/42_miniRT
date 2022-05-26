/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_by_type_figures.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:11:58 by jvacaris          #+#    #+#             */
/*   Updated: 2022/05/04 11:01:09 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_item	*line2sphere(char **line, t_item	*item)
{
	int	error;

	error = (get_array_size(line) != 4);
	item->type = SPHERE;
	if (!error)
		error += try_set_coords(&item->loc, line[1], MIN_PARSED_SIZE, \
				MAX_PARSED_SIZE);
	if (!error)
		error += try_set_atof(&item->diameter, line[2], 0.0, MAX_PARSED_SIZE);
	if (!error)
		error += try_set_color(&item->color, line[3]);
	if (error)
		ft_free((void **) &item);
	return (item);
}

static t_item	*line2plane(char **line, t_item	*item)
{
	int	error;

	error = (get_array_size(line) != 4);
	item->type = PLANE;
	if (!error)
		error += try_set_coords(&item->loc, line[1], MIN_PARSED_SIZE, \
				MAX_PARSED_SIZE);
	if (!error)
		error += try_set_coords(&item->orient, line[2], -1.0, 1.0);
	if (!error)
		error += try_set_color(&item->color, line[3]);
	if (error)
		ft_free((void **) &item);
	return (item);
}

static t_item	*line2cylinder(char **line, t_item	*item)
{
	int	error;

	error = (get_array_size(line) != 6);
	item->type = CYLINDER;
	if (!error)
		error += try_set_coords(&item->loc, line[1], MIN_PARSED_SIZE, \
				MAX_PARSED_SIZE);
	if (!error)
		error += try_set_coords(&item->orient, line[2], -1.0, 1.0);
	if (!error)
		item->orient = turn2unit(item->orient);
	if (!error)
		error += try_set_atof(&item->diameter, line[3], 0.0, MAX_PARSED_SIZE);
	if (!error)
		error += try_set_atof(&item->height, line[4], 0.0, MAX_PARSED_SIZE);
	if (!error)
		error += try_set_color(&item->color, line[5]);
	if (error)
		ft_free((void **) &item);
	return (item);
}

t_item	*fill_struct_by_type_figures(char **line)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	if (!item)
		return (NULL);
	item = init_new_item(item);
	if (!ft_strcmp(line[0], "sp"))
		item = line2sphere(line, item);
	else if (!ft_strcmp(line[0], "pl"))
		item = line2plane(line, item);
	else if (!ft_strcmp(line[0], "cy"))
		item = line2cylinder(line, item);
	else
		ft_free((void **) &item);
	return (item);
}
