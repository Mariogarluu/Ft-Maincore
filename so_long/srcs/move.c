#include "../includes/so_long.h"

int can_move(t_game *game, int x, int y, char type)
{
    // Comprobar límites del mapa
    if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
        return (0);
    
    // Comprobar si es un muro
    if (game->map[y][x] == '1')
        return (0);
    
    // Para enemigos, no queremos que se muevan al jugador o a la salida
    if (type == 'C' || type == 'S')
    {
        if (game->map[y][x] == 'E')
            return (0);
        
        // Comprobar colisión con otros enemigos
        for (int i = 0; i < game->num_enemies; i++)
        {
            if (game->enemies[i].pos.x == x && game->enemies[i].pos.y == y)
                return (0);
        }
    }
    
    return (1);
}

void move_player(t_game *game, int dir_x, int dir_y)
{
    int new_x, new_y;

    new_x = game->player.pos.x + dir_x;
    new_y = game->player.pos.y + dir_y;

    if (can_move(game, new_x, new_y, 'P'))
    {
        // Actualizar la posición en el mapa
        game->map[game->player.pos.y][game->player.pos.x] = '0';
        
        // Actualizar la posición del jugador
        game->player.pos.x = new_x;
        game->player.pos.y = new_y;
        
        // Incrementar contador de movimientos
        game->player.moves++;
        
        // Comprobar si hemos recogido un coleccionable
        if (game->map[new_y][new_x] == 'C')
        {
            game->player.collectibles++;
            game->map[new_y][new_x] = '0';
        }
        
        // Comprobar si hemos llegado a la salida
        if (game->map[new_y][new_x] == 'E')
        {
            if (game->player.collectibles == game->total_collectibles)
                game_over(game, 1); // Victoria
        }
        
        // Marcar la nueva posición
        if (game->map[new_y][new_x] != 'E')
            game->map[new_y][new_x] = 'P';
        
        // Renderizar el juego actualizado
        render_game(game);
        display_moves(game);
    }
}

void move_enemies(t_game *game)
{
    int i, dir, new_x, new_y;
    static int counter = 0;

    // Mover enemigos cada cierto número de frames
    counter++;
    if (counter < 20) // Ajustar velocidad aquí
        return;
    counter = 0;

    for (i = 0; i < game->num_enemies; i++)
    {
        // Dirección aleatoria (0-3)
        dir = rand() % 4;
        
        new_x = game->enemies[i].pos.x;
        new_y = game->enemies[i].pos.y;
        
        // Determinar la dirección
        if (dir == 0) new_y--; // Arriba
        else if (dir == 1) new_y++; // Abajo
        else if (dir == 2) new_x--; // Izquierda
        else if (dir == 3) new_x++; // Derecha
        
        // Intentar mover al enemigo
        if (can_move(game, new_x, new_y, game->enemies[i].type))
        {
            // Actualizar la posición en el mapa
            game->map[game->enemies[i].pos.y][game->enemies[i].pos.x] = '0';
            
            // Actualizar la posición del enemigo
            game->enemies[i].pos.x = new_x;
            game->enemies[i].pos.y = new_y;
            
            // Marcar la nueva posición
            game->map[new_y][new_x] = game->enemies[i].type;
        }
    }
}

int check_enemy_collision(t_game *game)
{
    int i;

    for (i = 0; i < game->num_enemies; i++)
    {
        if (game->enemies[i].pos.x == game->player.pos.x && 
            game->enemies[i].pos.y == game->player.pos.y)
            return (1);
    }
    return (0);
}