#include "map.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char	**map;
	int		i;

	if (argc != 2)
	{
		printf("argc Error\n");
		return (1);
	}
	map = load_map(argv[1]);
	if (!map)
	{
		printf("load_map Error\n");
		return (1);
	}
	if (!check_valid_map(map))
	{
		printf("nonvalid map Error\n");
		return (1);
	}
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	free_map(map);
	return (0);
}
