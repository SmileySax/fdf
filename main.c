#include "fdf.h"

int	main(int argc, char *argv)
{
	t_map	*map;

	map = ft_parce(argv[1]);

	ft_free_int_tab(map->points);
	free(map);
}
