/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:04:26 by emadriga          #+#    #+#             */
/*   Updated: 2022/04/27 22:48:03 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "dtos.h"

/**
 * * Init mlx to render image following
 * https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
 * (writing-pixels-to-a-image)
 * @param matrix_colors	matrix of colors to render
*/
void	render_image_on_mlx(int	**matrix_colors);

#endif
