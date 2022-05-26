/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb2int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:13:48 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/27 17:01:36 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	Gets a color in its rgb form (struct t_colors) and returns the int value 
*	of such color.
!	Be careful with the precision of each float, as we're turning floats to 
!	ints ≥ 0 and ≤ 255.
*/
int	rgb2int(t_colors rgb)
{
	int	result;

	if (rgb.r < 0.0)
		rgb.r = 0.0;
	if (rgb.g < 0.0)
		rgb.g = 0.0;
	if (rgb.b < 0.0)
		rgb.b = 0.0;
	if (rgb.r > 255.0)
		rgb.r = 255.0;
	if (rgb.g > 255.0)
		rgb.g = 255.0;
	if (rgb.b > 255.0)
		rgb.b = 255.0;
	result = (int)rgb.b + (int)rgb.g * 256 + (int)rgb.r * 256 * 256;
	return (result);
}
