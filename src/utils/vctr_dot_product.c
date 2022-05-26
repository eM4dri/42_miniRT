/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_dot_product.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:44:57 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/30 20:09:51 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	Returns the cosine of the angle between two vectors.
	Yes, the function can be shortened into a single line, but it makes it
	less readable:
?	return (dot_product(va, vb) / (getmodule(va) * getmodule(vb)));
*/
float	get_cos(t_coords va, t_coords vb)
{
	float	dividend;
	float	divisor;

	dividend = dot_product(va, vb);
	divisor = getmodule(va) * getmodule(vb);
	return (dividend / divisor);
}

/*
*	Returns the dot product of two vectors.
*/
float	dot_product(t_coords va, t_coords vb)
{
	return ((va.x * vb.x) + (va.y * vb.y) + (va.z * vb.z));
}
