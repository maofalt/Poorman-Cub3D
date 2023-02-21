#include "../includes/parsing.h"


bool	check_extension(char *file)
{
	if (ft_strncmp(file + (ft_strlen(file) - 4), ".cub", ft_strlen(file)))
		return (false);
	return (true);
}