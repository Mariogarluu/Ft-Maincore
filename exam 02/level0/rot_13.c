#include <unistd.h>

char	*rot_13(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = ((str[i] - 'A' + 13) % 26) + 'A';
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = ((str[i] - 'a' + 13) % 26) + 'a';
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rot_13(argv[1]);
	write(1, "\n", 1);
	return (0);
}