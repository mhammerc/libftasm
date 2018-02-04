
#include "libfts.h"
#include <ctype.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int cmp_putchar(int c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (c);
}

/* int cmp_putstr(char *str) */
/* { */
/* 	return (write(1, str, strlen(str))); */
/* } */

int mainft_putstr(const char *str)
{
	return (write(3, str, strlen(str)));
}

int ft_putnstr(const char *str, size_t n)
{
	return (write(3, str, n));
}

int test_bzero()
{
	mainft_putstr(__func__); mainft_putstr(":\n");
	char str[] = "Bonjour je suis une chaine de char!\n";
	char str_cmp[] = "Bonjour je suis une chaine de char!\n";
	int len = strlen(str);
	int result = 0;
	int i;

	ft_bzero(NULL, 250);

	bzero(str_cmp, 1);
	ft_bzero(str, 1);
	i = -1;
	++result;
	while (++i < len)
	{
		if (str[i] != str_cmp[i])
		{
			dprintf(3, "Failed[%d]: %c vs %c at pos: %d\n", result, str[i], str_cmp[i], i);
			ft_putnstr(str, len);
			ft_putnstr(str_cmp, len);
			return(1);
		}
	}
	bzero(str_cmp + 5, 4);
	ft_bzero(str + 5, 4);
	++result;
	i = -1;
	while (++i < len)
	{
		if (str[i] != str_cmp[i])
		{
			dprintf(3, "Failed[%d]: %c vs %c at pos: %d\n", result, str[i], str_cmp[i], i);
			ft_putnstr(str, len);
			ft_putnstr(str_cmp, len);
			return(1);
		}
	}
	bzero(str_cmp + 2, len - 3);
	ft_bzero(str + 2, len - 3);
	++result;
	i = -1;
	while (++i < len)
	{
		if (str[i] != str_cmp[i])
		{
			dprintf(3, "Failed[%d]: %c vs %c at pos: %d\n", result, str[i], str_cmp[i], i);
			ft_putnstr(str, len);
			ft_putnstr(str_cmp, len);
			return(1);
		}
	}
	return (0);
}

int test_strcat()
{
	mainft_putstr(__func__); mainft_putstr(":\n");
	char str[20] = "first_";
	char str2[] = "second\n";
	char str_cmp[20] = "first_";
	char str_cmp2[] = "second\n";
	int len = 20;
	int i;

	strcat(str_cmp, str_cmp2);
	ft_strcat(str, str2);
	i = -1;
	while (++i < len)
	{
		if (str[i] != str_cmp[i])
		{
			dprintf(3, "Failed: %c vs %c at pos: %d\n", str[i], str_cmp[i], i);
			ft_putnstr(str, len);
			ft_putnstr(str_cmp, len);
			return(1);
		}
	}
	return (0);
}

int test_isalpha()
{
	mainft_putstr(__func__); mainft_putstr(":\n");
	char a = -1;
	int ret, ret_cmp;
	while (++a < 127)
	{
		if ((ret = ft_isalpha(a) == 0) != (ret_cmp = isalpha(a) == 0))
		{
			dprintf(3, "FAILED: %c [%d] => %d vs %d\n", a, a, ret, ret_cmp);
			return (1);
		}
	}
	return (0);
}

int test_isdigit()
{
	mainft_putstr(__func__); mainft_putstr(":\n");
	char a = -1;
	int ret, ret_cmp;
	while (++a < 127)
	{
		if ((ret = ft_isdigit(a) == 0) != (ret_cmp = isdigit(a) == 0))
		{
			dprintf(3, "FAILED: %c [%d] => %d vs %d\n", a, a, ret, ret_cmp);
			return(1);
		}
	}
	return (0);
}

int test_isalnum()
{
	mainft_putstr(__func__); mainft_putstr(":\n");
	char a = -1;
	int ret, ret_cmp;
	while (++a < 127)
	{
		if ((ret = ft_isalnum(a) == 0) != (ret_cmp = isalnum(a) == 0))
		{
			dprintf(3, "FAILED: %c [%d] => %d vs %d\n", a, a, ret, ret_cmp);
			return(1);
		}
	}
	return (0);
}

int test_isprint()
{
	mainft_putstr(__func__); mainft_putstr(":\n");
	char a = -1;
	int ret, ret_cmp;
	while (++a < 127)
	{
		if ((ret = ft_isprint(a) == 0) != (ret_cmp = isprint(a) == 0))
		{
			dprintf(3, "FAILED: %c [%d] => %d vs %d\n", a, a, ret, ret_cmp);
			return(1);
		}
	}
	return (0);
}

int test_toupper()
{
	mainft_putstr(__func__); mainft_putstr(":\n");
	char a = -1;
	while (++a < 127)
	{
		if (ft_toupper(a) != toupper(a))
		{
			dprintf(3, "FAILED: %c [%d]\n", a, a);
			return(1);
		}
	}
	return (0);
}

int test_tolower()
{
	mainft_putstr(__func__); mainft_putstr(":\n");
	char a = -1;
	while (++a < 127)
	{
		if (ft_tolower(a) != tolower(a))
		{
			dprintf(3, "FAILED: %c [%d]\n", a, a);
			return(1);
		}
	}
	return (0);
}

int test_puts()
{
	mainft_putstr(__func__); mainft_putstr(":\n");
	char str[] = "It's a char line you have to print. Not this one";
	str[35] = 0;
	int ret, ret_cmp;
	mainft_putstr("Notre___:|"); ft_puts(NULL);mainft_putstr("|\n");
	mainft_putstr("Notre___:|"); ret = ft_puts(str);mainft_putstr("|\n");
	mainft_putstr("Original:|"); ret_cmp = puts(str);mainft_putstr("|\n");
	if (!(ret > 0 && ret_cmp > 0) && ret != -1)
	{
		dprintf(3, "FAILED: %d vs %d\n", ret, ret_cmp);
		return (1);
	}
	return (0);
}

int test_strlen()
{
	mainft_putstr(__func__); mainft_putstr(":\n");
	char str[] = "zagaga";
	int ret, ret_cmp;
	ret = ft_strlen(str);
	ret_cmp = strlen(str);
	if (ret != ret_cmp)
	{
		dprintf(3, "FAILED: %d vs %d (on %s)", ret, ret_cmp, str);
		return (1);
	}
	ret = ft_strlen(NULL);
	ret_cmp = 0;
	if (ret != ret_cmp)
	{
		dprintf(3, "FAILED: %d vs %d (on nullptr)", ret, ret_cmp);
		return (1);
	}
	return (0);
}

int test_memset()
{
	mainft_putstr(__func__); mainft_putstr(":\n");
	char a = -1;
	char *str = strdup("Bonjour je suis une chaine de char!\n");
	char *str_cmp = strdup("Bonjour je suis une chaine de char!\n");
	char *ret, *ret_cmp;
	int len = strlen(str);
	int result = 0;
	int i;

	while (++a < 127)
	{
		++result;
		if (ft_memset(NULL, a, 250) != NULL)
		{
			dprintf(3, "Failed[%d]: memset on NULL\n", result);
			return (1);
		}
		ret_cmp = memset(str_cmp, a, 1);
		ret = ft_memset(str, a, 1);
		i = -1;
		++result;
		while (++i < len)
		{
			if (ret[i] != ret_cmp[i])
			{
				ft_putnstr(ret, len);
				ft_putnstr(ret_cmp, len);
				dprintf(3, "Failed[%d]: %c vs %c at pos: %d/%d\n", result, ret[i], ret_cmp[i], i, len);
				return(1);
			}
		}
		ret_cmp = memset(str_cmp + 5, a, 4);
		ret = ft_memset(str + 5, a, 4);
		++result;
		i = -1;
		while (++i < (len - 5))
		{
			if (ret[i] != ret_cmp[i])
			{
				ft_putnstr(ret, len);
				ft_putnstr(ret_cmp, len);
				dprintf(3, "Failed[%d]: %c vs %c at pos: %d/%d\n", result, ret[i], ret_cmp[i], i, len);
				return(1);
			}
		}
		ret_cmp = memset(str_cmp + 2, a, len - 3);
		ret = ft_memset(str + 2, a, len - 3);
		++result;
		i = -1;
		while (++i < (len - 2))
		{
			if (ret[i] != ret_cmp[i])
			{
				ft_putnstr(ret, len);
				ft_putnstr(ret_cmp, len);
				dprintf(3, "Failed[%d]: %c vs %c at pos: %d/%d\n", result, ret[i], ret_cmp[i], i, len);
				return(1);
			}
		}
	}
	free(str);
	free(str_cmp);
	return (0);
}

int test_memcpy()
{
	mainft_putstr(__func__); mainft_putstr(":\n");
	char str[] = "Bonjour je suis une chaine de char!\n";
	char str_cmp[] = "Bonjour je suis une chaine de char!\n";
	char ret[100], ret_cmp[100];
	char *me, *cmp;
	int len = strlen(str);
	int result = 0;
	int i;

	++result;
	if (ft_memcpy(NULL, str, -5) != NULL)
	{
		dprintf(3, "Failed[%d]: memcpy on NULL\n", result);
		return (1);
	}
	++result;
	if (ft_memcpy(ret, NULL, 250) != NULL)
	{
		dprintf(3, "Failed[%d]: memcpy on NULL\n", result);
		return (1);
	}
	cmp = memcpy(ret_cmp, str_cmp, len);
	me = ft_memcpy(ret, str, len);
	i = -1;
	++result;
	while (++i < len)
	{
		if (me[i] != cmp[i])
		{
			ft_putnstr(ret, len);
			ft_putnstr(ret_cmp, len);
			dprintf(3, "Failed[%d]: %c vs %c at pos: %d/%d\n", result, me[i], cmp[i], i, len);
			return(1);
		}
	}
	memcpy(ret_cmp + len, str_cmp, len);
	ft_memcpy(ret + len, str, len);
	i = -1;
	++result;
	while (++i < 2 * len)
	{
		if (me[i] != cmp[i])
		{
			ft_putnstr(ret, 2 * len);
			ft_putnstr(ret_cmp, 2 * len);
			dprintf(3, "Failed[%d]: %c vs %c at pos: %d/%d\n", result, me[i], cmp[i], i, 2 * len);
			return(1);
		}
	}
	return (0);
}

int test_strdup()
{
	mainft_putstr(__func__); mainft_putstr(":\n");
	char *str;
	char *str_cmp;
	int len, len_cmp;
	int i;
	if ((str = ft_strdup(NULL)) != NULL)
	{
		dprintf(3, "FAILED: not support NULL\n");
		return (1);
	}
	str = ft_strdup("Coucou");
	str_cmp = strdup("Coucou");
	len = strlen(str);
	len_cmp = strlen(str_cmp);
	if (len != len_cmp)
	{
		dprintf(3, "FAILED: len is %d vs %d\n", len, len_cmp);
		return (1);
	}
	i = -1;
	while (++i < len)
	{
		if (str[i] != str_cmp[i])
		{
			ft_putnstr(str, len);
			ft_putnstr(str_cmp, len);
			dprintf(3, "FAILED: %c vs %c\n", str[i], str_cmp[i]);
			return (1);
		}
	}
	free(str);
	free(str_cmp);
	return (0);
}

int test_cat(char ** argv)
{
	mainft_putstr(__func__); mainft_putstr(":\n");
	ft_cat(-42);
	mainft_putstr("Wait for a user input:\n");
	ft_cat(open(__FILE__, O_RDONLY));
	if (argv[1])
		ft_cat(open(argv[1], O_RDONLY));
	return (0);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	mainft_putstr("PART 1:\n_______\n");
	if (test_bzero() ||
			test_strcat() ||
			test_isalpha() ||
			test_isdigit() ||
			test_isalnum() ||
			test_isprint() ||
			test_toupper() ||
			test_tolower() ||
    test_puts())
		return (1);
	mainft_putstr("\nPART 2:\n_______\n");
	if (test_strlen() ||
			test_memset() ||
			test_memcpy() ||
			test_strdup())
		return (1);
	mainft_putstr("\nPART 3:\n_______\n");
	if (test_cat(argv))
		return (1);
	mainft_putstr("\033c\n\033[38;5;117mALL PASSED:\n___________\n\033[0m");
	return (0);
}
