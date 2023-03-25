/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:39:00 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/25 04:13:13 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* error_handling.c*/
void				raise_error(char *err);
bool				user_input(int argc, char **argv);

/* create_data.c */
void				init_data(struct s_data *data, char *file_map);
bool				create_data(struct s_data *data, char *file_map);
void				init_data(struct s_data *data, char *file_map);

/* handle_lines.c */
char				*strip_newline(char *line);
bool				line_start_valid(char *str);
bool				line_map(struct s_data *data, char *str);
bool				line_is_empty(struct s_data *data, char *str);

/* free.c */
void				free_split(char **tokens);

/* handle_maps.c */
void				handle_maps(struct s_data *data);
char				**create_map_array(struct s_data *data);
void				fill_map_array(char **map_array, struct s_data *data);
int					**map_to_int_array(char **map, int height, int width);

/* check_map.c */
bool				check_first_line(char *line);
bool				check_last_line(char *line);
bool				check_line(char *prev_line, char *line, char *next_line);
bool				check_map(char **map, int height);

/* tmp.c */
bool				texture_valid(char *str);
bool				ft_str_is_numeric(char *str);
bool				color_valid(char *color);
unsigned char		*scrap_colors(char *color);
int					cnt_words(char *str, char delim);
int					cub_strcmp(char *s1, char *s2);
void				data_line_save(struct s_data *data, char *str);
void				cub_lst_add_back(struct s_map_list **lst,
						struct s_map_list *new);
struct s_map_list	*create_node(char *str);
struct s_map_list	*ft_lstlast(struct s_map_list *lst);
void				map_list_save(struct s_map_list **list,
						struct s_map_list *node);
void				update_w_h(struct s_data *data, char *line);

void				draw(void);
void				data_destroy(struct s_data *data);

#endif
