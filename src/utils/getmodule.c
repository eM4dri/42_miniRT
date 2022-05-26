/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmodule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:57:34 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/15 20:51:52 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * * Returns vector's module
 * @param vector
*/
float	getmodule(t_coords vector)
{
	float	result;

	result = sqrtf(powf(vector.x, 2) + powf(vector.y, 2) + powf(vector.z, 2));
	return (fabs(result));
}

t_colors	set_color(const char *rgb)
{
	t_colors	color;
	char		**split;

	split = ft_split(rgb, ',');
	color.r = ft_atof(split[0]);
	color.g = ft_atof(split[1]);
	color.b = ft_atof(split[2]);
	megafree(&split);
	return (color);
}

t_coords	set_coords(const char *coords)
{
	t_coords	coordinates;
	char		**split;

	split = ft_split(coords, ',');
	coordinates.x = ft_atof(split[0]);
	coordinates.y = ft_atof(split[1]);
	coordinates.z = ft_atof(split[2]);
	megafree(&split);
	return (coordinates);
}
