/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:55:21 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/26 21:32:48 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
!	Function only called when the ray collides with the plane.
*	Gets the collision point of the ray with the plane, along with the
*	normal vector of that point, the color of the plane (without lights)
*	and its ID.
*/
static t_figure_point	get_plane_point(t_vectors ray, t_item plane)
{
	t_vectors		plane_vectors;
	t_figure_point	result;
	float			t;

	plane_vectors.dir = turn2unit(plane.orient);
	plane_vectors.loc = plane.loc;
	t = get_the_t(ray, plane_vector2equation(plane_vectors));
	result.loc = v_v_sum(v_f_mult(turn2unit(ray.dir), t), ray.loc);
	result.dir = turn2unit(rotate_plane_if_needed(\
		dir_and_loc_2_vector(plane.loc, plane.orient), ray));
	result.color = plane.color;
	result.id = plane.id;
	return (result);
}

/*
!	Function only called when the ray collides with the sphere.
*	Gets the collision point of the ray with the sphere, along with the
*	normal vector of that point, the color of the sphere (without lights)
*	and its ID.
*/
static t_figure_point	get_sphere_point(t_vectors ray, t_item sphere)
{
	t_figure_point	result;

	result.loc = v_v_sum(v_f_mult(ray.dir, get_ray_sphere_distance(ray, \
	sphere)), ray.loc);
	result.dir = v_v_sub(result.loc, sphere.loc);
	result.color = sphere.color;
	result.id = sphere.id;
	return (result);
}

/*
!	Function only called when the ray collides with the cylinder.
*	Gets the collision point of the ray with the cylinder, along with the
*	normal vector of that point, the color of the cylinder (without lights)
*	and its ID.
*/
static t_figure_point	get_cylinder_point(t_vectors ray, t_item cylinder)
{
	t_figure_point	result;
	int				rev_ori;
	t_coords		p_min_pprime;

	ray.dir = turn2unit(ray.dir);
	cylinder.orient = turn2unit(cylinder.orient);
	if (cylinder_wall(ray, cylinder, &(result.loc)))
	{
		p_min_pprime = v_v_sub(result.loc, cylinder.loc);
		result.dir = v_v_sub(p_min_pprime, v_f_mult(cylinder.orient, \
		dot_product(p_min_pprime, cylinder.orient)));
	}
	else if (cylinder_lid(ray, cylinder, &(result.loc), &rev_ori))
		result.dir = turn2unit(v_f_mult(cylinder.orient, rev_ori));
	result.color = cylinder.color;
	result.id = cylinder.id;
	return (result);
}

/*
*	This function gets the list of items and the ray being evaluated when
*	there's at least one collision. It will return the closest collision
*	point, along with the normal vector and the color of the figure involved
*	mixed with the color and brightness of the ALIGHT.
*/
t_figure_point	get_closest_fig_point(t_vectors ray, t_item *items)
{
	t_figure_point	new_point;
	t_figure_point	top_point;
	t_item			*items2;

	top_point.id = -42;
	items2 = items;
	while (items)
	{
		new_point.id = -21;
		if (items->type == SPHERE && touches_sphere(ray, *(items)))
			new_point = get_sphere_point(ray, *(items));
		else if (items->type == PLANE && touches_plane(ray, *(items)))
			new_point = get_plane_point(ray, *(items));
		else if (items->type == CYLINDER && touches_cylinder(ray, *(items)))
			new_point = get_cylinder_point(ray, *(items));
		if (new_point.id != -21 && (top_point.id == -42 || getmodule(v_v_sub(\
		new_point.loc, ray.loc)) < getmodule(v_v_sub(top_point.loc, ray.loc))))
			top_point = new_point;
		if (items->next == NULL)
			break ;
		items = items->next;
	}
	calculate_reflection(&top_point, items2, get_item_by_type(&items, ALIGHT), \
	ray);
	return (top_point);
}

/**
 * Here we're checking if there's an object between the light and the point
 * being evaluated. To know if there's objects in between, we check the
 * distance from the light to the first point touched. 
 * If the object we touch is closer to the light than the point evaluated, we
 * consider it an obstacle. The problem is that a slight inconsistency with
 * floats can make the beam collide decimals before it's supposed to. 
 * 
 * 
 * @retval 1 means that no interruptions were found.
 * @retval 0 means an interruption was found.
 */
int	find_light_interruption(t_item light, t_figure_point target, t_item *items)
{
	t_figure_point	new_point;
	t_vectors		ray;

	ray.dir = turn2unit(v_v_sub(target.loc, light.loc));
	ray.loc = light.loc;
	new_point.id = -42;
	while (items)
	{
		if (items->id != target.id)
		{
			if (items->type == SPHERE && touches_sphere(ray, *(items)))
				new_point = get_sphere_point(ray, *(items));
			else if (items->type == PLANE && touches_plane(ray, *(items)))
				new_point = get_plane_point(ray, *(items));
			else if (items->type == CYLINDER && touches_cylinder(ray, *(items)))
				new_point = get_cylinder_point(ray, *(items));
			if (new_point.id != -42 && getmodule(v_v_sub(new_point.loc, \
			light.loc)) < getmodule(v_v_sub(target.loc, light.loc)))
				return (0);
		}
		items = items->next;
	}
	return (1);
}
