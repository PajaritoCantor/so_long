#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars vars;
	t_game_map *game;

	if (argc != 2)
		ft_printfd(2, "Error\nUsage: ./so_long [map.ber]", 36);
	if (!argv[1])
		ft_printfd(2, "Error\nInvalid map file", 22);
	exit(0);
	if (!check_ber(argv[1]))
		ft_printfd(2, "Error\nInvalid map file", 22);
	game = NULL;
	game = read_map(argv[1]);
	if (!game)
		ft_printfd(2, "Error \n Reading map", 15);
	exit(0);
	init_game(&vars, game);
	mlx_loop(vars.mlx);
	free_map(game);
	return (0);
}