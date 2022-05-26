/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:04:24 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/26 20:01:36 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define BACKGROUND_COLOR 0x0

/**
 * * Returns color matrix malloced with a background color set
*/
static int	**create_color_matrix(void)
{
	int	i;
	int	**c_matrix;

	c_matrix = malloc(sizeof(int *) * (HORIZ_RESOLUTION + 1));
	c_matrix[HORIZ_RESOLUTION] = NULL;
	i = -1;
	while (++i < HORIZ_RESOLUTION)
	{
		c_matrix[i] = malloc(sizeof(int) * (VERT_RESOLUTION + 1));
		c_matrix[i][VERT_RESOLUTION] = 0;
	}
	return (c_matrix);
}

/**
 * * Set color of a matrix's pixel
 * @param items		items  
 * @param cam		cam
 * @param pixel		matrix's pixel to set color
*/
static int	set_color_pixel(t_item *items, t_item cam, t_coords *pixel)
{
	t_figure_point	cp;

	cp = get_closest_fig_point(dir_and_cam_2_vector(cam, *pixel), items);
	return (rgb2int(cp.color));
}

/*
*	In this function, we're creating a matrix to store the color of each pixel
*	in rgb (transformed to an int).
*/
int	**set_color_matrix(t_item *items, t_coords **v_matrix, t_item cam)
{
	int				x;
	int				y;
	int				**c_matrix;

	y = -1;
	c_matrix = create_color_matrix();
	while (++y < VERT_RESOLUTION)
	{
		x = -1;
		while (++x < HORIZ_RESOLUTION)
		{
			if (check4collisions(v_matrix[x][y], items, cam))
				c_matrix[x][y] = set_color_pixel(items, cam, &v_matrix[x][y]);
			else
				c_matrix[x][y] = BACKGROUND_COLOR;
		}
	}
	lst_rt_print(items);
	return (c_matrix);
}

void	free_array_colors(int ***list)
{
	int	a;

	a = 0;
	if (*list)
	{
		while ((*list)[a])
			free((*list)[a++]);
		free((*list)[a]);
		free(*list);
	}
}
