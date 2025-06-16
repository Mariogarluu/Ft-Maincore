#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "libft.h"    // Incluimos libft.h para usar sus funciones
# include "ft_printf.h" // Incluimos ft_printf.h para usar ft_printf en lugar de printf

# define TILE_SIZE 64
# define MAX_MAP_SIZE 50
# define MAX_COLLECTIBLES 50

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_coord
{
    int	x;
    int	y;
}	t_coord;

typedef struct s_player
{
    t_coord	pos;
    int		moves;
    int		collectibles;
}	t_player;

typedef struct s_enemy
{
    t_coord	pos;
    char	type;
}	t_enemy;

typedef struct s_game
{
    void		*mlx;
    void		*win;
    char		**map;
    int			map_width;
    int			map_height;
    int			total_collectibles;
    t_player	player;
    t_enemy		*enemies;
    int			num_enemies;
    void		*img_player;
    void		*img_wall;
    void		*img_collectible;
    void		*img_exit;
    void		*img_enemy_c;
    void		*img_enemy_s;
    void		*img_floor;
    int			exit_x;
    int			exit_y;
    int			game_over;
    int			win_flag;
}	t_game;

// main.c
int		main(int argc, char **argv);
int		game_loop(t_game *game);
int		key_hook(int keycode, t_game *game);
int		close_game(t_game *game);

// init.c
void	init_game(t_game *game);
void	load_images(t_game *game);
void	init_player(t_game *game);
void	init_enemies(t_game *game);
int		count_enemies(t_game *game);

// move.c
void	move_player(t_game *game, int dir_x, int dir_y);
void	move_enemies(t_game *game);
int		check_enemy_collision(t_game *game);
int		can_move(t_game *game, int x, int y, char type);

// map.c
int		parse_map(t_game *game, char *filename);
int		validate_map(t_game *game);
void	free_map(t_game *game);

// render.c
void	render_game(t_game *game);
void	render_map(t_game *game);
void	render_player(t_game *game);
void	render_enemies(t_game *game);
void	put_image(t_game *game, void *img, int x, int y);

// game_logic.c
int		update_game_state(t_game *game);
int		check_collectible(t_game *game);
int		check_exit(t_game *game);
void	game_over(t_game *game, int win);

#endif