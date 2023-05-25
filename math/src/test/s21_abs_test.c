#include "s21_tests_suite.h"

START_TEST(test_01_s21_abs) {
    int x = 10;
    int s21_res = s21_abs(x), res = abs(x);

    ck_assert_int_eq(s21_res, res);
} END_TEST

START_TEST(test_02_s21_abs) {
    int x = -182;
    int s21_res = s21_abs(x), res = abs(x);

    ck_assert_int_eq(s21_res, res);
} END_TEST

START_TEST(test_03_s21_abs) {
    int x = 0xA13;
    int s21_res = s21_abs(x), res = abs(x);

    ck_assert_int_eq(s21_res, res);
} END_TEST

START_TEST(test_04_s21_abs) {
    int x = 126789;
    int s21_res = s21_abs(x), res = abs(x);

    ck_assert_int_eq(s21_res, res);
} END_TEST

START_TEST(test_05_s21_abs) {
    int x = -0.5;
    int s21_res = s21_abs(x), res = abs(x);

    ck_assert_int_eq(s21_res, res);
} END_TEST

START_TEST(test_06_s21_abs) {
    int x = -2147123145;
    int s21_res = s21_abs(x), res = abs(x);

    ck_assert_int_eq(s21_res, res);
} END_TEST

Suite * s21_abs_suite(void) {
    Suite * suite = suite_create("group of abs test's");

    TCase * tc_insert = tcase_create("abs_test");

    tcase_add_test(tc_insert, test_01_s21_abs);
    tcase_add_test(tc_insert, test_02_s21_abs);
    tcase_add_test(tc_insert, test_03_s21_abs);
    tcase_add_test(tc_insert, test_04_s21_abs);
    tcase_add_test(tc_insert, test_05_s21_abs);
    tcase_add_test(tc_insert, test_06_s21_abs);

    suite_add_tcase(suite, tc_insert);

    return suite;
}
