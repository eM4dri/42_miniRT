/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/26 21:38:37 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "dtos.h"

/**
 * * Add new node into list at begining
 * @param list		list
 * @param new_node	new node to link
*/
void				lst_rt_add_front(t_item **alst, t_item *new_node);

/**
 * * Free list
 * @param list	list
*/
void				lst_rt_free(t_item **list);

/**
 * * Print list
 * @param list
*/
void				lst_rt_print(t_item *list);

/**
 * * Returns an item_list of t_item that has the type given.
 * @param item_list	list of items
 * @param type		type of item_list to get
*/
t_item				get_item_by_type(t_item **item_list, int type);

/**
 * * Returns an item_list of t_item that has the type given.
 * @param item_list	list of items
 * @param type		type of item_list to get
*/
void				get_items_by_type(t_item **filtered_list, t_item *list, \
						int type);

/**
 * * Returns a t_item with all visible items (cylinders, spheres & planes).
*/
void				get_object_items(t_item **filtered_list, t_item *list);

/**
 * * Turns degrees into radians.
*/
float				deg2rad(float deg);

/**
 * * Turns radians into degrees.
*/
float				rad2deg(float rad);

/**
 * * Returns vector's module
 * @param vector	vector we're getting the module from.
*/
float				getmodule(t_coords vector);

/**
 * * Returns a color in a t_colors structure from a string composed of the 
 * * rgb values separated by commas.
 * @param rgb	string in "r,g,b" format (each value goes from 0 to 255).
*/
t_colors			set_color(const char *rgb);

/**
 * * Returns a coordinate in a t_coords structure from a string composed of the
 * * xyz values separated by commas.
 * @param rgb	string in "x,y,z" format.
*/
t_coords			set_coords(const char *coords);

/**
 * * Returns the cross product (×) of two vectors.
*/
t_coords			v_v_cross_product(t_coords a, t_coords b);

/**
 * * Substraction of vector (a) with the vector (b).
*/
t_coords			v_v_sub(t_coords a, t_coords b);

/**
 * * Sum of vector (a) plus the vector (b).
*/
t_coords			v_v_sum(t_coords a, t_coords b);

/**
 * * Multiplication of a vector with an integer.
 * * function v_f_mult is probably more useful.
*/
t_coords			v_i_mult(t_coords v, int i);

/**
 * * Multiplication of a vector with a float.
*/
t_coords			v_f_mult(t_coords v, float i);

/**
 * * Turns a color stored in a t_colors structure into an int 
 * * (for MiniLibX purposes)
*/
int					rgb2int(t_colors rgb);

/**
 * Turns a plane defined by a point and a normal vector (struct t_vectors)
 * to its equation form (struct t_plane_equation).

 * * --> ax + by + cz + d = 0 <--

 * @param norm_vector plane defined by a point and a normal vector.
*/
t_plane_equation	plane_vector2equation(t_vectors norm_vector);

/**
* *	Checks the correlation of the ray and the plane. Possible cases:
* @retval 0:	Line collides with the plane in front of the camera.
* @retval 1:	Line is parallel AND CONTAINED within the plane.
* @retval 2:	Line is parallel but doesn't collide with the plane at any point.
* @retval 3:	Line colllides with the plane but behind the camera.
*/
int					line_plane_correlation(t_vectors ray, \
						t_plane_equation equation);

/**
*	Calculating a constant needed to evaluate planes
*	More info in the function.
*/
float				get_the_t(t_vectors ray, t_plane_equation equation);

/*
*	Turns a vector into a unit vector (module = 1)
*/
t_coords			turn2unit(t_coords original);

/*
*	Getting how many times must the vector from the camera advance
*	to find the collision point (starting from the camera "eye").
	Tangent rays are also counted.
*/
float				get_ray_sphere_distance(t_vectors ray, t_item sphere);

/*
*	Returns the number of times the ray collides with a sphere (0-2).
*/
int					line_sphere_collisionsnum(t_vectors ray, t_item sphere);

/**
 * Returns the dot product of two vectors.
 @retval The value returned is a float.
*/
float				dot_product(t_coords va, t_coords vb);

/**
 * Returns the cosine of the angle between two vectors.
*/
float				get_cos(t_coords va, t_coords vb);

/**
 * Returns a vector formed by a direction and a point. This is just to
 * be able to pass two t_coords in one (struct t_vectors).
*/
t_vectors			dir_and_loc_2_vector(t_coords loc, t_coords dir);

/**
 * Returns a vector formed by a direction and a point. This is just to
 * be able to pass two t_coords in one (struct t_vectors).
 * The point is retrieved from the loc value in a t_item.
*/
t_vectors			dir_and_cam_2_vector(t_item cam, t_coords dir);

/**
 * Will return an inverted normal vector depending on which side does 
 * a ray collide with the plane.
*/
t_coords			rotate_plane_if_needed(t_vectors plane, t_vectors ray);

int					second_degree_equation(float a, float b, float c, \
float d[2]);

int					cylinder_lid(t_vectors ray, t_item cyli, t_coords *coords, \
int *rev_ori);

int					cylinder_wall(t_vectors ray, t_item cylinder, t_coords \
*coords);

#endif
