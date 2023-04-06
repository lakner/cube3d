/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephanie.lakner <stephanie.lakner@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:39:00 by dcharala          #+#    #+#             */
/*   Updated: 2023/04/06 14:34:40 by stephanie.l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "cub3d.h"

/* error_handling.c*/
void				raise_error(char *err);
bool				user_input(int argc, char **argv);

/* create_data.c */
void				init_data(struct s_data *data, char *file_map);
bool				create_data(struct s_data *data, char *file_map);
void				init_data(struct s_data *data, char *file_map);
void				update_w_h(struct s_data *data, char *line);

/* handle_lines.c */
char				*strip_newline(char *line);
bool				line_start_valid(char *str);
void				data_line_save(struct s_data *data, char *str);
bool				line_map(struct s_data *data, char *str);
bool				line_is_empty(struct s_data *data, char *str);

/* free.c */
void				free_split(char **tokens);
void				data_destroy(struct s_data *data);

/* free_img_data.c */
void				free_img_data(t_img_data *img);

/* handle_maps.c */
void				handle_maps(struct s_data *data);
char				**create_map_array(struct s_data *data);
void				fill_map_array(char **map_array, struct s_data *data);
int					**map_to_int_array(struct s_data *data);
void				set_player_position(struct s_data *data, int **int_map,
						int i, int j);

/* check_map.c */
bool				check_first_line(char *line, int width);
bool				check_last_line(char *line, int width);
bool				check_line(char *prev_line, char *line, char *next_line,
						int width);
bool				check_map(char **map, int height, int width);

/* handle_textures.c */
bool				texture_valid(char *str);

/* handle_colors.c */
bool				color_valid(char *color);
unsigned char		*scrap_colors(char *color);
int					rgb_to_hex(unsigned char *colors);

/* utilities_00.c */
bool				u_str_is_numeric(char *str);
int					u_count_words(char *str, char delim);
int					u_strcmp(char *s1, char *s2);

/* utilities_01.c */
void				u_lst_add_back(struct s_map_list **lst,
						struct s_map_list *new);
struct s_map_list	*u_create_node(char *str);

#endif
