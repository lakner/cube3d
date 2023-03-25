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

char				*newline_strip(char *line);
void				raise_error(char *err);
bool				user_input(int argc, char **argv);
void				free_split(char **tokens);
bool				line_start_valid(char *str);
bool				line_map(struct s_data *data, char *str);
bool				line_is_empty(struct s_data *data, char *str);
bool				texture_valid(char *str);
bool				ft_str_is_numeric(char *str);
bool				color_valid(char *color);
unsigned char		*scrap_colors(char *color);
int					cnt_words(char *str, char delim);
int					cub_strcmp(char *s1, char *s2);
void				data_line_save(struct s_data *data, char *str);
void				ft_lstadd_back_ms(struct s_map_list **lst, struct s_map_list *new);
struct s_map_list	*create_node(char *str);
struct s_map_list	*ft_lstlast(struct s_map_list *lst);
void				map_list_save(struct s_map_list **list, struct s_map_list *node);
void				update_w_h(struct s_data *data, char *line);
char				**create_map_array(struct s_data *data);
bool				first_line_checker(char *line);
bool				last_line_checker(char *line);
bool				line_checker(char *prev_line, char *line, char *next_line);
bool				map_check(char **map, int height);
int					**map_to_int_array(char **map, int height, int width);
void				handle_maps(struct s_data *data);
void				init_data(struct s_data *data, char *file_map);
bool				data_create(struct s_data *data, char *file_map);
void				draw(void);
void				data_destroy(struct s_data *data);

#endif
