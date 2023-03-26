/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:27:39 by slakner           #+#    #+#             */
/*   Updated: 2023/03/26 16:31:35 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

double		dda_walldist(t_img_data *data, t_column *col);
t_dpoint	dist_to_grid_line(t_img_data *data, t_ipoint map_sq, t_column *col);
double		dist_to_next_wall(t_img_data *data, t_ipoint map_sq, t_column *col);
t_ipoint	stepdir(t_dpoint ray_dir);
double		wall_found(t_column *col, int walltype);

#endif