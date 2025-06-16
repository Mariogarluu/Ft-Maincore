#include "../includes/so_long.h"

void put_image(t_game *game, void *img, int x, int y)
{
    mlx_put_image_to_window(game->mlx, game->win, img, 
        x * TILE_SIZE, y * TILE_SIZE);
}

void render_map(t_game *game)
{
    int i, j;

    for (i = 0; i < game->map_height; i++)
    {
        for (j = 0; j < game->map_width; j++)
        {
            // Renderizar el suelo primero
            put_image(game, game->img_floor, j, i);

            // Renderizar los elementos
            if (game->map[i][j] == '1')
                put_image(game, game->img_wall, j, i);
            else if (game->map[i][j] == 'C')
                put_image(game, game->img_collectible, j, i);
            else if (game->map[i][j] == 'E')
                put_image(game, game->img_exit, j, i);
        }
    }
}

void render_player(t_game *game)
{
    put_image(game, game->img_player, game->player.pos.x, game->player.pos.y);
}

void render_enemies(t_game *game)
{
    int i;

    for (i = 0; i < game->num_enemies; i++)
    {
        if (game->enemies[i].type == 'C')
            put_image(game, game->img_enemy_c, game->enemies[i].pos.x, game->enemies[i].pos.y);
        else if (game->enemies[i].type == 'S')
            put_image(game, game->img_enemy_s, game->enemies[i].pos.x, game->enemies[i].pos.y);
    }
}

void render_game(t_game *game)
{
    render_map(game);
    render_player(game);
    render_enemies(game);

    // Mostrar mensajes de fin de juego
    if (game->game_over)
    {
        mlx_string_put(game->mlx, game->win, 
            (game->map_width * TILE_SIZE) / 2 - 50,
            (game->map_height * TILE_SIZE) / 2,
            0xFF0000, "¡GAME OVER!");
    }
    else if (game->win_flag)
    {
        mlx_string_put(game->mlx, game->win, 
            (game->map_width * TILE_SIZE) / 2 - 50,
            (game->map_height * TILE_SIZE) / 2,
            0x00FF00, "¡VICTORIA!");
    }
}