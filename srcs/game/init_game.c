/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:56:07 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/02 18:33:26 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_handler(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	close_window(game);
	exit(0);
}
void	close_window(t_game *game)
{
	if (game->window->mlx)
	{
		if (game->window->mlx_win)
			mlx_terminate(game->window->mlx);
		free(game->window->mlx);
	}
}
void	convert_textures(t_game *game)
{
	game->textures->wall_img = mlx_texture_to_image(game->window->mlx,
			game->textures->wall_img);
	game->textures->background_img = mlx_texture_to_image(game->window->mlx,
			game->textures->background_img);
	game->textures->player_img = mlx_texture_to_image(game->window->mlx,
			game->textures->player_img);
	game->textures->exit_img = mlx_texture_to_image(game->window->mlx,
			game->textures->exit_img);
	if (!game->textures->wall_img || !game->textures->background_img
		|| !game->textures->player_img || !game->textures->player_img
		|| !game->textures->exit_img)
		ft_error("Error: Could not convert all textures", 1);
}

void	load_textures(t_game *game)
{
	// Cargar textura de pared
	printf("Cargando textura: %s\n", WALL_TEXTURE);
	if (access(WALL_TEXTURE, F_OK) != 0)
	{
		printf("Error: La textura %s no existe o no es accesible.\n",
			WALL_TEXTURE);
	}
	else
	{
		game->textures->wall_img = mlx_load_xpm42(WALL_TEXTURE);
		if (!game->textures->wall_img)
			printf("Error al cargar textura de pared: %s\n",
				mlx_strerror(mlx_errno));
	}
	// Cargar textura de fondo
	printf("Cargando textura: %s\n", FLOOR_TEXTURE);
	if (access(FLOOR_TEXTURE, F_OK) != 0)
	{
		printf("Error: La textura %s no existe o no es accesible.\n",
			FLOOR_TEXTURE);
	}
	else
	{
		game->textures->background_img = mlx_load_xpm42(FLOOR_TEXTURE);
		if (!game->textures->background_img)
			printf("Error al cargar textura de fondo: %s\n",
				mlx_strerror(mlx_errno));
	}
	// Cargar textura de jugador
	printf("Cargando textura: %s\n", PLAYER_TEXTURE);
	if (access(PLAYER_TEXTURE, F_OK) != 0)
	{
		printf("Error: La textura %s no existe o no es accesible.\n",
			PLAYER_TEXTURE);
	}
	else
	{
		game->textures->player_img = mlx_load_xpm42(PLAYER_TEXTURE);
		if (!game->textures->player_img)
			printf("Error al cargar textura de jugador: %s\n",
				mlx_strerror(mlx_errno));
	}
	// Cargar textura de coleccionable
	printf("Cargando textura: %s\n", COLLECTIBLE_TEXTURE);
	if (access(COLLECTIBLE_TEXTURE, F_OK) != 0)
	{
		printf("Error: La textura %s no existe o no es accesible.\n",
			COLLECTIBLE_TEXTURE);
	}
	else
	{
		game->textures->caracter_img = mlx_load_xpm42(COLLECTIBLE_TEXTURE);
		if (!game->textures->caracter_img)
			printf("Error al cargar textura de coleccionable: %s\n",
				mlx_strerror(mlx_errno));
	}
	// Cargar textura de salida
	printf("Cargando textura: %s\n", EXIT_TEXTURE);
	if (access(EXIT_TEXTURE, F_OK) != 0)
	{
		printf("Error: La textura %s no existe o no es accesible.\n",
			EXIT_TEXTURE);
	}
	else
	{
		game->textures->exit_img = mlx_load_xpm42(EXIT_TEXTURE);
		if (!game->textures->exit_img)
			printf("Error al cargar textura de salida: %s\n",
				mlx_strerror(mlx_errno));
	}
	// Validación final
	if (!game->textures->wall_img || !game->textures->background_img
		|| !game->textures->player_img || !game->textures->exit_img
		|| !game->textures->caracter_img)
	{
		ft_error("Error: Una o más texturas no se pudieron cargar.", 1);
	}
}

// funcion para los pixeles mlx_texture_to_image

void	init_game(t_game *game)
{
	int	width;
	int	height;

	if (!game || !game->map || !game->map->matrix)
		ft_error(ERROR_MAP, 1);
	width = game->map->cols * TILE_SIZE;
	height = game->map->rows * TILE_SIZE;
	game->window = ft_calloc(1, sizeof(t_window));
	if (!game->window)
		ft_error(ERROR_WINDOW, 1);
	game->window->mlx = mlx_init(width, height, "SO_LONG", true);
	if (!game->window->mlx)
		ft_error("Error inicializando la ventana", 1);
	else
		printf("MLX initialized successfully.\n");
	game->textures = ft_calloc(1, sizeof(t_textures));
	if (!game->textures)
		ft_error("Error al asignar memoria para las texturas", 1);
	load_textures(game);
	convert_textures(game);
	render_map(game);
	mlx_close_hook(game->window->mlx, close_handler, game);
	// mlx_key_hook(game->window->mlx, key_handler, game);
	mlx_loop(game->window->mlx);
}
