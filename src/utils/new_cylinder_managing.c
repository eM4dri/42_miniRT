/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cylinder_managing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:11:05 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/27 19:33:58 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
* Nameless operation done multiple times in cylinder_lid and cylinder_wall.
*/
static float	do_the_f(t_coords vec_u, t_coords vec_w, t_coords vec_ori)
{
	return (dot_product(vec_u, vec_w) - dot_product(vec_ori, vec_u) * \
	dot_product(vec_ori, vec_w));
}

/*
*	Continuation of the function below.
*/
static int	set_m_and_pos_ori(float pos_m[2], float *m, int *rev_ori)
{
	if (pos_m[0] >= 0.0 && (pos_m[0] < pos_m[1] || pos_m[1] < 0.0))
	{
		*m = pos_m[0];
		if (rev_ori)
			*rev_ori = 1;
	}
	else if (pos_m[1] >= 0.0 && (pos_m[1] < pos_m[0] || \
	pos_m[0] < 0.0))
	{
		*m = pos_m[1];
		if (rev_ori)
			*rev_ori = -1;
	}
	else
		return (0);
	return (1);
}

/**
* * This functions checks whether a ray collides with the LID of a cylinder.
* 
* @param ray Loc and dir (unit vector) of the ray coming out from the camera.
* @param cylinder The t_item struct of the cylinder being evaluated.
* @param coords Used to return the coordinates of the collision when successful.
* @param rev_ori Set to 1 if the normal vector of the lid matches the normal 
* vector of the cylinder. Otherwise, it returns -1.
* @retval 0 if the ray doesn't collide with the wall of the cylinder and 1 if 
* it does. The coordinates of the collision are returned via the coords 
* parameter.
*/
int	cylinder_lid(t_vectors ray, t_item cyli, t_coords *coords, int *rev_ori)
{
	float		m;
	float		pos_m[2];
	t_coords	pc;
	float		dp;

	dp = dot_product(cyli.orient, ray.dir);
	if (!dp)
		return (0);
	pc = v_v_sub(ray.loc, cyli.loc);
	pos_m[0] = (cyli.height / 2.0 - dot_product(cyli.orient, pc)) / dp;
	pos_m[1] = (-cyli.height / 2.0 - dot_product(cyli.orient, pc)) / dp;
	if (!set_m_and_pos_ori(pos_m, &m, rev_ori))
		return (0);
	if (do_the_f(v_v_sum(pc, v_f_mult(ray.dir, m)), v_v_sum(pc, v_f_mult(\
	ray.dir, m)), cyli.orient) >= powf(cyli.diameter / 2.0, 2.0))
		return (0);
	*coords = v_v_sum(v_f_mult(ray.dir, m), ray.loc);
	return (1);
}

/**
* * This functions checks whether a ray collides with the WALL of a cylinder.
* * If the ray collides with a lid first and then comes out from a wall, this
* * function will consider it DOES NOT collide.
* 
* @param ray Loc and dir (unit vector) of the ray coming out from the camera.
* @param cylinder The t_item struct of the cylinder being evaluated.
* @param coords Used to return the coordinates of the collision when successful.
* @retval 0 if the ray doesn't collide with the wall of the cylinder and 1 if 
* it does. The coordinates of the collision are returned via the coords 
* parameter.
*/
int	cylinder_wall(t_vectors ray, t_item cylinder, t_coords *coords)
{
	float		m;
	float		pos_m[2];
	t_coords	pc;

	pc = v_v_sub(ray.loc, cylinder.loc);
	if (!second_degree_equation(do_the_f(ray.dir, ray.dir, turn2unit(\
	cylinder.orient)), 2.0 * do_the_f(pc, ray.dir, turn2unit(cylinder.orient)), \
	do_the_f(pc, pc, turn2unit(cylinder.orient)) - powf(cylinder.diameter / \
	2.0, 2.0), pos_m))
		return (0);
	if ((pos_m[0] < 0.0 && pos_m[1] > 0.0) || \
		(pos_m[1] < 0.0 && pos_m[0] > 0.0))
		return (0);
	if (pos_m[0] >= 0.0 && (pos_m[0] < pos_m[1] || pos_m[1] < 0.0))
		m = pos_m[0];
	else if (pos_m[1] >= 0.0 && (pos_m[1] < pos_m[0] || pos_m[0] < 0.0))
		m = pos_m[1];
	else
		return (0);
	if (fabs(dot_product(cylinder.orient, v_v_sum(pc, v_f_mult(ray.dir, m)))) \
	> cylinder.height / 2.0)
		return (0);
	if (coords)
		*coords = v_v_sum(ray.loc, v_f_mult(ray.dir, m));
	return (1);
}
