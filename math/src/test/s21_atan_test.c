#include "s21_tests_suite.h"

START_TEST(test_01_s21_atan) {
    int x = 0;
    int s21_res = s21_atan(x), res = atan(x);

    ck_assert_int_eq(s21_res, res);
} END_TEST

START_TEST(test_02_s21_atan) {
    int x = -182;
    int s21_res = s21_atan(x), res = atan(x);

    ck_assert_int_eq(s21_res, res);
} END_TEST

START_TEST(test_03_s21_atan) {
    int x = 10;
    int s21_res = s21_atan(x), res = atan(x);

    ck_assert_int_eq(s21_res, res);
} END_TEST

START_TEST(test_04_s21_atan) {
    int x = 0xA13;
    int s21_res = s21_atan(x), res = atan(x);

    ck_assert_int_eq(s21_res, res);
} END_TEST

Suite * s21_atan_suite(void) {
    Suite * suite = suite_create("group of atan test's");

    TCase * tc_insert = tcase_create("atan_test");

    tcase_add_test(tc_insert, test_01_s21_atan);
    tcase_add_test(tc_insert, test_02_s21_atan);
    tcase_add_test(tc_insert, test_03_s21_atan);
    tcase_add_test(tc_insert, test_04_s21_atan);

    suite_add_tcase(suite, tc_insert);

    return suite;
}
