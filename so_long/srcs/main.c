#include "../includes/so_long.h"

int close_game(t_game *game)
{
    int i;

    if (game->mlx && game->win)
        mlx_destroy_window(game->mlx, game->win);
    
    // Liberar imágenes
    if (game->mlx && game->img_player)
        mlx_destroy_image(game->mlx, game->img_player);
    if (game->mlx && game->img_wall)
        mlx_destroy_image(game->mlx, game->img_wall);
    if (game->mlx && game->img_collectible)
        mlx_destroy_image(game->mlx, game->img_collectible);
    if (game->mlx && game->img_exit)
        mlx_destroy_image(game->mlx, game->img_exit);
    if (game->mlx && game->img_enemy_c)
        mlx_destroy_image(game->mlx, game->img_enemy_c);
    if (game->mlx && game->img_enemy_s)
        mlx_destroy_image(game->mlx, game->img_enemy_s);
    if (game->mlx && game->img_floor)
        mlx_destroy_image(game->mlx, game->img_floor);

    // Liberar mapa
    if (game->map)
        free_map(game);
    
    // Liberar enemigos
    if (game->enemies)
        free(game->enemies);

    exit(0);
    return (0);
}

int key_hook(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        close_game(game);
    
    if (game->game_over || game->win_flag)
        return (0);

    if (keycode == KEY_W)
        move_player(game, 0, -1);
    else if (keycode == KEY_A)
        move_player(game, -1, 0);
    else if (keycode == KEY_S)
        move_player(game, 0, 1);
    else if (keycode == KEY_D)
        move_player(game, 1, 0);

    return (0);
}

int game_loop(t_game *game)
{
    if (game->game_over || game->win_flag)
        return (0);

    move_enemies(game);
    if (check_enemy_collision(game))
    {
        game_over(game, 0);
        return (0);
    }

    render_game(game);
    display_moves(game);
    
    return (0);
}

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
    {
        ft_printf("Error\nUso: %s <archivo_mapa.ber>\n", argv[0]);
        return (1);
    }

    init_game(&game);
    
    ft_printf("Bienvenido a so_long! Gráficos por Foozle\n");
    
    if (!parse_map(&game, argv[1]))
    {
        ft_printf("Error\nProblema al cargar el mapa\n");
        close_game(&game);
        return (1);
    }

    if (!validate_map(&game))
    {
        ft_printf("Error\nMapa inválido\n");
        close_game(&game);
        return (1);
    }

    game.mlx = mlx_init();
    if (!game.mlx)
    {
        ft_printf("Error\nNo se pudo inicializar MLX\n");
        close_game(&game);
        return (1);
    }

    game.win = mlx_new_window(game.mlx, 
        game.map_width * TILE_SIZE, 
        game.map_height * TILE_SIZE, 
        "so_long - La Búsqueda del Tesoro");

    if (!game.win)
    {
        ft_printf("Error\nNo se pudo crear la ventana\n");
        close_game(&game);
        return (1);
    }

    load_images(&game);
    init_player(&game);
    init_enemies(&game);

    mlx_hook(game.win, 2, 1L<<0, key_hook, &game);
    mlx_hook(game.win, 17, 0, close_game, &game);
    mlx_loop_hook(game.mlx, game_loop, &game);
    
    render_game(&game);
    mlx_loop(game.mlx);

    return (0);
}