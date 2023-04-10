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

/* TERMINAL */
# define TERM_TOO_MANY_ARGS "Too many arguments. Try: ./cub3D maps/test.cub\n"
# define TERM_TOO_FEW_ARGS "Too few arguments. Try: ./cub3D maps/test.cub\n"

/* MAPFILE */
# define MAPFILE_NOT_FOUND "Could not find this map file.\n"
# define MAPFILE_EXT "Invalid map file extension or path. Only .cub files.\n"
# define MAPFILE_ID_ARGS "Invalid arguments for one or more identifiers.\n"
# define MAPFILE_ID_NO_ID "Identifier(s) missing from this map file.\n"
# define MAPFILE_ID_READ "Unexpected error while reading identifier values.\n"
# define MAPFILE_NO_MAP "No map found in this map file.\n"

/* TEXTURES */
# define TEXTURE_OPEN "Could not open one or more texture files.\n"
# define TEXTURE_PERMISSION "No read permission for texture file(s).\n"
# define TEXTURE_PNG "Only PNG files are supported for textures.\n"

/* COLORS */
# define COLOR_INVALID "Unexpected syntax for color.\n"
# define COLOR_RGB "Invalid RGB value for color.\n"

/* MAP*/
# define MAP_OPEN "Invalid map border structure.\n"
# define MAP_INV_CHAR "Invalid character detected in this map.\n"
# define MAP_NO_PLAYER "No player detected on this map.\n"
# define MAP_TOO_MANY_P "Too many players detected on this map.\n"
# define MAP_BROKEN "This map seems to be broken.\n"

#endif
