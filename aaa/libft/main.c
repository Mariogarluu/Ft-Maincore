#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char ft_toupper_no_index(unsigned int index, char c)
{
	(void)index;
	return ft_toupper(c);
}

void ft_example_function(unsigned int index, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
	printf("Índice %u: %c\n", index, *c);
}

void del_function(void *content)
{
	free(content);
}

void *map_function(void *content)
{
	char *new_content = ft_strdup((char *)content);
	if (new_content)
	{
		for (size_t i = 0; new_content[i]; i++)
			new_content[i] = ft_toupper(new_content[i]);
	}
	return new_content;
}

void print_content(void *content)
{
	printf("Elemento: %s\n", (char *)content);
}

int main(void)
{
	// Pruebas de las funciones de ft_is*
	char test_char = 'A';
	printf("ft_isalpha('%c'): %d\n", test_char, ft_isalpha(test_char));
	test_char = '1';
	printf("ft_isalpha('%c'): %d\n", test_char, ft_isalpha(test_char));

	test_char = '9';
	printf("ft_isdigit('%c'): %d\n", test_char, ft_isdigit(test_char));
	test_char = 'A';
	printf("ft_isdigit('%c'): %d\n", test_char, ft_isdigit(test_char));

	test_char = 'b';
	printf("ft_isalnum('%c'): %d\n", test_char, ft_isalnum(test_char));
	test_char = '@';
	printf("ft_isalnum('%c'): %d\n", test_char, ft_isalnum(test_char));

	unsigned char test_uchar = 128;
	printf("ft_isascii(%d): %d\n", test_uchar, ft_isascii(test_uchar));
	test_uchar = '!';
	printf("ft_isascii('%c'): %d\n", test_uchar, ft_isascii(test_uchar));

	test_char = 32;
	printf("ft_isprint('%c'): %d\n", test_char, ft_isprint(test_char));
	test_char = 126;
	printf("ft_isprint('%c'): %d\n", test_char, ft_isprint(test_char));
	test_char = 31;
	printf("ft_isprint(%d): %d\n", test_char, ft_isprint(test_char));

	// Pruebas de las funciones de ft_memset
	char buffer[20];
	ft_memset(buffer, '*', 19);
	buffer[19] = '\0';
	printf("ft_memset (19 veces *): %s\n", buffer);

	ft_memset(buffer, 'X', 10);
	buffer[10] = '\0';
	printf("ft_memset (10 veces X): %s\n", buffer);

	ft_memset(buffer, '\0', 5);
	printf("ft_memset (5 veces null): '%s'\n", buffer);

	ft_memset(buffer, 255, 5);
	printf("ft_memset (5 veces 255): ");
	for (int i = 0; i < 5; i++)
		printf("%d ", (unsigned char)buffer[i]);
	printf("\n");

	// Pruebas de ft_strlcpy y ft_strlcat
	char src[] = "Hola Mundo";
	char dest[20];
	size_t len;

	len = ft_strlcpy(dest, src, 10);
	printf("ft_strlcpy: Copia '%s' (longitud: %zu)\n", dest, len);

	char dest_cat[30] = "Texto inicial ";
	len = ft_strlcat(dest_cat, "y más texto", 30);
	printf("ft_strlcat: Concatenación '%s' (longitud total: %zu)\n", dest_cat, len);

	// Pruebas de toupper y tolower
	printf("ft_toupper('a'): %c\n", ft_toupper('a'));
	printf("ft_tolower('A'): %c\n", ft_tolower('A'));

	// Pruebas de strchr y strrchr
	char *result_chr = ft_strchr(src, 'o');
	if (result_chr)
		printf("ft_strchr: Encontrado '%c' en '%s'\n", *result_chr, src);
	else
		printf("ft_strchr: No encontrado en '%s'\n", src);

	result_chr = ft_strrchr(src, 'o');
	if (result_chr)
		printf("ft_strrchr: Encontrado '%c' en '%s'\n", *result_chr, src);
	else
		printf("ft_strrchr: No encontrado en '%s'\n", src);

	// Prueba de strncmp
	char s1[] = "Hola";
	char s2[] = "HOLA";
	printf("ft_strncmp: Resultado de comparación '%d'\n", ft_strncmp(s1, s2, 4));

	// Pruebas de ft_memchr
	char memblock[20] = "abcdefghijklmnopqrst";

	char *found = (char *)ft_memchr(memblock, 'p', 20);
	if (found != NULL)
		printf("Carácter encontrado: %c\n", *found);
	else
		printf("Carácter no encontrado.\n");

	found = (char *)ft_memchr(memblock, 'z', 20);
	if (found != NULL)
		printf("Carácter encontrado: %c\n", *found);
	else
		printf("Carácter no encontrado.\n");

	// Pruebas de ft_memcmp
	char memblock1[] = "ABCDE";
	char memblock2[] = "ABCDF";

	int result = ft_memcmp(memblock1, memblock2, 5);
	printf("ft_memcmp: Resultado de comparar '%s' y '%s': %d\n", memblock1, memblock2, result);

	result = ft_memcmp(memblock1, memblock1, 5);
	printf("ft_memcmp: Resultado de comparar '%s' y '%s': %d\n", memblock1, memblock1, result);

	// Pruebas para ft_strnstr
	const char *haystack = "This is a simple string";
	const char *needle = "simple";
	char *resultu;

	resultu = ft_strnstr(haystack, needle, 20);
	printf("ft_strnstr: '%s' en '%s': %s\n", needle, haystack, resultu ? resultu : "No encontrado");

	needle = "complex";
	resultu = ft_strnstr(haystack, needle, 20);
	printf("ft_strnstr: '%s' en '%s': %s\n", needle, haystack, resultu ? resultu : "No encontrado");

	// Pruebas para ft_atoi
	const char *number_str = "  -12345";
	printf("ft_atoi('%s'): %d\n", number_str, ft_atoi(number_str));

	number_str = "42";
	printf("ft_atoi('%s'): %d\n", number_str, ft_atoi(number_str));

	number_str = "+2147483647";
	printf("ft_atoi('%s'): %d\n", number_str, ft_atoi(number_str));

	number_str = "  00010203abc";
	printf("ft_atoi('%s'): %d\n", number_str, ft_atoi(number_str));

	// Pruebas para ft_calloc
	int *arr = (int *)ft_calloc(5, sizeof(int));
	if (arr)
	{
		for (int i = 0; i < 5; i++)
			printf("ft_calloc[%d]: %d\n", i, arr[i]);
		free(arr);
	}
	else
		printf("ft_calloc: Error al asignar memoria\n");

	// Pruebas para ft_strdup
	const char *original = "Hello, World!";
	char *duplicate = ft_strdup(original);
	if (duplicate)
	{
		printf("ft_strdup: Original '%s', Duplicado '%s'\n", original, duplicate);
		free(duplicate);
	}
	else
		printf("ft_strdup: Error al duplicar cadena\n");

	// Pruebas ft_substr
	char *str = "Hola Mundo!";
	char *resultptr;

	resultptr = ft_substr(str, 5, 3);
	if (resultptr)
	{
		printf("Substring: '%s'\n", resultptr);
		free(resultptr);
	}

	resultptr = ft_substr(str, 12, 5);
	if (resultptr)
	{
		printf("Substring fuera de rango: '%s'\n", resultptr);
		free(resultptr);
	}

	resultptr = ft_substr(str, 0, 20);
	if (resultptr)
	{
		printf("Substring mayor que el tamaño: '%s'\n", resultptr);
		free(resultptr);
	}

	// Pruebas para ft_strjoin
	char *str1 = "Hola ";
	char *str2 = "Mundo!";
	char *joined = ft_strjoin(str1, str2);

	if (joined)
	{
		printf("ft_strjoin: '%s' + '%s' = '%s'\n", str1, str2, joined);
		free(joined);
	}
	else
		printf("Error al unir las cadenas\n");

	// Pruebas para ft_strtrim
	char *str11 = "  ***Hola Mundo***  ";
	char *set = "* ";
	char *trimmed_str;

	trimmed_str = ft_strtrim(str11, set);
	if (trimmed_str)
	{
		printf("ft_strtrim: '%s' recortado: '%s'\n", str11, trimmed_str);
		free(trimmed_str);
	}
	else
	{
		printf("Error al recortar la cadena\n");
	}

	str11 = "12345";
	set = "123";
	trimmed_str = ft_strtrim(str11, set);
	if (trimmed_str)
	{
		printf("ft_strtrim: '%s' recortado: '%s'\n", str11, trimmed_str);
		free(trimmed_str);
	}

	str11 = "****";
	set = "*";
	trimmed_str = ft_strtrim(str11, set);
	if (trimmed_str)
	{
		printf("ft_strtrim: '%s' recortado: '%s'\n", str11, trimmed_str);
		free(trimmed_str);
	}

	// Pruebas para ft_split
	char *str12 = "Hola mundo 42 en el   mar";
	char **split_result = ft_split(str12, ' ');

	if (split_result)
	{
		for (int i = 0; split_result[i] != NULL; i++)
		{
			printf("ft_split: Substring %d: '%s'\n", i, split_result[i]);
			free(split_result[i]);
		}
		free(split_result);
	}
	else
	{
		printf("Error en la división de la cadena\n");
	}

	str12 = "ab,cd,ef,gh";
	split_result = ft_split(str, ',');

	if (split_result)
	{
		for (int i = 0; split_result[i] != NULL; i++)
		{
			printf("ft_split: Substring %d: '%s'\n", i, split_result[i]);
			free(split_result[i]);
		}
		free(split_result);
	}
	//Itoa
	char *num_str;

	num_str = ft_itoa(-2147483648);
	printf("ft_itoa(-2147483648): %s\n", num_str);
	free(num_str);

	num_str = ft_itoa(2147483647);
	printf("ft_itoa(2147483647): %s\n", num_str);
	free(num_str);

	num_str = ft_itoa(0);
	printf("ft_itoa(0): %s\n", num_str);
	free(num_str);

	//Strapi
	char *strapi = "Hola Mundo!";
	char *resultapi = ft_strmapi(strapi, ft_toupper_no_index);

	if (resultapi)
	{
		printf("Resultado de ft_strmapi: '%s'\n", resultapi);
		free(resultapi);
	}
	else
	{
		printf("Error al aplicar ft_strmapi\n");
	}

	// Prueba de ft_striteri
	char str_to_modify[] = "hola mundo!";
	printf("Antes de ft_striteri: '%s'\n", str_to_modify);
	ft_striteri(str_to_modify, ft_example_function);
	printf("Después de ft_striteri: '%s'\n", str_to_modify);

	// Prueba de ft_putchar_fd
	printf("Prueba de ft_putchar_fd:\n");
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);

	// Prueba de ft_putstr_fd
	printf("\nPrueba de ft_putstr_fd:\n");
	ft_putstr_fd("Hola Mundo", 1);
	ft_putchar_fd('\n', 1);

	// Prueba de ft_putendl_fd
	printf("\nPrueba de ft_putendl_fd:\n");
	ft_putendl_fd("Hola Mundo", 1);

	// Prueba de ft_putnbr_fd
	printf("\nPrueba de ft_putnbr_fd:\n");
	ft_putnbr_fd(42, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-42, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);

	return 0;
}

