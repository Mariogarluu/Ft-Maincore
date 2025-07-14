#include <unistd.h>

void	rotone(char *str)
{
	char	c;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			c = (str[i] - 'a' + 1) % 26 + 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			c = (str[i] - 'A' + 1) % 26 + 'A';
		write(1, &c, 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}