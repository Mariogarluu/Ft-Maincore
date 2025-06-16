#include "../includes/so_long.h"

int ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strdup(const char *s)
{
    char *dup;
    int i;
    int len;

    len = ft_strlen(s);
    dup = (char *)malloc(sizeof(char) * (len + 1));
    if (!dup)
        return (NULL);
    i = 0;
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

static int count_words(char const *s, char c)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] && s[i] == c)
            i++;
        if (s[i])
            count++;
        while (s[i] && s[i] != c)
            i++;
    }
    return (count);
}

static char *get_word(char const *s, char c, int *i)
{
    int start;
    int len;
    char *word;

    while (s[*i] && s[*i] == c)
        (*i)++;
    start = *i;
    while (s[*i] && s[*i] != c)
        (*i)++;
    len = *i - start;
    word = (char *)malloc(sizeof(char) * (len + 1));
    if (!word)
        return (NULL);
    word[len] = '\0';
    while (--len >= 0)
        word[len] = s[start + len];
    return (word);
}

char **ft_split(char const *s, char c)
{
    char **result;
    int i;
    int j;
    int word_count;

    if (!s)
        return (NULL);
    word_count = count_words(s, c);
    result = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (!result)
        return (NULL);
    i = 0;
    j = 0;
    while (j < word_count)
    {
        result[j] = get_word(s, c, &i);
        if (!result[j])
        {
            while (--j >= 0)
                free(result[j]);
            free(result);
            return (NULL);
        }
        j++;
    }
    result[j] = NULL;
    return (result);
}

void ft_putnbr(int n)
{
    char c;

    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else
    {
        c = n + '0';
        write(1, &c, 1);
    }
}

void display_moves(t_game *game)
{
    char moves_str[20];
    
    // Utilizar ft_itoa de libft para convertir el número a string
    ft_sprintf(moves_str, "Movimientos: %d | Sprites por Foozle", game->player.moves);
    
    // Mostrar en la ventana
    mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, moves_str);
    
    // También mostrar en consola
    ft_printf("Movimientos: %d | Sprites por Foozle\n", game->player.moves);
}