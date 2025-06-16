#include "../includes/so_long.h"

int parse_map(t_game *game, char *filename)
{
    int fd;
    char *line;
    char *temp;
    char *map_str;
    char **lines;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    // Utilizar get_next_line (si está en libft) o readline
    map_str = ft_strdup("");
    while ((line = get_next_line(fd)) != NULL)
    {
        temp = map_str;
        map_str = ft_strjoin(map_str, line);
        free(temp);
        free(line);
    }
    close(fd);

    // Dividir el buffer en líneas usando ft_split de libft
    lines = ft_split(map_str, '\n');
    free(map_str);
    if (!lines)
        return (0);

    // Contar líneas y establecer dimensiones
    game->map_height = 0;
    while (lines[game->map_height])
        game->map_height++;

    game->map_width = ft_strlen(lines[0]);
    game->map = lines;

    return (1);
}

int validate_map(t_game *game)
{
    int i, j;
    int player_count = 0;
    int exit_count = 0;
    int collectible_count = 0;

    // Verificar que el mapa es rectangular
    for (i = 0; i < game->map_height; i++)
    {
        if (ft_strlen(game->map[i]) != (size_t)game->map_width)
            return (0);
    }

    // Verificar que el mapa está cerrado por muros
    for (i = 0; i < game->map_height; i++)
    {
        for (j = 0; j < game->map_width; j++)
        {
            if ((i == 0 || i == game->map_height - 1 || 
                j == 0 || j == game->map_width - 1) && 
                game->map[i][j] != '1')
                return (0);
        }
    }

    // Contar elementos
    for (i = 0; i < game->map_height; i++)
    {
        for (j = 0; j < game->map_width; j++)
        {
            if (game->map[i][j] == 'P')
                player_count++;
            else if (game->map[i][j] == 'E')
            {
                exit_count++;
                game->exit_x = j;
                game->exit_y = i;
            }
            else if (game->map[i][j] == 'C')
                collectible_count++;
            else if (game->map[i][j] != '0' && game->map[i][j] != '1' && 
                    game->map[i][j] != 'S')
                return (0); // Carácter inválido
        }
    }

    // Verificar que hay exactamente un jugador y una salida, y al menos un coleccionable
    if (player_count != 1 || exit_count != 1 || collectible_count < 1)
        return (0);

    game->total_collectibles = collectible_count;
    return (1);
}

void free_map(t_game *game)
{
    int i;

    if (!game->map)
        return;

    for (i = 0; game->map[i]; i++)
        free(game->map[i]);
    free(game->map);
    game->map = NULL;
}