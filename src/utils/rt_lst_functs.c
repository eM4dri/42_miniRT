/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lst_functs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/27 19:06:37 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * * Add new node into list at begining
 * @param list		list
 * @param new_node	new node to link
*/
void	lst_rt_add_front(t_item **alst, t_item *new)
{
	if (!alst || !new)
		return ;
	new -> next = *alst;
	*alst = new;
}

/**
 * * Returns an item of list that has the type given.
 * @param item_list	list of items
 * @param type		type of item_list to get
*/
t_item	get_item_by_type(t_item **item_list, int type)
{
	t_item		*item;
	t_item		returning;

	returning.type = -1;
	item = *item_list;
	while (item)
	{
		if (item->type == type)
		{
			returning = *item;
			return (returning);
		}
		item = item -> next;
	}
	return (returning);
}

static t_item	*copy_rt_content(t_item *content)
{
	t_item	*result;

	result = NULL;
	result = malloc(sizeof(t_item));
	result->brightness = content->brightness;
	result->color = content->color;
	result->diameter = content->diameter;
	result->fov = content->fov;
	result->height = content->height;
	result->loc = content->loc;
	result->orient = content->orient;
	result->type = content->type;
	return (result);
}

/**
 * * Filter list from type given.
 * @param item_list	list of items
 * @param type		type of item_list to get
*/
void	get_items_by_type(t_item **filtered_list, t_item *list, int type)
{
	t_item		*content;

	content = NULL;
	while (list != NULL)
	{
		if (list->type == type)
		{
			content = copy_rt_content(list);
			lst_rt_add_front(filtered_list, content);
		}
		list = list->next;
	}
}

void	get_object_items(t_item **filtered_list, t_item *list)
{
	t_item		*content;

	content = NULL;
	while (list != NULL)
	{
		if (list->type == SPHERE || list->type == PLANE \
		|| list->type == CYLINDER)
		{
			content = copy_rt_content(list);
			lst_rt_add_front(filtered_list, content);
		}
		list = list->next;
	}
}
