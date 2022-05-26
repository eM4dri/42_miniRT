/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_cam_vectors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:01:28 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/26 21:34:50 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	Setting all the vectors from the two vertical margins knowing the vectors
*	of the 4 corners.
*/
static void	set_cam_margins(t_coords **matrix)
{
	int			ctr;
	int			max_x;
	int			max_y;
	t_coords	diff;

	ctr = 1;
	max_x = HORIZ_RESOLUTION - 1;
	max_y = VERT_RESOLUTION - 1;
	while (ctr < VERT_RESOLUTION)
	{
		diff.x = matrix[0][max_y].x - matrix[0][0].x;
		diff.y = matrix[0][max_y].y - matrix[0][0].y;
		diff.z = matrix[0][max_y].z - matrix[0][0].z;
		matrix[0][ctr].x = matrix[0][0].x + (diff.x / (max_y)) * ctr;
		matrix[0][ctr].y = matrix[0][0].y + (diff.y / (max_y)) * ctr;
		matrix[0][ctr].z = matrix[0][0].z + (diff.z / (max_y)) * ctr;
		diff.x = matrix[max_x][max_y].x - matrix[max_x][0].x;
		diff.y = matrix[max_x][max_y].y - matrix[max_x][0].y;
		diff.z = matrix[max_x][max_y].z - matrix[max_x][0].z;
		matrix[max_x][ctr].x = matrix[max_x][0].x + (diff.x / (max_y)) * ctr;
		matrix[max_x][ctr].y = matrix[max_x][0].y + (diff.y / (max_y)) * ctr;
		matrix[max_x][ctr].z = matrix[max_x][0].z + (diff.z / (max_y)) * ctr;
		ctr++;
	}
}

/*
*	Setting all the other vectors knowing the vectors of the margins 
*	(right and left).
*/
static void	set_cam_middle(t_coords **matrix)
{
	int			ctr_x;
	int			ctr_y;
	int			max_x;
	t_coords	diff;

	ctr_y = 0;
	max_x = HORIZ_RESOLUTION - 1;
	while (ctr_y < VERT_RESOLUTION)
	{
		ctr_x = 0;
		diff.x = matrix[max_x][ctr_y].x - matrix[0][ctr_y].x;
		diff.y = matrix[max_x][ctr_y].y - matrix[0][ctr_y].y;
		diff.z = matrix[max_x][ctr_y].z - matrix[0][ctr_y].z;
		while (ctr_x < max_x)
		{
			matrix[ctr_x][ctr_y].x = matrix[0][ctr_y].x + \
			(diff.x / (max_x + 1)) * ctr_x;
			matrix[ctr_x][ctr_y].y = matrix[0][ctr_y].y + \
			(diff.y / (max_x + 1)) * ctr_x;
			matrix[ctr_x][ctr_y].z = matrix[0][ctr_y].z + \
			(diff.z / (max_x + 1)) * ctr_x;
			ctr_x++;
		}
		ctr_y++;
	}
}

/*
*	Creates a matrix with the vector of every pixel and fills it with the
*	appropriate values.
*	The input parameter is a struct with the vectors of the 4 corners.
*/
t_coords	**set_cam_vectors(t_corners corn)
{
	t_coords	**matrix;
	int			ctr;

	matrix = ft_calloc(sizeof(t_coords *), HORIZ_RESOLUTION + 1);
	ctr = 0;
	while (ctr < HORIZ_RESOLUTION)
	{
		matrix[ctr] = ft_calloc(sizeof(t_coords), VERT_RESOLUTION + 1);
		ctr++;
	}
	matrix[0][0] = corn.tl;
	matrix[HORIZ_RESOLUTION - 1][0] = corn.tr;
	matrix[0][VERT_RESOLUTION - 1] = corn.bl;
	matrix[HORIZ_RESOLUTION - 1][VERT_RESOLUTION - 1] = corn.br;
	set_cam_margins(matrix);
	set_cam_middle(matrix);
	return (matrix);
}

void	free_array_coords(t_coords ***list)
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
