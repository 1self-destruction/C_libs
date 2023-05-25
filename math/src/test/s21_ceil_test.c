#include "s21_tests_suite.h"

START_TEST(test_01_s21_ceil) {
    double x = 15.01;
    double s21_res = s21_ceil(x), res = ceil(x);

    ck_assert_double_eq(s21_res, res);
} END_TEST

START_TEST(test_02_s21_ceil) {
    double x = -15.01;
    double s21_res = s21_ceil(x), res = ceil(x);

    ck_assert_double_eq(s21_res, res);
} END_TEST

START_TEST(test_03_s21_ceil) {
    double x = 0.01;
    double s21_res = s21_ceil(x), res = ceil(x);

    ck_assert_double_eq(s21_res, res);
} END_TEST

START_TEST(test_04_s21_ceil) {
    double x = S21_DBL_MAX;
    double s21_res = s21_ceil(x), res = ceil(x);

    ck_assert_double_eq(s21_res, res);
} END_TEST

START_TEST(test_05_s21_ceil) {
    double x = 1;
    double s21_res = s21_ceil(x), res = ceil(x);

    ck_assert_double_eq(s21_res, res);
} END_TEST

START_TEST(test_06_s21_ceil) {
    double x = 0;
    double s21_res = s21_ceil(x), res = ceil(x);

    ck_assert_double_eq(s21_res, res);
} END_TEST


Suite * s21_ceil_suite(void) {
    Suite * suite = suite_create("group of ceil test's");

    TCase *tc_insert = tcase_create("ceil_tests");

    tcase_add_test(tc_insert, test_01_s21_ceil);
    tcase_add_test(tc_insert, test_02_s21_ceil);
    tcase_add_test(tc_insert, test_03_s21_ceil);
    tcase_add_test(tc_insert, test_04_s21_ceil);
    tcase_add_test(tc_insert, test_05_s21_ceil);
    tcase_add_test(tc_insert, test_06_s21_ceil);

    suite_add_tcase(suite, tc_insert);

    return suite;
}
