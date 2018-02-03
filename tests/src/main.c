#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../../include/libft.h"

void    test_for_each_ascii(char *test_name, int (*func1)(int), int (*func2)(int), int strict)
{
    int     i;

    i = 0;
    while (i < 256)
    {
        if (strict)
            fail_unless(func1(i) == func2(i), test_name);
        else
        {
            int res1 = func1(i);
            int res2 = func2(i);    

            if (res1 == 0 && res2 != 0)
                fail_unless(0, test_name);
            if (res1 != 0 && res2 == 0)
                fail_unless(0, test_name);
        }
        ++i;
    }
}

START_TEST(ft_isalpha_test)
{
    test_for_each_ascii("isalpha", &ft_isalpha, &isalpha, 0);
}
END_TEST

START_TEST(ft_isdigit_test)
{
    test_for_each_ascii("isdigit", &ft_isdigit, &isdigit, 0);
}
END_TEST

START_TEST(ft_isalnum_test)
{
    test_for_each_ascii("isalnum", &ft_isalnum, &isalnum, 0);
}
END_TEST

START_TEST(ft_isascii_test)
{
    test_for_each_ascii("isascii", &ft_isascii, &isascii, 0);
}
END_TEST

START_TEST(ft_isprint_test)
{
    test_for_each_ascii("isprint", &ft_isprint, &isprint, 0);
}
END_TEST

START_TEST(ft_toupper_test)
{
    test_for_each_ascii("toupper", &ft_toupper, &toupper, 1);
}
END_TEST

START_TEST(ft_tolower_test)
{
    test_for_each_ascii("tolower", &ft_tolower, &tolower, 1);
}
END_TEST

START_TEST(ft_strlen_test)
{
    fail_unless(ft_strlen(NULL) == 0, "ft_strlen(NULL)");
    fail_unless(ft_strlen("") == 0, "ft_strlen()");
    fail_unless(ft_strlen("a") == 1, "ft_strlen(a)");
    fail_unless(ft_strlen("aa") == 2, "ft_strlen(aa)");
}
END_TEST

START_TEST(ft_strcat_test)
{
    char *s1 = "Hello";    
    char *s2 = ", ";
    char *s3 = "world";
    char *s4 = "!";
    char s5[50];

    s5[0] = '\0';

    ft_strcat(s5, s1);
    fail_unless(strcmp(s5, "Hello") == 0, "strcat");

    ft_strcat(s5, s2);
    fail_unless(strcmp(s5, "Hello, ") == 0, "strcat");

    ft_strcat(s5, s3);
    fail_unless(strcmp(s5, "Hello, world") == 0, "strcat");

    ft_strcat(s5, s4);
    fail_unless(strcmp(s5, "Hello, world!") == 0, "strcat");
}
END_TEST

START_TEST(ft_strdup_test)
{
    char *s1 = "Hello!";
    char *s2 = ft_strdup(s1);

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

START_TEST(ft_bzero_test)
{
    char *s1 = "Hello!";
    char *s2 = strdup(s1);

    ft_bzero(s2, 0);
    fail_unless(strcmp(s1, s2) == 0, "bzero");

    ft_bzero(s2, strlen(s1)); 
    fail_unless(strcmp(s2, "") == 0, "bzero");

    free(s2);
}
END_TEST

START_TEST(ft_memset_test)
{
    char s1[10];

    s1[9] = '\0';

    ft_memset(s1, 'a', 9);
    fail_unless(strcmp(s1, "aaaaaaaaa") == 0, "memset");

    ft_memset(s1 + 1, 'b', 2);
    fail_unless(strcmp(s1, "abbaaaaaa") == 0, "memset");

    ft_memset(s1 + 4, 'c', 4);
    fail_unless(strcmp(s1, "abbacccca") == 0, "memset");

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

int main(void)
{
    Suite *s1 = suite_create("Libft ASM"); TCase *tc1_1 = tcase_create("Libft ASM");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, ft_isalpha_test);
    tcase_add_test(tc1_1, ft_isdigit_test);
    tcase_add_test(tc1_1, ft_isalnum_test);
    tcase_add_test(tc1_1, ft_isascii_test);
    tcase_add_test(tc1_1, ft_isprint_test);
    tcase_add_test(tc1_1, ft_toupper_test);
    tcase_add_test(tc1_1, ft_tolower_test);
    tcase_add_test(tc1_1, ft_strlen_test);
    tcase_add_test(tc1_1, ft_strcat_test);
    tcase_add_test(tc1_1, ft_strdup_test);
    tcase_add_test(tc1_1, ft_bzero_test);
    tcase_add_test(tc1_1, ft_memset_test);
    tcase_add_test(tc1_1, ft_memcpy_test);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
