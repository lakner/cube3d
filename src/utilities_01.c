/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 06:29:04 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/25 06:29:31 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	u_lst_add_back(struct s_map_list **lst, struct s_map_list *new)
{
	struct s_map_list	*tmp;

	if (new == NULL)
		return ;
	if (*lst)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}

struct s_map_list
	*u_create_node(char *str)
{
	struct s_map_list	*node;

	node = malloc(sizeof(struct s_map_list));
	node->line = ft_strdup(str);
	node->next = NULL;
	return (node);
}
