/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_turn2unit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:28:25 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/21 22:55:18 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	Turns a vector into a unit vector (module = 1)
*/
t_coords	turn2unit(t_coords original)
{
	t_coords	result;
	float		module;

	module = getmodule(original);
	result.x = original.x / module;
	result.y = original.y / module;
	result.z = original.z / module;
	return (result);
}
