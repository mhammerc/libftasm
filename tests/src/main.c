#include "stdio.h"
#include "stdlib.h"
#include "string.h"

extern void ft_bzero(char *s, size_t n);
extern char *ft_strcat(char *dest, char *src);
extern int  ft_isalpha(int c);

void    check_ok(int num)
{
    printf("\tCheck %d: OK\n", num);
}

void    check_fail(int num)
{
    printf("\tCheck %d: FAIL\n", num);
}

void    check(int condition, int num)
{
    if (condition)
        check_ok(num);
    else
        check_fail(num);
}

int main()
{
    char    *str;
    char    *str2;
    int     integer;
    int     integer2;
    size_t  len;
    size_t  len2;

    printf("Welcome in this (very) small test library of libftasm.\n");

    printf("TEST 0: ft_bzero\n");

    str = strdup("Salut!");

    ft_bzero(str, strlen(str));

    check(strlen(str) == 0, 1);
    free(str);
    str = NULL;

    // ---
    printf("\n\nTEST 1: ft_strcat\n");

    str = malloc(100);
    str[0] = 0;
    str2 = ft_strcat(str, "salut :)");
    check(str == str2, 1);
    check(strcmp(str, "salut :)") == 0, 2);

    str2 = ft_strcat(str, "! Hein? Quoi?");
    check(str == str2, 3);
    check(strcmp(str, "salut :)! Hein? Quoi?") == 0, 4);
    free(str2);

    //--
    printf("\n\nTEST 2: ft_isalpha\n");
    check(ft_isalpha('A') == 1, 1);
    check(ft_isalpha('H') == 1, 2);
    check(ft_isalpha('Z') == 1, 3);
    check(ft_isalpha('a') == 1, 4);
    check(ft_isalpha('h') == 1, 5);
    check(ft_isalpha('z') == 1, 6);
    check(ft_isalpha('A' - 1) == 0, 7);
    check(ft_isalpha('Z' + 1) == 0, 8);
    check(ft_isalpha('a' - 1) == 0, 9);
    check(ft_isalpha('z' + 1) == 0, 10);


    return (0);
}
