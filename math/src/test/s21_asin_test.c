#include "s21_tests_suite.h"

START_TEST(test_01_s21_asin) {
    double x = 0.55;
    long double s21_res = s21_asin(x), res = asin(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_02_s21_asin) {
    double x = -0.98;
    long double s21_res = s21_asin(x), res = asin(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_03_s21_asin) {
    double x = -1;
    long double s21_res = s21_asin(x), res = asin(x);

    ck_assert_ldouble_eq(s21_res, res);
} END_TEST

START_TEST(test_04_s21_asin) {
    double x = 1;
    long double s21_res = s21_asin(x), res = asin(x);

    ck_assert_ldouble_eq(s21_res, res);
} END_TEST

START_TEST(test_05_s21_asin) {
    double x = 0;
    long double s21_res = s21_asin(x), res = asin(x);

    ck_assert_ldouble_eq(s21_res, res);
} END_TEST

START_TEST(test_06_s21_asin) {
    double x = 0.7071067811865475244;
    long double s21_res = s21_asin(x), res = asin(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_07_s21_asin) {
    double x = -0.7071067811865475244;
    long double s21_res = s21_asin(x), res = asin(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_08_s21_asin) {
    int ret = 0;
    double x = -1.1;
    long double s21_res = s21_asin(x), res = asin(x);

    if (isnan(res) == isnan(s21_res)) ret = 1;

    ck_assert_int_eq(1, ret);
} END_TEST

START_TEST(test_09_s21_asin) {
    int ret = 0;
    double x = 1.1;
    long double s21_res = s21_asin(x), res = asin(x);

    if (isnan(res) == isnan(s21_res)) ret = 1;

    ck_assert_int_eq(1, ret);
} END_TEST

Suite * s21_asin_suite(void) {
    Suite * suite = suite_create("group of asin test's");

    TCase *tc_insert = tcase_create("asin_tests");

    tcase_add_test(tc_insert, test_01_s21_asin);
    tcase_add_test(tc_insert, test_02_s21_asin);
    tcase_add_test(tc_insert, test_03_s21_asin);
    tcase_add_test(tc_insert, test_04_s21_asin);
    tcase_add_test(tc_insert, test_05_s21_asin);
    tcase_add_test(tc_insert, test_06_s21_asin);
    tcase_add_test(tc_insert, test_07_s21_asin);
    tcase_add_test(tc_insert, test_08_s21_asin);
    tcase_add_test(tc_insert, test_09_s21_asin);

    suite_add_tcase(suite, tc_insert);

    return suite;
}
