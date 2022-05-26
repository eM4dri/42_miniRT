/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_int_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:37:51 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/26 20:37:38 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	Multiplication of a vector with an int.
*/
t_coords	v_i_mult(t_coords v, int i)
{
	t_coords	result;

	result.x = v.x * i;
	result.y = v.y * i;
	result.z = v.z * i;
	return (result);
}

/*
*	Multiplication of a vector with a float.
*/
t_coords	v_f_mult(t_coords v, float i)
{
	t_coords	result;

	result.x = v.x * i;
	result.y = v.y * i;
	result.z = v.z * i;
	return (result);
}
