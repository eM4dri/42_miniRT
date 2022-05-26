/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:16:37 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/24 21:09:36 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define ERROR_SCENE "Error: invadid scene\n"
#define ERROR_EXTENSION_SCENE "Error: Introduce a valid scene (.rt file)\n"

//* Element type counters to handle errors
typedef struct s_mandatory_items
{
	int	ambient;
	int	camera;
	int	light;
}t_mandatory_items;

t_item	*init_new_item(t_item	*item)
{
	item->brightness = 0.0;
	item->color.r = 0.0;
	item->color.g = 0.0;
	item->color.b = 0.0;
	item->diameter = 0.0;
	item->fov = 0.0;
	item->height = 0.0;
	item->id = -1;
	item->loc.x = 0.0;
	item->loc.y = 0.0;
	item->loc.z = 0.0;
	item->orient.x = 0.0;
	item->orient.y = 0.0;
	item->orient.z = 0.0;
	item->next = NULL;
	item->type = -1;
	return (item);
}

/**
 * * Get item from a line read of a scene file regarding element's type
 * @param line	line to process from scene file
 * @return 		*t_item/NULL as ok/error
 */
static	t_item	*get_item(char	*line)
{
	t_item	*item;
	char	**sep_line;

	item = NULL;
	sep_line = ft_split(line, ' ');
	if (!ft_strcmp(sep_line[0], "A") || !ft_strcmp(sep_line[0], "C") || \
		!ft_strcmp(sep_line[0], "L") || !ft_strcmp(sep_line[0], "bh"))
		item = fill_struct_by_type(sep_line);
	else if (!ft_strcmp(sep_line[0], "sp") || !ft_strcmp(sep_line[0], "pl") || \
		!ft_strcmp(sep_line[0], "cy"))
		item = fill_struct_by_type_figures(sep_line);
	megafree(&sep_line);
	return (item);
}

/**
 * * Get item from a line read of a scene file
 * @param list	list of items to populate
 * @param line	line to process from scene file
 * @param m		element type counters to handle errors
 * @return 		FALSE/TRUE as ok/error
 */
static int	try_get_item(t_item **list, char *line, t_mandatory_items *m, \
							int id)
{
	t_item	*item;

	while (ft_isspace(*line))
		line++;
	if (*line == '\0' || *line == '\n')
		return (FALSE);
	item = get_item(line);
	if (item == NULL)
		return (TRUE);
	m->ambient += (item->type == ALIGHT);
	m->camera += (item->type == CAMERA);
	m->light += (item->type == LIGHT);
	item->id = id;
	lst_rt_add_front(list, item);
	if (m->ambient > 1 || m->camera > 1 || (m->light > 1 && !MULTIPLE_LIGHTS))
		return (TRUE);
	return (FALSE);
}

/**
 * * Get items from a given scene file
 * @param list	returned list of items
 * @param fd	file descriptor of scene file to process
 * @param m		element type counters to handle errors
*/
static void	try_get_items(t_item **list, int fd, t_mandatory_items	*m)
{
	char	*line;
	int		id;
	int		error;

	error = FALSE;
	id = 0;
	while (get_next_line(fd, &line) > 0 && !error)
	{
		error = try_get_item(list, line, m, id++);
		free(line);
	}
	if (!error)
		error = try_get_item(list, line, m, id++);
	free(line);
	if (error || m->ambient != 1 || m->camera != 1 || \
	(m->light != 1 && !MULTIPLE_LIGHTS))
	{
		lst_rt_free(list);
		ft_putstr_fd(ERROR_SCENE, STDERR_FILENO);
	}
}

/**
 * * Get items from a given scene file
 * @param list			returned list of items
 * @param scene_file	scene file to process
*/
void	get_items(t_item **list, char *scene_file)
{
	int					fd;
	t_mandatory_items	m;

	if (ft_strncmp(&scene_file[ft_strlen(scene_file) - 3], ".rt", 3))
		ft_putstr_fd(ERROR_EXTENSION_SCENE, STDERR_FILENO);
	else
	{
		m.ambient = 0;
		m.camera = 0;
		m.light = 0;
		fd = open(scene_file, O_RDONLY);
		if (fd < 0)
			perror(LIT_ERROR);
		else
			try_get_items(list, fd, &m);
		if (close(fd) < 0 && fd != -1)
		{
			perror(LIT_ERROR);
			lst_rt_free(list);
		}
	}
}
