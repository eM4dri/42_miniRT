/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:37:23 by emadriga          #+#    #+#             */
/*   Updated: 2022/04/16 20:30:10 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define NON_ZERO_NUMBERS "123456789"

/**
 * * Validates string nbr contents within range
* @param s_nbr	string nbr to process
* @param min	min range
* @param max	max range
* @return 		FALSE/TRUE as ok/error
*/
static int	not_valid_range(const char *s_nbr, long min, long max)
{
	double	d;
	size_t	i;

	d = 0;
	i = 0;
	if (s_nbr[0] == '-' && ft_isdigit(s_nbr[1]))
	{
		d = (s_nbr[1] - '0') * -1;
		i += 2;
	}
	else if (s_nbr[0] == '+')
		i++;
	while (s_nbr[i] != '\0' && ft_isdigit(s_nbr[i]) && (d < max || d > min))
		d = d * 10 + s_nbr[i++] - '0';
	if (s_nbr[i] == '.')
		while (!ft_strchr(NON_ZERO_NUMBERS, s_nbr[i]))
			i++;
	d += (ft_isdigit(s_nbr[i]) && s_nbr[0] != '-');
	d -= (ft_isdigit(s_nbr[i]) && s_nbr[0] == '-');
	if (d > max || d < min)
		return (TRUE);
	return (FALSE);
}

/**
 * * Validates allowed characters(decimal)
 * * Acept just one char as sign and one dot as decimal separator
* @param s_nbr	string nbr to process
* @return 		FALSE/TRUE as ok/error
*/
static int	not_valid_nbr_characters(char *s_nbr)
{
	int		dots_used;

	dots_used = NONE;
	if (!(ft_isdigit(s_nbr[0])) && \
	!(ft_isdigit(s_nbr[1]) && (s_nbr[0] == '-' || s_nbr[0] == '+')))
		return (TRUE);
	if (*s_nbr == '-' || *s_nbr == '+')
		s_nbr++;
	while (*s_nbr != '\0' && !ft_isspace(*s_nbr))
	{
		if (!ft_isdigit(*s_nbr) && *s_nbr != '.')
			return (TRUE);
		dots_used += (*s_nbr == '.');
		if (dots_used > 1)
			break ;
		s_nbr++;
	}
	if (*s_nbr != '\0')
		return (TRUE);
	return (FALSE);
}

/**
 * * Try to set a decimal nbr from str given
* @param out	returned decimal number
* @param nbr	string nbr to process
* @param min	min range
* @param max	max range
* @return 		0/1 as ok/error
*/
int	try_set_atof(float *out, char *nbr, long min, long max)
{
	if (not_valid_nbr_characters(nbr))
		return (1);
	if (not_valid_range(nbr, min, max))
		return (1);
	*out = ft_atof(nbr);
	return (0);
}

/**
 * * Try to set a color from str given
* @param out	returned color
* @param rgb	string color to process
* @return 		0/1 as ok/error
*/
int	try_set_color(t_colors *out, const char *rgb)
{
	char		**split;
	int			error;

	split = ft_split(rgb, ',');
	error = (split[3] != NULL);
	if (!error)
		error += try_set_atof(&out->r, split[0], 0.0, 255.0);
	if (!error)
		error += try_set_atof(&out->g, split[1], 0.0, 255.0);
	if (!error)
		error += try_set_atof(&out->b, split[2], 0.0, 255.0);
	megafree(&split);
	return (error);
}

/**
 * * Try to set a coordinates from str given
* @param out	returned coordinates
* @param coords	string coordinates to process
* @param min	min range
* @param max	max range
* @return 		0/1 as ok/error
*/
int	try_set_coords(t_coords *out, const char *coords, long min, long max)
{
	char		**split;
	int			error;

	split = ft_split(coords, ',');
	error = (split[3] != NULL);
	if (!error)
		error += try_set_atof(&out->x, split[0], min, max);
	if (!error)
		error += try_set_atof(&out->y, split[1], min, max);
	if (!error)
		error += try_set_atof(&out->z, split[2], min, max);
	megafree(&split);
	return (error);
}
