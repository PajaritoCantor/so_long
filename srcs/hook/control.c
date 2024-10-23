#include "so_long.h"

void	move_player(t_vars *vars, int x_offset, int y_offset)
{
	int new_x;
	int new_y;

	new_x = vars->player_x + x_offset;
	new_y = vars->player_y + y_offset;
	if (vars->game->matrix[new_y][new_x] != '1')
	{
		vars->player_x = new_x;
		vars->player_y = new_y;
		render_map(vars, vars->game);
	}
	ft_printfd(2, "succesfull", 12);
	exit(1);
}