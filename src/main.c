/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:37:50 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/25 06:25:07 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	draw(void)
{

}

int
	main(int argc, char **argv)
{
	struct s_data	data;

	if (user_input(argc, argv) == true)
	{
		if (create_data(&data, argv[1]))
			draw();
		data_destroy(&data);
	}
}
