/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lst_functs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/27 19:27:25 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define LIT_TYPES "ALIGHT ☀️,CAMERA 🎥,LIGHT 💡,SPHERE ⚽️,PLANE ⬜️,CYLINDER 🥫,\
BLACK HOLE 🕳️"
#define LIT_TYPE "\n\033[1mtype:\033[0m %s\n"
#define LIT_BRIGHT "\033[1mbright:\033[0m %f\t"
#define LIT_DIAMETER "\033[1mdiameter:\033[0m %f\t"
#define LIT_FOV "\033[1mfov:\033[0m %f\t"
#define LIT_HEIGHT "\033[1mheight:\033[0m %f\t"
#define LIT_COLOR "\n\033[1mcolor:\n\t\033[1;31mR \033[0;31m%f\t\033[1;32mG\
 \033[0;32m%f\t\033[1;34mB \033[0;36m%f\033[0m"
#define LIT_POSITION "\n\033[1mposition:\033[0m\n\t\033[1mX\033[0m %f\t\033[1m\
Y\033[0m %f\t\033[1mZ\033[0m %f"
#define LIT_ORIENTATION "\n\033[1morientantion:\033[0m\n\t\033[1mX\033[0m \
%f\t\033[1mY\033[0m %f\t\033[1mZ\033[0m %f"
#define LIT_SEPARATOR "\033[0;33m ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \033[0m"

/**
 * * Print list
 * @param list
*/
void	lst_rt_print(t_item *i)
{
	char	**type;

	type = ft_split(LIT_TYPES, ',');
	while (i != NULL)
	{
		printf(LIT_TYPE, type[i->type]);
		if (i->type == ALIGHT || i->type == LIGHT || i->type == BLACK_HOLE)
			printf(LIT_BRIGHT, i->brightness);
		if (i->type == CYLINDER || i->type == SPHERE)
			printf(LIT_DIAMETER, i->diameter);
		if (i->type == CAMERA)
			printf(LIT_FOV, i->fov);
		if (i->type == CYLINDER)
			printf(LIT_HEIGHT, i->height);
		if (i->type != CAMERA && i->type != LIGHT && i->type != BLACK_HOLE)
			printf(LIT_COLOR, i->color.r, i->color.g, i->color.b);
		if (i->type != ALIGHT)
			printf(LIT_POSITION, i->loc.x, i->loc.y, i->loc.z);
		if (i->type == CYLINDER || i->type == PLANE || i->type == CAMERA)
			printf(LIT_ORIENTATION, i->orient.x, i->orient.y, i->orient.z);
		printf("\n\033[1mID:\033[0m %d\n\n%s\n", i->id, LIT_SEPARATOR);
		i = i->next;
	}
	megafree(&type);
}

/**
 * * Free list
 * @param list	list
*/
void	lst_rt_free(t_item **list)
{
	t_item	*next;
	t_item	*item;

	next = *list;
	item = *list;
	while (next != NULL)
	{
		next = next->next;
		free(item);
		item = next;
	}
	*list = NULL;
	list = NULL;
}
