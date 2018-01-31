#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>

extern void ft_bzero(char *s, size_t n);
extern char *ft_strcat(char *dest, char *src);
extern int  ft_isalpha(int c);
extern int  ft_isdigit(int c);
extern int  ft_isalnum(int c);
extern int  ft_isascii(int c);
extern int  ft_isspace(int c);
extern int  ft_ispunct(int c);
extern int  ft_isprint(int c);
extern int  ft_toupper(int c);
extern int  ft_tolower(int c);
extern int  ft_puts(char *str);

void    check_ok(int num)
{
    printf("\tCheck %.2d: OK\n", num);
}

void    check_fail(int num)
{
    printf("\tCheck %.2d: FAIL\n", num);
}

void    check(int condition, int num)
{
    if (condition)
        check_ok(num);
    else
        check_fail(num);
}

typedef int (*t_ascii_func)(int);

void    check_every_ascii(t_ascii_func original, t_ascii_func tested, int strict)
{
    int i;
    int ret1;
    int ret2;

    i = 0;
    while (i <= 127)
    {
        ret1 = original(i);
        ret2 = tested(i);

        if (strict && ret1 != ret2)
        {
            check_fail(1);
            break;
        }

        if (!strict && (
            (ret1 > 0 && ret2 == 0) ||
            (ret1 == 0 && ret2 > 0)))
        {
            printf("\tTest: %d, Original: %d, tested: %d\n", i, ret1, ret2);
            check_fail(1);
            break;
        }

        ++i;
    }
    if (i == 128)
        check_ok(1);

}

int main()
{
    char    *str;
    char    *str2;
    int     integer;
    int     integer2;
    int     ret;
    int     ret2;
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

    //--
    printf("\n\nTEST 3: ft_isdigit\n");
    check(ft_isdigit('0' - 1) == 0, 1);
    check(ft_isdigit('9' + 1) == 0, 2);
    check(ft_isdigit('0') == 1, 3);
    check(ft_isdigit('1') == 1, 4);
    check(ft_isdigit('2') == 1, 5);
    check(ft_isdigit('3') == 1, 6);
    check(ft_isdigit('4') == 1, 7);
    check(ft_isdigit('5') == 1, 8);
    check(ft_isdigit('6') == 1, 9);
    check(ft_isdigit('7') == 1, 10);
    check(ft_isdigit('8') == 1, 11);
    check(ft_isdigit('9') == 1, 12);

    printf("\n\nTEST 4: ft_isalnum\n");
    check(ft_isalnum('A') == 1, 1);
    check(ft_isalnum('H') == 1, 2);
    check(ft_isalnum('Z') == 1, 3);
    check(ft_isalnum('a') == 1, 4);
    check(ft_isalnum('h') == 1, 5);
    check(ft_isalnum('z') == 1, 6);
    check(ft_isalnum('A' - 1) == 0, 7);
    check(ft_isalnum('Z' + 1) == 0, 8);
    check(ft_isalnum('a' - 1) == 0, 9);
    check(ft_isalnum('z' + 1) == 0, 10);
    check(ft_isalnum('0' - 1) == 0, 11);
    check(ft_isalnum('9' + 1) == 0, 12);
    check(ft_isalnum('0') == 1, 13);
    check(ft_isalnum('1') == 1, 14);
    check(ft_isalnum('2') == 1, 15);
    check(ft_isalnum('3') == 1, 16);
    check(ft_isalnum('4') == 1, 17);
    check(ft_isalnum('5') == 1, 18);
    check(ft_isalnum('6') == 1, 19);
    check(ft_isalnum('7') == 1, 20);
    check(ft_isalnum('8') == 1, 21);
    check(ft_isalnum('9') == 1, 22);

    printf("\n\nTEST 5: ft_isascii\n");
    check(ft_isascii(-1) == 0, 1);
    check(ft_isascii(128) == 0, 2);
    check(ft_isascii(0) == 1, 3);
    check(ft_isascii(127) == 1, 4);
    check(ft_isascii(42) == 1, 5);

    printf("\n\nTEST 6: ft_isspace\n");
    check(ft_isspace(' ') == 1, 1);
    check(ft_isspace(' ' + 1) == 0, 2);
    check(ft_isspace(' ' - 1) == 0, 3);

    printf("\n\nTEST 7: ft_ispunct\n");
    check(ft_ispunct(33) == 1, 1);
    check(ft_ispunct(47) == 1, 2);
    check(ft_ispunct(58) == 1, 3);
    check(ft_ispunct(64) == 1, 4);
    check(ft_ispunct(91) == 1, 5);
    check(ft_ispunct(96) == 1, 6);
    check(ft_ispunct(123) == 1, 7);
    check(ft_ispunct(126) == 1, 8);
    check(ft_ispunct(33 - 1) == 0, 9);
    check(ft_ispunct(47 + 1) == 0, 10);
    check(ft_ispunct(58 - 1) == 0, 11);
    check(ft_ispunct(64 + 1) == 0, 12);
    check(ft_ispunct(91 - 1) == 0, 13);
    check(ft_ispunct(96 + 1) == 0, 14);
    check(ft_ispunct(123 - 1) == 0, 15);
    check(ft_ispunct(126 + 1) == 0, 16);

    printf("\n\nTEST 8: ft_isprint\n");
    check_every_ascii(&isprint, &ft_isprint, 0);

    printf("\n\nTEST 9: ft_toupper\n");
    check_every_ascii(&toupper, &ft_toupper, 1);

    printf("\n\nTEST 9: ft_toupper\n");
    check_every_ascii(&tolower, &ft_tolower, 1);

    printf("\n\nTEST 10: ft_puts\n");
    ft_puts("Hello :D");

    return (0);
}
