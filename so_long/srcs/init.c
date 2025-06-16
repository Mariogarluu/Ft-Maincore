#include "../includes/so_long.h"

void init_game(t_game *game)
{
    game->mlx = NULL;
    game->win = NULL;
    game->map = NULL;
    game->map_width = 0;
    game->map_height = 0;
    game->total_collectibles = 0;
    game->player.moves = 0;
    game->player.collectibles = 0;
    game->enemies = NULL;
    game->num_enemies = 0;
    game->img_player = NULL;
    game->img_wall = NULL;
    game->img_collectible = NULL;
    game->img_exit = NULL;
    game->img_enemy_c = NULL;
    game->img_enemy_s = NULL;
    game->img_floor = NULL;
    game->exit_x = -1;
    game->exit_y = -1;
    game->game_over = 0;
    game->win_flag = 0;
}

void load_images(t_game *game)
{
    int width, height;

    game->img_player = mlx_xpm_file_to_image(game->mlx, 
        "assets/player.xpm", &width, &height);
    game->img_wall = mlx_xpm_file_to_image(game->mlx, 
        "assets/wall.xpm", &width, &height);
    game->img_collectible = mlx_xpm_file_to_image(game->mlx, 
        "assets/collectible.xpm", &width, &height);
    game->img_exit = mlx_xpm_file_to_image(game->mlx, 
        "assets/exit.xpm", &width, &height);
    game->img_enemy_c = mlx_xpm_file_to_image(game->mlx, 
        "assets/enemy_c.xpm", &width, &height);
    game->img_enemy_s = mlx_xpm_file_to_image(game->mlx, 
        "assets/enemy_s.xpm", &width, &height);
    game->img_floor = mlx_xpm_file_to_image(game->mlx, 
        "assets/floor.xpm", &width, &height);

    if (!game->img_player || !game->img_wall || !game->img_collectible ||
        !game->img_exit || !game->img_enemy_c || !game->img_enemy_s || 
        !game->img_floor)
    {
        printf("Error\nNo se pudieron cargar las imágenes\n");
        close_game(game);
    }
}

void init_player(t_game *game)
{
    int i, j;

    for (i = 0; i < game->map_height; i++)
    {
        for (j = 0; j < game->map_width; j++)
        {
            if (game->map[i][j] == 'P')
            {
                game->player.pos.x = j;
                game->player.pos.y = i;
                return;
            }
        }
    }
}

int count_enemies(t_game *game)
{
    int i, j, count;

    count = 0;
    for (i = 0; i < game->map_height; i++)
    {
        for (j = 0; j < game->map_width; j++)
        {
            if (game->map[i][j] == 'C' || game->map[i][j] == 'S')
                count++;
        }
    }
    return (count);
}

void init_enemies(t_game *game)
{
    int i, j, k;

    game->num_enemies = count_enemies(game);
    game->enemies = (t_enemy *)malloc(sizeof(t_enemy) * game->num_enemies);
    if (!game->enemies)
    {
        printf("Error\nNo se pudo asignar memoria para los enemigos\n");
        close_game(game);
        return;
    }

    k = 0;
    for (i = 0; i < game->map_height; i++)
    {
        for (j = 0; j < game->map_width; j++)
        {
            if (game->map[i][j] == 'C' || game->map[i][j] == 'S')
            {
                game->enemies[k].pos.x = j;
                game->enemies[k].pos.y = i;
                game->enemies[k].type = game->map[i][j];
                k++;
            }
        }
    }
}