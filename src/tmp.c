#include "cub3d.h"



void free_split(char **tokens)
{
    char **tmp = tokens;
    
    while (*tmp)
        free(*tmp++);
    free(tokens);
}






bool    texture_valid(char *str)
{
    if (str != NULL && access(str, F_OK) != -1)
        return (true);
    return (false);
}

bool    ft_str_is_numeric(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]) == false)
			return (false);
	return (true);
}

bool    color_valid(char *color)
{
    char **rgb;
    int i;

    i = 0;
    printf("The color is : %s\n", color);
    rgb = ft_split(color, ',');
    while (i < 3)
    {
        printf("The rgb is : %s\n", rgb[i]);
        if (rgb[i] == NULL || ft_str_is_numeric(rgb[i]) == false)
        {
        	free_split(rgb);
        	return (false);
        }
        else if (ft_atoi(rgb[i]) < 0 && ft_atoi(rgb[i]) > 255)
        {
        	free_split(rgb);
            return (false);
        }
        i++;
    }
    free_split(rgb);
    return (true);
}

unsigned char    *scrap_colors(char *color)
{
    char            **rgb;
    unsigned char   *colors;

    rgb = ft_split(color, ',');
    colors = malloc(sizeof(char) * 4);
    // printf("The first color is : %d\n", ft_atoi(rgb[0]));
    colors[0] = ft_atoi(rgb[0]);
    colors[1] = ft_atoi(rgb[1]);
    colors[2] = ft_atoi(rgb[2]);
    colors[3] = '\0';
    return (colors);
}

int
	cnt_words(char *str, char delim)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if ((str[i] != delim && str[i + 1] == delim)
			|| (str[i] != delim && str[i + 1] == 0))
			j++;
		i++;
	}
	return (j);
}

int
	cub_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (1);
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (0);
	else if (s1[i] < s2[i])
		return (-1);
	else
		return (1);
}



void
	cub_lst_add_back(struct s_map_list **lst, struct s_map_list *new)
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

struct s_map_list *create_node(char *str)
{
    struct s_map_list *node;

    node = malloc(sizeof(struct s_map_list));
    node->line = ft_strdup(str);
    node->next = NULL;
    return (node);
}

struct s_map_list	*ft_lstlast(struct s_map_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (lst -> next == 0)
			return (lst);
		lst = lst -> next;
	}
	return (NULL);
}

void    map_list_save(struct s_map_list **list, struct s_map_list *node)
{
	struct s_map_list	*last;

	if (list == NULL || node == NULL)
		return ;
	if (*list == NULL)
	{
		*list = node;
		return ;
	}
	last = ft_lstlast(*list);
	last->next = node;
}

// void    map_list_save(struct s_data *data, char *line)
// {
    
// }

void    update_w_h(struct s_data *data, char *line)
{
    data->height++;
    if (ft_strlen(line) > (size_t)data->width)
        data->width = ft_strlen(line);
}

char** create_map_array(struct s_data* data) 
{
    char** map_array = (char**) malloc(data->height * sizeof(char*));
    int i = 0;
    while (i < data->height) {
        map_array[i] = (char*) malloc(data->width * sizeof(char));
        ft_memset(map_array[i], ' ', data->width); // fill array with empty spaces
        i++;
    }

    struct s_map_list* current = data->map_list;
    int row = 0;
    while (current != NULL && row < data->height)
    {
        int col = 0;
        int line_len = ft_strlen(current->line);
        while (col < line_len && col < data->width) {
            map_array[row][col] = current->line[col];
            col++;
        }
        current = current->next;
        row++;
    }

    return (map_array);
}
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
bool	first_line_checker(char *line)
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

bool	last_line_checker(char *line)
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

bool	line_checker(char *prev_line, char *line, char *next_line)
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

bool	map_check(struct s_map_list *map, int i)
{
	struct s_map_list	*tmp;
	struct s_map_list	*prev_line;
	struct s_map_list	*next_line;

	init_vars(&map, &tmp, &prev_line, &next_line);
	while (tmp != NULL)
	{
		if (i == 0 && first_line_checker(tmp->line) == false)
			return (false);
		else if (tmp->next == NULL)
		{
			if (last_line_checker(tmp->line) == false)
				return (false);
		}
		else if (!line_checker(prev_line->line, tmp->line, next_line->line))
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


bool
	first_line_checker(char *line)
{
	int i;

	i = 0;
    while (line[i] != '\0')
    {
        if (line[i] != '1' && line[i] != ' ')
            return false;
        i++;
    }
    return (true);
}

bool
	last_line_checker(char *line)
{
	int i;

	i = 0;
    while (line[i] != '\0')
    {
        if (line[i] != '1' && line[i] != ' ')
            return false;
        i++;
    }
    return (true);
}

bool
	line_checker(char *prev_line, char *line, char *next_line)
{
	int j;

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

bool map_check(char **map, int height) {
    for (int i = 0; i < height; i++) {
        if (i == 0 && !first_line_checker(map[i]))
            return false;
        else if (i == height - 1 && !last_line_checker(map[i]))
            return false;
        else if (i > 0 && i < height - 1 && !line_checker(map[i - 1], map[i], map[i + 1]))
            return false;
    }
    return true;
}

int **map_to_int_array(char **map, int height, int width) {
    int **int_map = (int **) malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        int_map[i] = (int *) malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            if (map[i][j] == ' ')
                int_map[i][j] = 2;
            else if (map[i][j] == 'N')
                int_map[i][j] = 3;
            else
                int_map[i][j] = map[i][j] - '0';
        }
    }
    return int_map;
}

void
	handle_maps(struct s_data *data)
{
	data->map = create_map_array(data);
	if (map_check(data->map, data->height) == false)
		raise_error(INVALID_MAP);
	data->map_int = map_to_int_array(data->map, data->height, data->width);
	print_s_data(data);
}




void    draw()
{

}

void    data_destroy(struct s_data *data)
{
    close(data->map_fd);
    // FREE THE COLORS
    // try to remove everthing alloced (map and the textures strings if allocated)
}


