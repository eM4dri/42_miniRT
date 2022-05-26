/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg2rad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:31:45 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/26 21:16:50 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * * Turns degrees into radians.
*/
float	deg2rad(float deg)
{
	return (deg * (M_PI / 180.0));
}

/**
 * * Turns radians into degrees.
*/
float	rad2deg(float rad)
{
	return (rad * (180.0 / M_PI));
}
