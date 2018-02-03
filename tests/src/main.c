#include <check.h>

int ft_puts(char *str);

START_TEST(ft_puts_test)
{
    ft_puts("");
    ft_puts(NULL);
    ft_puts("Hello, world!");
}
END_TEST

int main(void)
{
    return (0);
}