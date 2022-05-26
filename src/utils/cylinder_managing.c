/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_managing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:13:43 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/22 18:08:44 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * *	This function gets the a, b and c values for a second degree equation
 * *	and writes the two results in d.
 * 
 * @note
 * -b ± sqrt(b^2 - 4ac)
 * --------------------
 * 			2a
 * 
 * @param a ax^2
 * @param b bx
 * @param c c
 * @param d[2] An array of two floats to store the two possible solutions.
 * 
 * @retval 0 No solutions could be found.
 * @retval 1 One or two solutions were found.
*/
int	second_degree_equation(float a, float b, float c, float d[2])
{
	float	inside_sqrt;

	if (a == 0.0 || powf(b, 2.0) < 4.0 * a * c)
		return (0);
	inside_sqrt = powf(b, 2.0) - (4.0 * a * c);
	d[0] = (-b + sqrtf(inside_sqrt)) / (2.0 * a);
	d[1] = (-b - sqrtf(inside_sqrt)) / (2.0 * a);
	return (1);
}
