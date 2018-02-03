#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int     ft_isalpha(int c);
int     ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);

int     ft_toupper(int c);
int     ft_tolower(int c);

int     ft_puts(const char *s);

size_t  ft_strlen(const char *s);
char    *ft_strcat(char *dest, const char *src);
char    *ft_strdup(const char *s);

void    ft_bzero(void *s, size_t n);
void    *ft_memset(void *s, int c, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);

#endif