/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:10:31 by emadriga          #+#    #+#             */
/*   Updated: 2022/04/30 13:04:53 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define KEY_ESC 53

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
}	t_data;

typedef struct s_vars{
	void	*mlx;
	void	*win;
	t_data	img;
}	t_vars;

/**
 * * Close mlx windows
 * @param vars	mlx vars	 
*/
static	int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

/**
 * * Render a pixel of the image form a color given
 * @param img	image to render
 * @param x		x coordinate
 * @param y		y coordinate
 * @param color	color to draw pixel
*/
static void	render_pixel(t_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = (y * img->line_length + x * (img->bits_per_pixel / 8)) + img->addr;
	*(unsigned int *)pixel = color;
}

/**
 * * Render every element of matrix into image pixels
 * @param matrix_colors		matrix of colors to render
 * @param img				image to render
*/
static void	render_pixels(t_data	*img, int **matrix_colors)
{
	int			x;
	int			y;

	y = 0;
	while (y < VERT_RESOLUTION)
	{
		x = 0;
		while (x < HORIZ_RESOLUTION)
		{
			render_pixel(img, x, y, matrix_colors[x][y]);
			x++;
		}
		y++;
	}
	free_array_colors(&matrix_colors);
}

/**
 * * Hook to handle heys
 * @param keycode	key pressed 
 * @param vars		mlx vars	 
*/
static int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		close_window(vars);
	return (0);
}

/**
 * * Init mlx to render image following 
 * https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
 * (writing-pixels-to-a-image)
 * @param matrix_colors	matrix of colors to render 
*/
void	render_image_on_mlx(int	**matrix_colors)
{
	t_vars	v;
	int		endian;

	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, HORIZ_RESOLUTION, VERT_RESOLUTION, MLX_TITLE);
	v.img.img = mlx_new_image(v.mlx, HORIZ_RESOLUTION, VERT_RESOLUTION);
	v.img.addr = mlx_get_data_addr(v.img.img, &v.img.bits_per_pixel, \
	&v.img.line_length, &endian);
	render_pixels(&v.img, matrix_colors);
	mlx_put_image_to_window(v.mlx, v.win, v.img.img, 0, 0);
	mlx_key_hook(v.win, key_hook, &v);
	mlx_hook(v.win, 17, 1L << 17, close_window, &v);
	mlx_loop(v.mlx);
}
