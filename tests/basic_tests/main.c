#include <signal.h>
#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../../include/libfts.h"

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

START_TEST(ft_lstnew_test)
{
    printf("Testing ft_lstnew...");
    t_list *list;

    list = ft_lstnew(NULL, 2);
    fail_unless(list != 0, "ft_lstnew 1");
    fail_unless(list->next == NULL, "ft_lstnew 2");
    fail_unless(list->content_size == 0, "ft_lstnew 3");
    fail_unless(list->content == NULL, "ft_lstnew 4");
    free(list);

    list = ft_lstnew(NULL, 42);
    fail_unless(list != 0, "ft_lstnew 5");
    fail_unless(list->next == NULL, "ft_lstnew 6");
    fail_unless(list->content_size == 0, "ft_lstnew 7");
    fail_unless(list->content == NULL, "ft_lstnew 8");
    free(list);

    char *msg = "Hello!";
    list = ft_lstnew(msg, strlen(msg) + 1);
    fail_unless(list != 0, "ft_lstnew 9");
    fail_unless(list->next == NULL, "ft_lstnew 10");
    fail_unless(list->content_size == strlen(msg) + 1, "ft_lstnew 11");
    fail_unless(strcmp(list->content, msg) == 0, "ft_lstnew 12");
    fail_unless(list->content != msg, "ft_lstnew 13");
    free(list);

    printf(" done!\n");
}
END_TEST

START_TEST(ft_lstadd_test)
{
    printf("Testing ft_lstadd...");

    t_list *list_begin;
    t_list *list2;
    t_list *list3;
    t_list *list4;

    list_begin = ft_lstnew(NULL, 0);
    list2 = list_begin;
    list3 = ft_lstnew(NULL, 0);
    list4 = ft_lstnew(NULL, 0);

    ft_lstadd(&list_begin, list3);
    ft_lstadd(&list_begin, list4);

    fail_unless(list_begin == list4, "ft_lstadd 1");
    fail_unless(list_begin->next == list3, "ft_lstadd 2");
    fail_unless(list_begin->next->next == list2, "ft_lstadd 7");
    fail_unless(list_begin->content_size == 0, "ft_lstadd 3");
    fail_unless(list_begin->content == NULL, "ft_lstadd 4");
    fail_unless(list_begin->next->content_size == 0, "ft_lstadd 5");
    fail_unless(list_begin->next->content == NULL, "ft_lstadd 6");

    ft_lstadd(&list_begin, NULL);
    ft_lstadd(NULL, NULL);
    ft_lstadd(NULL, list2);


    list_begin = NULL;
    list2->next = NULL;
    list3->next = NULL;
    list4->next = NULL;
    ft_lstadd(&list_begin, list4);
    ft_lstadd(&list_begin, list3);
    ft_lstadd(&list_begin, list2);

    fail_unless(list_begin == list2, "ft_lstadd 1");
    fail_unless(list_begin->next == list3, "ft_lstadd 2");
    fail_unless(list_begin->next->next == list4, "ft_lstadd 7");
    fail_unless(list_begin->content_size == 0, "ft_lstadd 3");
    fail_unless(list_begin->content == NULL, "ft_lstadd 4");
    fail_unless(list_begin->next->content_size == 0, "ft_lstadd 5");
    fail_unless(list_begin->next->content == NULL, "ft_lstadd 6");

    printf(" done!\n");
}
END_TEST

START_TEST(ft_lstaddback_test)
{
    printf("Testing ft_lstaddback...");

    t_list *list_begin;
    t_list *list2;
    t_list *list3;

    list_begin = NULL;
    list2 = ft_lstnew(NULL, 0);
    list3 = ft_lstnew(NULL, 0);

    ft_lstaddback(&list_begin, list2);

    fail_unless(list_begin == list2, "ft_lstaddback 7");

    ft_lstaddback(&list_begin, list3);

    fail_unless(list_begin == list2, "ft_lstaddback 1");
    fail_unless(list_begin->next == list3, "ft_lstaddback 2");
    fail_unless(list_begin->content_size == 0, "ft_lstaddback 3");
    fail_unless(list_begin->content == NULL, "ft_lstaddback 4");
    fail_unless(list_begin->next->content_size == 0, "ft_lstaddback 5");
    fail_unless(list_begin->next->content == NULL, "ft_lstaddback 6");

    ft_lstaddback(&list_begin, NULL);
    ft_lstaddback(NULL, NULL);
    ft_lstaddback(NULL, list2);

    printf(" done!\n");
}
END_TEST

START_TEST(ft_lstat_test)
{
    printf("Testing ft_lstat...");

    t_list *list_begin;
    t_list *list0;
    t_list *list1;
    t_list *list2;
    t_list *list3;

    list_begin = NULL;
    list0 = ft_lstnew(NULL, 0);
    list1 = ft_lstnew(NULL, 0);
    list2 = ft_lstnew(NULL, 0);
    list3 = ft_lstnew(NULL, 0);

    ft_lstaddback(&list_begin, list0);
    ft_lstaddback(&list_begin, list1);
    ft_lstaddback(&list_begin, list2);
    ft_lstaddback(&list_begin, list3);

    fail_unless(list_begin == list0, "ft_lstat 1");
    fail_unless(list_begin->next == list1, "ft_lstat 2");
    fail_unless(list_begin->next->next == list2, "ft_lstat 3");
    fail_unless(list_begin->next->next->next == list3, "ft_lstat 4");

    fail_unless(ft_lstat(list_begin, 0) == list0, "ft_lstat 5");
    fail_unless(ft_lstat(list_begin, 1) == list1, "ft_lstat 5");
    fail_unless(ft_lstat(list_begin, 2) == list2, "ft_lstat 5");
    fail_unless(ft_lstat(list_begin, 3) == list3, "ft_lstat 5");

    printf(" done!\n");
}
END_TEST

int count = 0;

void del_func_1(void *content, size_t size)
{
    fail_unless(content == NULL, "lstdel | lstdelone");
    fail_unless(size == 0, "lstdel | lstdelone");
    ++count;
}

START_TEST(ft_lstdel_test)
{
    printf("Testing ft_lstdel...");

    t_list *list_begin;
    t_list *list0;
    t_list *list1;
    t_list *list2;
    t_list *list3;

    list_begin = NULL;
    list0 = ft_lstnew(NULL, 0);
    list1 = ft_lstnew(NULL, 0);
    list2 = ft_lstnew(NULL, 0);
    list3 = ft_lstnew(NULL, 0);

    ft_lstadd(&list_begin, list0);
    ft_lstadd(&list_begin, list1);
    ft_lstadd(&list_begin, list2);
    ft_lstadd(&list_begin, list3);

    count = 0;

    ft_lstdel(&list_begin, NULL); // should not proceed

    ft_lstdel(&list_begin, &del_func_1);

    fail_unless(count == 4, "ft_lstat 1");
    fail_unless(list_begin == NULL, "ft_lstat 2");

    ft_lstdel(NULL, &del_func_1);

    printf(" done!\n");
}
END_TEST

START_TEST(ft_lstdelone_test)
{
    printf("Testing ft_lstdelone...");

    t_list *list;

    count = 0;
    list = ft_lstnew(NULL, 0);

    ft_lstdelone(&list, NULL); // should not crash or perform anything

    ft_lstdelone(&list, &del_func_1);
    fail_unless(list == NULL, "ft_lstdelone");
    fail_unless(count == 1, "ft_lstdelone");

    ft_lstdelone(NULL, &del_func_1);

    printf(" done!\n");
}
END_TEST

START_TEST(ft_isalpha_test)
{
    printf("Testing ft_isalpha...");
    test_for_each_ascii("isalpha", &ft_isalpha, &isalpha, 0);
    printf(" done!\n");
}
END_TEST

START_TEST(ft_isdigit_test)
{
    printf("Testing ft_isdigit...");
    test_for_each_ascii("isdigit", &ft_isdigit, &isdigit, 0);
    printf(" done!\n");
}
END_TEST

START_TEST(ft_isalnum_test)
{
    printf("Testing ft_isalnum...");
    test_for_each_ascii("isalnum", &ft_isalnum, &isalnum, 0);
    printf(" done!\n");
}
END_TEST

START_TEST(ft_isascii_test)
{
    printf("Testing ft_isascii...");
    test_for_each_ascii("isascii", &ft_isascii, &isascii, 0);
    printf(" done!\n");
}
END_TEST

START_TEST(ft_isprint_test)
{
    printf("Testing ft_isprint...");
    test_for_each_ascii("isprint", &ft_isprint, &isprint, 0);
    printf(" done!\n");
}
END_TEST

START_TEST(ft_toupper_test)
{
    printf("Testing ft_toupper...");
    test_for_each_ascii("toupper", &ft_toupper, &toupper, 1);
    printf(" done!\n");
}
END_TEST

START_TEST(ft_tolower_test)
{
    printf("Testing ft_tolower...");
    test_for_each_ascii("tolower", &ft_tolower, &tolower, 1);
    printf(" done!\n");
}
END_TEST

START_TEST(ft_strlen_test)
{
    printf("Testing ft_strcat...");

    fail_unless(ft_strlen(NULL) == 0, "ft_strlen(NULL)");
    fail_unless(ft_strlen("") == 0, "ft_strlen()");
    fail_unless(ft_strlen("a") == 1, "ft_strlen(a)");
    fail_unless(ft_strlen("aa") == 2, "ft_strlen(aa)");

    printf(" done!\n");
}
END_TEST

START_TEST(ft_strcat_test)
{
    printf("Testing ft_strcat...");

    char *s1 = "Hello";    
    char *s2 = ", ";
    char *s3 = "world";
    char *s4 = "!";
    char s5[50];
    char *ret;

    s5[0] = '\0';

    ret = ft_strcat(s5, s1);
    fail_unless(strcmp(s5, "Hello") == 0, "strcat 1");
    fail_unless(ret == s5, "strcat 2");

    ret = ft_strcat(s5, s2);
    fail_unless(strcmp(s5, "Hello, ") == 0, "strcat 3");
    fail_unless(ret == s5, "strcat 4");

    ret = ft_strcat(s5, s3);
    fail_unless(strcmp(s5, "Hello, world") == 0, "strcat 5");
    fail_unless(ret == s5, "strcat 6");

    ret = ft_strcat(s5, s4);
    fail_unless(strcmp(s5, "Hello, world!") == 0, "strcat 7");
    fail_unless(ret == s5, "strcat 8");

    ret = ft_strcat(s5, NULL);
    fail_unless(ret == NULL, "strcat 9");

    ret = ft_strcat(NULL, s5);
    fail_unless(ret == NULL, "strcat 10");

    ret = ft_strcat(NULL, NULL);
    fail_unless(ret == NULL, "strcat 11");

    printf(" done!\n");
}
END_TEST

START_TEST(ft_strdup_test)
{
    printf("Testing ft_strdup...");

    char *s1 = "Hello!";
    char *s2 = ft_strdup(s1);

    fail_unless(strcmp(s1, s2) == 0, "strdup 1");
    free(s2);

    s1 = "";
    s2 = ft_strdup(s1);
    fail_unless(strcmp(s1, s2) == 0, "strdup 2");
    free(s2);

    s2 = ft_strdup(NULL);
    fail_unless(s2 == NULL, "strdup 3");

    printf(" done!\n");
}
END_TEST

START_TEST(ft_bzero_test)
{
    printf("Testing ft_bzero...");

    char *s1 = "Hello!";
    char *s2 = strdup(s1);

    ft_bzero(s2, 0);
    fail_unless(strcmp(s1, s2) == 0, "bzero 1");

    ft_bzero(s2, strlen(s1)); 
    fail_unless(strcmp(s2, "") == 0, "bzero 2");

    free(s2);

    ft_bzero(NULL, 10);

    printf(" done!\n");
}
END_TEST

START_TEST(ft_memset_test)
{
    printf("Testing ft_memset...");

    char s1[10];
    char *s2;

    s1[9] = '\0';

    s2 = ft_memset(s1, 'a', 9);
    fail_unless(strcmp(s1, "aaaaaaaaa") == 0, "memset 1");
    fail_unless(s2 == s1, "memset 2");

    s2 = ft_memset(s1 + 1, 'b', 2);
    fail_unless(strcmp(s1, "abbaaaaaa") == 0, "memset 3");
    fail_unless(s2 == (s1 + 1), "memset 4");

    s2 = ft_memset(s1 + 4, 'c', 4);
    fail_unless(strcmp(s1, "abbacccca") == 0, "memset 5");
    fail_unless(s2 == (s1 + 4), "memset 6");

    s2 = ft_memset(s1, 'Z', 0);
    fail_unless(strcmp(s1, "abbacccca") == 0, "memset 7");
    fail_unless(s2 == s1, "memset 8");

    s2 = ft_memset(NULL, 'Z', 10);
    fail_unless(s2 == NULL, "memset 9");

    printf(" done!\n");
}
END_TEST

START_TEST(ft_memcpy_test)
{
    printf("Testing ft_memcpy...");

    char *s1 = "Hello!";
    char s2[10];
    char *s3;

    ft_memcpy(s2, s1, 7);
    fail_unless(strcmp(s1, s2) == 0, "memcpy 1");

    s1 = "";
    ft_memcpy(s2, s1, 1);
    fail_unless(strcmp(s1, s2) == 0, "memcpy 2");

    s1 = "Hello!";
    s3 = ft_memcpy(s2, s1, 7);
    fail_unless(strcmp(s1, s2) == 0, "memcpy 3");
    fail_unless(s3 == s2, "memcpy 4");

    s3 = ft_memcpy(NULL, s1, 7);
    fail_unless(s3 == NULL, "memcpy 5");

    s3 = ft_memcpy(s2, NULL, 7);
    fail_unless(s3 == NULL, "memcpy 6");

    printf(" done!\n");
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("libfts");
    TCase *tc1_1 = tcase_create("libfts");
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
 
    tcase_add_test(tc1_1, ft_lstnew_test);
    tcase_add_test(tc1_1, ft_lstadd_test);
    tcase_add_test(tc1_1, ft_lstaddback_test);
    tcase_add_test(tc1_1, ft_lstat_test);
    tcase_add_test(tc1_1, ft_lstdel_test);
    tcase_add_test(tc1_1, ft_lstdelone_test);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
