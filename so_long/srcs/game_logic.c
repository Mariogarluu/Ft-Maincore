#include "../includes/so_long.h"

int check_collectible(t_game *game)
{
    if (game->map[game->player.pos.y][game->player.pos.x] == 'C')
    {
        game->player.collectibles++;
        game->map[game->player.pos.y][game->player.pos.x] = '0';
        return (1);
    }
    return (0);
}

int check_exit(t_game *game)
{
    if (game->map[game->player.pos.y][game->player.pos.x] == 'E')
    {
        if (game->player.collectibles == game->total_collectibles)
            return (1);
    }
    return (0);
}

void game_over(t_game *game, int win)
{
    if (win)
    {
        game->win_flag = 1;
        ft_printf("¡Felicidades! Has encontrado el tesoro en %d movimientos.\n", 
            game->player.moves);
        ft_printf("Sprites creados por Foozle\n");
    }
    else
    {
        game->game_over = 1;
        ft_printf("¡Game Over! Un cazador te ha pillado.\n");
        ft_printf("Sprites creados por Foozle\n");
    }
    render_game(game);
}

int update_game_state(t_game *game)
{
    // Comprobar colisión con enemigos
    if (check_enemy_collision(game))
    {
        game_over(game, 0);
        return (0);
    }
    
    // Comprobar coleccionables
    check_collectible(game);
    
    // Comprobar salida
    if (check_exit(game))
    {
        game_over(game, 1);
        return (0);
    }
    
    return (1);
}