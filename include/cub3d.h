/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:35:29 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/11 21:16:59 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/include/libft.h"
#include <stdbool.h>

// macros for error
#define WRONG_INPUT "WRONG_INPUT\n"
#define MAP_ERROR "MAP_ERROR\n"
#define COLOR_INVALID "COLOR_INVALID\n"
#define TEXTURE_INVALID "TEXTURE INVALID\n"
#define TOO_MANY_ARGS_FOR_PATH "TOO_MANY_ARGS_FOR_PATH\n"
#define TOO_MANY_ARGS "TOO_MANY_ARGS\n"
#define MAP_NOT_FOUND "MAP_NOT_FOUND\n"
#define NOT_DOT_CUB "NOT_DOT_CUB\n"
#define INVALID_MAP "INVALID MAP\n"

struct s_map_list
{
    char *line;
    struct s_map_list *next;
};


struct s_data
{
    int     width;
    int     height;
    int     map_fd;
    int     NO_fd;
    int     SO_fd;
    int     WE_fd;
    int     EA_fd;
    unsigned char    *F_colors;
    unsigned char    *C_colors;
    long long   F_color; // to check
    long long   C_color; // to check

    bool    map_found;
    
    struct  s_map_list *map_list;
    char    **map;
    int     **map_int;    
};


#endif
