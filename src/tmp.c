#include "cub3d.h"

// void    map_list_save(struct s_data *data, char *line)
// {
    
// }

/*
char    **check_map(struct s_data *data, char **map)
{
    int i;
    int j;

    i = 0;
    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || map[i][j + 1] == ' ' || map[i][j - 1] == ' ')
                return (NULL);
            j++;
        }
        i++;
    }
    
    return (map);
}

///////////////////////////////////////////////////////////////////////////
bool	check_first_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	check_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	check_line(char *prev_line, char *line, char *next_line)
{
	int	j;

	j = 0;
	while (line[j] != '\0')
	{
		if (line[j] == '0')
		{
			if (line[j + 1] == ' ' || line[j - 1] == ' '
				|| prev_line[j] == ' ' || next_line[j] == ' ')
				return (false);
		}
		j++;
	}
	return (true);
}

void	init_vars(struct s_map_list **map, struct s_map_list **tmp,
					struct s_map_list **prev_line, struct s_map_list **next_line)
{
	*tmp = *map;
	if ((*tmp)->next)
		*next_line = (*tmp)->next;
	*prev_line = *map;
}

bool	check_map(struct s_map_list *map, int i)
{
	struct s_map_list	*tmp;
	struct s_map_list	*prev_line;
	struct s_map_list	*next_line;

	init_vars(&map, &tmp, &prev_line, &next_line);
	while (tmp != NULL)
	{
		if (i == 0 && check_first_line(tmp->line) == false)
			return (false);
		else if (tmp->next == NULL)
		{
			if (check_last_line(tmp->line) == false)
				return (false);
		}
		else if (!check_line(prev_line->line, tmp->line, next_line->line))
			return (false);
		prev_line = tmp;
		tmp = tmp->next;
		if (tmp)
			next_line = tmp->next;
		i++;
	}
	return (true);
}
///////////////////////////////////////////////////////////////////////////
*/


// void    map_list_save(struct s_map_list **list, struct s_map_list *node)
// {
// 	struct s_map_list	*last;

// 	if (list == NULL || node == NULL)
// 		return ;
// 	if (*list == NULL)
// 	{
// 		*list = node;
// 		return ;
// 	}
// 	last = ft_lstlast(*list);
// 	last->next = node;
// }

// struct s_map_list	*ft_lstlast(struct s_map_list *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst != NULL)
// 	{
// 		if (lst -> next == 0)
// 			return (lst);
// 		lst = lst -> next;
// 	}
// 	return (NULL);
// }