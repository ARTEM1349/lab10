#include ".../src/lib.h"
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
        int i;
        int s = 6;
        for(i=0; i<s-1;i++){
          int actual = lab06(i);
         ck_assert_int_eq(actual,expected); 
          }
}
  
END_TEST  
  
START_TEST(test_lab06_1)
{
       int j;
       int s=6;
        for ( j  =0;j<s-i-1;j++){
        int actual = lab06(j);
         ck_assert_int_eq(actual,expected); 
        }
 }
END_TEST  
        
  START_TEST(test_lab06_2)
{
         int j;
       long int b expected[5]= {24,342,345,234,545,678};
          if (b[j] > b[j+1]){
            int actual = lab06(b[j,b[j]]+1);
         ck_assert_int_eq(actual, expected[5]);
          }
}
END_TEST

Suite *lab_test_suite(void)
{
    Suite *s;
    TCase *tc_TCase *tc_lab05;;
    TCase *tc_lab06;
    
    s = suite_create("lab09");
  
    tc_lab05; = tcase_create("lab_05");
    
    tcase_add_test(tc_clab05, test_lab05);
 
    tc_lab06; = tcase_create("lab_06");
  
    tcase_add_test(tc_lab06, test_lab06);
	  tcase_add_test(tc_lab06, test_lab06_1);
	  tcase_add_test(tc_lab06, test_lab06_2);
   
  
	 suite_add_tcase(s, tc_lab05);
	 suite_add_tcase(s, tc_lab06);
    
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
