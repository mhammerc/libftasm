#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../include/libft.h"

size_t  ft_strlen(const char *s);

START_TEST(ft_strlen_test)
{
    fail_unless(ft_strlen(NULL) == 0, "ft_strlen(NULL)");
    fail_unless(ft_strlen("") == 0, "ft_strlen()");
    fail_unless(ft_strlen("a") == 1, "ft_strlen(a)");
    fail_unless(ft_strlen("aa") == 2, "ft_strlen(aa)");
}
END_TEST

START_TEST(ft_memcpy_test)
{
    char *s1 = "Hello!";
    char s2[10];

    ft_memcpy(s2, s1, 7);
    fail_unless(strcmp(s1, s2) == 0, "memcpy");

    s1 = "";
    ft_memcpy(s2, s1, 1);
    fail_unless(strcmp(s1, s2) == 0, "memcpy");
}
END_TEST

START_TEST(ft_strdup_test)
{
    char    *s1 = "Hello!";
    char    *s2 = ft_strdup(s1);

    fail_unless(strcmp(s1, s2) == 0, "ft_strdup(Hello)");
    free(s2);

    s1 = "";
    s2 = ft_strdup(s1);
    fail_unless(strcmp(s1, s2) == 0, "ft_strdup()");
    free(s2);

    s2 = ft_strdup(NULL);
    fail_unless(s2 == NULL, "ft_stdup(NULL)");
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Libft ASM");
    TCase *tc1_1 = tcase_create("Libft ASM");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, ft_strlen_test);
    tcase_add_test(tc1_1, ft_strdup_test);
    tcase_add_test(tc1_1, ft_memcpy_test);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
