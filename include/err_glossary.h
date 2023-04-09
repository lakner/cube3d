/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_glossary.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 02:48:55 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/25 03:42:06 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_GLOSSARY_H
# define ERR_GLOSSARY_H

# define MAP_ERROR "An error occured while trying to read the map.\n"
# define COLOR_INVALID "Invalid color.\n"
# define TEXTURE_INVALID "Invalid texture.\n"
# define TEXTURE_PERMISSION "No read permission for texture file.\n"
# define TOO_MANY_ARGS_PATH "Too many arguments. Expenting path to texture.\n"
# define TOO_MANY_ARGS "Too many arguments.\nTry: ./cub3D maps/test.cub\n"
# define TOO_FEW_ARGS "Too few arguments.\nTry: ./cub3D maps/test.cub\n"
# define MAP_NOT_FOUND "Map not found.\n"
# define NOT_DOT_CUB "Invalid map file extension.\nAccepting only .cub files.\n"
# define INVALID_MAP "Invalid map.\n"
# define PNG_ONLY "Only PNG files are supported for textures.\n"
# define SYNTAX_ERROR "Syntax Error.\n"

#endif
