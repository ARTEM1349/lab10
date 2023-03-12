#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <check.h>

START_TEST(test_lab05)
{
        int test_a = 1;
        int test_n = 1;
        int test_i = 200;
        int test_result = 2000;
        int actual_result = lab05(test_a,test_n);
  
        ck_assert_int_eq(test_result, actual_result);
				
}
END_TEST

START_TEST(test_lab06)
{
        int i ,j,c;
        int s = 6;
       long int expected[5]= {24,342,345,234,545,678};
         int actual = lab06(i,j,c); 
         ck_assert_int_eq(actual, expected[5]);
}
END_TEST
Suite *lab_test_suite(void)
{
    Suite *s;
    TCase *tc_core;
    
    s = suite_create("lab09");
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_lab05);
    tcase_add_test(tc_core, test_lab06);
    suite_add_tcase(s, tc_core);
    
    return s;
}

int main(void)
{
    
    int number_failed;
    Suite *s;
    SRunner *sr;
    
    s = lab_test_suite();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

}
