/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:35:29 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/09 23:25:05 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/include/libft.h"
#include <stdbool.h>

// macros for error
#define WRONG_INPUT "YOUR SHIT IS BAD\n"
#define MAP_ERROR "1YOUR SHIT IS BAD\n"
#define COLOR_INVALID "2YOUR SHIT IS BAD\n"
#define TEXTURE_INVALID "3YOUR SHIT IS BAD\n"
#define TOO_MANY_ARGS_FOR_PATH "TOO_MANY_ARGS_FOR_PATH\n"
struct s_data
{
    int     map_fd;
    int     NO_fd;
    int     SO_fd;
    int     WE_fd;
    int     EA_fd;
    char    *F_colors;
    char    *C_colors;
    long long   F_color; // to check
    long long   C_color; // to check

    bool    map_found;
    
    char    **map;    
};


#endif
