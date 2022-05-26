/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_managing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:54:09 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/26 21:25:18 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	If the ray comes from the "other side" of the plane, this function will
*	return the inverted normal vector in order to make the reflections look
*	good. The inversion is done by multiplying all the x,y,z values by -1.
*/
t_coords	rotate_plane_if_needed(t_vectors plane, t_vectors ray)
{
	float	module1;
	float	module2;

	module1 = getmodule(v_v_sub(v_v_sum(plane.loc, plane.dir), ray.loc));
	module2 = getmodule(v_v_sub(v_v_sub(plane.loc, plane.dir), ray.loc));
	if (module1 <= module2)
		return (plane.dir);
	else
		return (v_f_mult(plane.dir, -1.0));
}

/*
*	Turning a plane given by its normal vector and a point to a plane
*	represented as an equation ax + by + cz = d
?	https://tutorial.math.lamar.edu/classes/calciii/eqnsofplanes.aspx
*/
t_plane_equation	plane_vector2equation(t_vectors norm_vector)
{
	t_plane_equation	result;

	result.a = norm_vector.dir.x;
	result.b = norm_vector.dir.y;
	result.c = norm_vector.dir.z;
	result.d = -norm_vector.loc.x * norm_vector.dir.x - norm_vector.loc.y * \
	norm_vector.dir.y - norm_vector.loc.z * norm_vector.dir.z;
	return (result);
}

/*
*	Calculating a constant needed to evaluate planes
*	More info:
	Intersection plane-line
?	https://www.youtube.com/watch?v=Is_wLo6yhxE
*/
float	get_the_t(t_vectors ray, t_plane_equation equation)
{
	float	times_t;
	float	not_t;

	times_t = equation.a * ray.dir.x + equation.b * ray.dir.y + equation.c * \
	ray.dir.z;
	not_t = equation.a * ray.loc.x + equation.b * ray.loc.y + equation.c * \
	ray.loc.z + equation.d;
	return ((-not_t) / times_t);
}

/*
*	Checks the correlation of the ray and the plane. Possible cases:
?	0:	Line collides with the plane in front of the camera.
?	1:	Line is parallel AND CONTAINED within the plane.
?	2:	Line is parallel but doesn't collide with the plane at any point.
?	3:	Line colllides with the plane but behind the camera.
*/
int	line_plane_correlation(t_vectors ray, t_plane_equation equation)
{
	float	times_t;
	float	not_t;

	times_t = equation.a * ray.dir.x + equation.b * ray.dir.y + equation.c * \
	ray.dir.z;
	not_t = equation.a * ray.loc.x + equation.b * ray.loc.y + equation.c * \
	ray.loc.z + equation.d;
	if (!times_t && !not_t)
		return (1);
	else if (!times_t)
		return (2);
	else if ((-not_t) / times_t < 0.0)
		return (3);
	else
		return (0);
}
