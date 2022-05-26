/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_corners.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:26:26 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/26 20:26:59 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_corners	corners_write2struct(t_coords unit_v, t_coords unit_q, \
t_coords a, int fov)
{
	t_corners	corn;
	float		ang_tan;

	ang_tan = tanf(deg2rad(fov / 2.0));
	corn.tl.x = unit_v.x - ang_tan * unit_q.x + ang_tan * (9.0 / 16.0) * a.x;
	corn.tl.y = unit_v.y - ang_tan * unit_q.y + ang_tan * (9.0 / 16.0) * a.y;
	corn.tl.z = unit_v.z - ang_tan * unit_q.z + ang_tan * (9.0 / 16.0) * a.z;
	corn.tr.x = unit_v.x + ang_tan * unit_q.x + ang_tan * (9.0 / 16.0) * a.x;
	corn.tr.y = unit_v.y + ang_tan * unit_q.y + ang_tan * (9.0 / 16.0) * a.y;
	corn.tr.z = unit_v.z + ang_tan * unit_q.z + ang_tan * (9.0 / 16.0) * a.z;
	corn.bl.x = unit_v.x - ang_tan * unit_q.x - ang_tan * (9.0 / 16.0) * a.x;
	corn.bl.y = unit_v.y - ang_tan * unit_q.y - ang_tan * (9.0 / 16.0) * a.y;
	corn.bl.z = unit_v.z - ang_tan * unit_q.z - ang_tan * (9.0 / 16.0) * a.z;
	corn.br.x = unit_v.x + ang_tan * unit_q.x - ang_tan * (9.0 / 16.0) * a.x;
	corn.br.y = unit_v.y + ang_tan * unit_q.y - ang_tan * (9.0 / 16.0) * a.y;
	corn.br.z = unit_v.z + ang_tan * unit_q.z - ang_tan * (9.0 / 16.0) * a.z;
	return (corn);
}

static t_coords	get_unit_q(t_coords unit_v)
{
	t_coords	q;
	t_coords	unit_q;
	float		module;

	q.x = -unit_v.z;
	q.y = 0.0;
	q.z = unit_v.x;
	module = getmodule(q);
	if (module)
	{
		unit_q.x = q.x / module;
		unit_q.z = q.z / module;
	}
	else
	{
		unit_q.x = 1.0;
		unit_q.z = 0.0;
	}
	unit_q.y = 0.0;
	return (unit_q);
}

/*
*	Setting the vectors of the 4 corners considering the location and
*	orientation of the camera and the FOV.
?	NOTE: We consider that the 2 top corners and the 2 bottom corners
?	must have the same y coordinate (so the camera is never tilted).
*/
t_corners	set_corners(t_item item)
{
	t_coords	unit_v;
	t_coords	unit_q;
	t_coords	a;
	t_corners	corn;

	unit_v = turn2unit(item.orient);
	unit_q = get_unit_q(unit_v);
	a.x = -unit_q.z * unit_v.y;
	a.y = +unit_v.x * unit_q.z - unit_q.x * unit_v.z;
	a.z = unit_q.x * unit_v.y;
	corn = corners_write2struct(unit_v, unit_q, a, item.fov);
	return (corn);
}
