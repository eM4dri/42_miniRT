/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_managing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:03:01 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/26 21:26:27 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	More info: 
?	https://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection
*/
static float	sphere_formula2(t_vectors ray, t_item sphere)
{
	float	frst;
	float	scnd;

	frst = powf(dot_product(ray.dir, v_v_sub(ray.loc, sphere.loc)), 2);
	scnd = powf(getmodule(v_v_sub(ray.loc, sphere.loc)), 2) - \
	powf(sphere.diameter / 2, 2);
	return (frst - scnd);
}

/*
*	Returns the number of times the ray collides with a sphere (0-2).
*/
int	line_sphere_collisionsnum(t_vectors ray, t_item sphere)
{
	float	calc;

	calc = sphere_formula2(ray, sphere);
	if (calc < 0.0)
		return (0);
	else if (calc == 0.0)
		return (1);
	else
		return (2);
}

/*
*	Here we're getting how many times must the vector from the camera advance
*	to find the collision point (starting from the camera "eye").
	Tangent rays are also counted.
*/
float	get_ray_sphere_distance(t_vectors ray, t_item sphere)
{
	float	first_part;
	float	distance_one;
	float	distance_two;

	first_part = -dot_product(ray.dir, v_v_sub(ray.loc, sphere.loc));
	distance_one = first_part + sqrtf(sphere_formula2(ray, sphere));
	distance_two = first_part - sqrtf(sphere_formula2(ray, sphere));
	if (distance_two > 0.0)
		return (distance_two);
	else
		return (distance_one);
}
