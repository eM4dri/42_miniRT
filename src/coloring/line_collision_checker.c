/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_collision_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:17:25 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/26 21:33:51 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	This function recieves the ray being casted and the sphere being 
*	evaluated and returns 1 if the ray collides at some point with the sphere
*	and 0 otherwise.
*/
int	touches_sphere(t_vectors ray, t_item sphere)
{
	if (line_sphere_collisionsnum(ray, sphere) == 0)
		return (0);
	if (get_ray_sphere_distance(ray, sphere) < 0.0)
		return (0);
	else
		return (1);
}

/*
*	This function recieves the ray being casted and the cylinder being 
*	evaluated and returns 1 if the ray collides at some point with the 
*	cylinder and 0 otherwise.
*/
int	touches_cylinder(t_vectors ray, t_item cylinder)
{
	t_coords	result;

	if (cylinder_wall(ray, cylinder, &(result)))
		return (1);
	else if (cylinder_lid(ray, cylinder, &result, NULL))
		return (1);
	return (0);
}

/*
*	This function recieves the ray being casted and the plane being 
*	evaluated and returns 1 if the ray collides at some point with the 
*	plane and 0 otherwise.
*	Intersection plane-line
?	https://www.youtube.com/watch?v=Is_wLo6yhxE
*/
int	touches_plane(t_vectors ray, t_item plane)
{
	t_vectors	plane_vectors;
	int			result;

	plane_vectors.dir = turn2unit(plane.orient);
	plane_vectors.loc = plane.loc;
	result = line_plane_correlation(ray, plane_vector2equation(plane_vectors));
	if (!result)
		return (1);
	else
		return (0);
}

/*
*	This function goes through all the items checking if any of them are in
*	the way of the ray. Returns the number of collisions.
*/
int	check4collisions(t_coords vector, t_item *items, t_item	cam)
{
	t_vectors	ray;
	int			touches;

	ray.dir = turn2unit(vector);
	ray.loc = cam.loc;
	touches = 0;
	while (items && !touches)
	{
		if (items->type == SPHERE)
			touches += touches_sphere(ray, *(items));
		else if (items->type == CYLINDER)
			touches += touches_cylinder(ray, *(items));
		else if (items->type == PLANE)
			touches += touches_plane(ray, *(items));
		items = items->next;
	}
	return (touches);
}
