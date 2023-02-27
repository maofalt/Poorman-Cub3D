/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [0]main_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:30:35 by motero            #+#    #+#             */
/*   Updated: 2023/02/27 03:30:19 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	main_parsing(t_cub	*data, char *path)
{
	if (!valid_file(path))
		return (0);
	if (!parsing_text(data, path))
		return (0);
	printf("Parsing done\n");
	free_double_char(data->map);
	return (1);
}

/*
** Function that will allocated receive a double char array and allocate
** memory for each for the number of elements in the array passed 
** as a parameter
** the last element of the array will be set to NULL
** In case of error, the function will return 0
** otherwise it will return 1
*/

int	initialize_double_char(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		array[i] = ft_calloc(1, sizeof(char));
		if (!array[i])
			return (0);
		i++;
	}
	array[i] = NULL;
	return (1);
}

int	nbr_commas(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (str[i] == ',')
			nbr++;
		i++;
	}
	return (nbr);
}

void	print_double_char(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("str[%d] =  %s\n ", i, str[i]);
		i++;
	}
	printf("\n");
}

/*
** function that reprlace the free_double_char function and the ft_putstr_fd
** function in one line	
** It will free the double char array and print the error message that is passed
*/
void	print_error(char *message)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
