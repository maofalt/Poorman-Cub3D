/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [8]parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:03:30 by motero            #+#    #+#             */
/*   Updated: 2023/02/23 18:15:23 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"


/**
**while reading the file, we create a node for each line
** and add the line as a void *content to the node
** we then add the node to the list.
** we then  get the size of the list with ft_lstsize
** and we create a char ** with the size of the list
** we then add the content of each node to the char **
** and free the node
** we then return 1 
 */
int	parse_map(char	*line, char ***map, int fd)
{
	t_list	*list;
	t_list	*tmp;
	int		i;

	list = NULL;
	i = 0;
	while (line)
	{
		ft_lstadd_back(&list, ft_lstnew(line));
		line = get_next_line(fd);
	}
	*map = malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	while (list)
	{
		(*map)[i] = list->content;
		tmp = list;
		list = list->next;
		free(tmp);
		i++;
	}
	(*map)[i] = NULL;
	return (1);
}

/* print a char **
*/

void	print_map(char **map)
{
	int	i;

	printf("****map\n");
	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}
