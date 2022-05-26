/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:35:34 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/30 13:14:07 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	doing_calculations(char **argv)
{
	t_item		*items;
	t_coords	**v_matrix;
	int			**c_matrix;
	t_item		cam;

	items = NULL;
	get_items(&items, argv[1]);
	if (items != NULL)
	{
		cam = get_item_by_type(&items, CAMERA);
		v_matrix = set_cam_vectors(set_corners(cam));
		c_matrix = set_color_matrix(items, v_matrix, cam);
		free_array_coords(&v_matrix);
		lst_rt_free(&items);
		render_image_on_mlx(c_matrix);
		free_array_colors(&c_matrix);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	doing_calculations(argv);
}
