/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_reflection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:22:08 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/27 19:58:41 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	single_light(t_figure_point point, t_item light, t_item *items)
{
	t_coords	incision_vector;
	float		vect_cos;

	items = NULL;
	incision_vector = v_v_sub(light.loc, point.loc);
	vect_cos = get_cos(incision_vector, point.dir);
	if (vect_cos < 0.0)
		vect_cos = 0.0;
	if (vect_cos > 1.0)
		vect_cos = 1.0;
	return (vect_cos);
}

static t_colors	bness2rgb(t_colors *init_color, float brightness)
{
	t_colors	final_colors;

	if (!init_color)
	{
		final_colors.r = 0.0;
		final_colors.g = 0.0;
		final_colors.b = 0.0;
	}
	else
	{
		final_colors.r = init_color->r * brightness;
		final_colors.g = init_color->g * brightness;
		final_colors.b = init_color->b * brightness;
	}
	return (final_colors);
}

static t_colors	render_specular(t_colors tot_phong_color, \
t_figure_point *point, t_vectors ray, t_item *lights)
{
	t_colors	result;

	if (RENDER_PHONG)
	{
		result = color_sum(tot_phong_color, 1.0, \
		lights->color, specular_reflection(*lights, *point, ray) \
		* lights->brightness * (0.45 / (0.5 + 0.1 * (getmodule(\
		v_v_sub(point->loc, lights->loc)))) + 0.1));
		return (result);
	}
	else
		return (tot_phong_color);
}

/**
 * * In this function, we're calculating what lights (ambient and 
 * * multidirectional) collide with the point being evaluated and we add them 
 * * all toghether considering the angle between the normal vector of the point
 * * and the light and the brightness of each light.
 * * Then, we apply the overall light to the color of the point.
 * * If RENDER_PHONG is set to true, it will also apply the Specular Reflection
 * * to the overall color, but this one gets applied directly above the figure.
 * 
 * @param point A struct containing the location of the collision point, its 
 * normal vector, the color of the object (not counting lights) and its ID.
 * @param items List of all the items.
 * @param item_alight The ambient light of the scene.
 * @param ray The current ray projected bby the camera (struct containing the 
 * loc and dir as a unitary vector).
 *
 * @retval Nothing is returned, but the value of color in point gets modified.
*/
void	calculate_reflection(t_figure_point *point, t_item *items, \
t_item item_alight, t_vectors ray)
{
	t_item		*lights;
	t_colors	tot_light_color;
	float		bness;
	t_colors	phong;

	tot_light_color = bness2rgb(&(item_alight.color), item_alight.brightness);
	phong = bness2rgb(NULL, 0);
	lights = items;
	while (lights)
	{
		if (lights->type == LIGHT || lights->type == BLACK_HOLE)
		{
			if (find_light_interruption(*(lights), *point, items))
			{
				bness = single_light(*point, *(lights), items);
				tot_light_color = color_sum(tot_light_color, 1.0, \
				lights->color, bness * lights->brightness);
				phong = render_specular(phong, point, ray, lights);
			}
		}
		lights = lights->next;
	}
	point->color = color_sum(light2fig(point->color, tot_light_color, 1.0), \
	1.0, phong, (float)RENDER_PHONG);
}
