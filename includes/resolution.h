/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:33:12 by emadriga          #+#    #+#             */
/*   Updated: 2022/04/27 22:46:47 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLUTION_H
# define RESOLUTION_H

# define RESOLUTION 2

// 									WVGA		16/9
# if RESOLUTION==0
#  define HORIZ_RESOLUTION 850
#  define VERT_RESOLUTION 480

//									HD			16/9
# elif RESOLUTION==1
#  define HORIZ_RESOLUTION 1280
#  define VERT_RESOLUTION 720

//									FULL_HD		16/9
# elif RESOLUTION==2
#  define HORIZ_RESOLUTION 1920
#  define VERT_RESOLUTION 1080

//									2K			17/9
# elif RESOLUTION==3
#  define HORIZ_RESOLUTION 2048
#  define VERT_RESOLUTION 1080

//									QHD			16/9
# elif RESOLUTION==4
#  define HORIZ_RESOLUTION 2560
#  define VERT_RESOLUTION 1440

//									4K UHDV		16/9
# elif RESOLUTION==5
#  define HORIZ_RESOLUTION 3840
#  define VERT_RESOLUTION 2160

//									4K CINEMA	17/9
# elif RESOLUTION==6
#  define HORIZ_RESOLUTION 4096
#  define VERT_RESOLUTION 2160
# endif

#endif
