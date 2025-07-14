#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char	result;
	int				i;

	i = 8;
	while ((i--) > 0)
	{
		result = (octet >> i & 1) + '0';
		write(1, &result, 1);
	}
}

int	main(void)
{
	print_bits(0x42);
	return (0);
}
