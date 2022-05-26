/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light2fig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:53:11 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/29 21:02:30 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
* *	This function gets the color of a surface and the color and brightness of 
* *	the light appllied to it and returns the resulting color.
* @param fig_color Color of the point being evaluated.
* @param light_color Color of the incident light.
* @param light_brightness Brightness (0-1) of the sum of lights at that point.
*/
t_colors	light2fig(t_colors fig_color, t_colors light_color, \
float light_brightness)
{
	t_colors	result;

	result.r = (fig_color.r) * ((light_color.r * light_brightness) / 255);
	result.g = (fig_color.g) * ((light_color.g * light_brightness) / 255);
	result.b = (fig_color.b) * ((light_color.b * light_brightness) / 255);
	if (result.r > 255.0)
		result.r = 255.0;
	if (result.g > 255.0)
		result.g = 255.0;
	if (result.b > 255.0)
		result.b = 255.0;
	return (result);
}

/**
* *	This function gets the color of two lights colliding at the same point
* * and merges them toghether.
* @param color1 First color to be added.
* @param bright1 Brightness of the first color to be added.
* @param color2 Second color to be added.
* @param bright2 Brightness of the second color to be added.
* @retval Returns a t_colors with the resulting color (brightness = 1.0).
* Calculated by c1 * b1 + c2 * b2.
*/
t_colors	color_sum(t_colors color1, float bright1, t_colors color2, float \
bright2)
{
	t_colors	result;

	result.r = color1.r * bright1 + color2.r * bright2;
	result.g = color1.g * bright1 + color2.g * bright2;
	result.b = color1.b * bright1 + color2.b * bright2;
	if (result.r >= 255.0)
		result.r = 255.0;
	if (result.g >= 255.0)
		result.g = 255.0;
	if (result.b >= 255.0)
		result.b = 255.0;
	return (result);
}
