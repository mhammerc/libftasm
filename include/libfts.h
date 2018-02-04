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

void	ft_cat(int fd);

typedef struct      s_list
{
    void            *content;
    struct s_list   *next;
    size_t          content_size;
} __attribute__((aligned(8),packed))     t_list;

t_list              *ft_lstnew(void const *content, size_t content_size);
void                ft_lstadd(t_list **alst, t_list *new);
void                ft_lstaddback(t_list **alst, t_list *new);
t_list              *ft_lstat(t_list *list, size_t index);
void                ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void                ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

#endif
