#include "s21_tests_suite.h"

START_TEST(test_01_s21_exp) {
    double x = 0;
    long double s21_res = s21_exp(x), res = exp(x);

    ck_assert_ldouble_eq(s21_res, res);
} END_TEST

START_TEST(test_02_s21_exp) {
    double x = 1;
    long double s21_res = s21_exp(x), res = exp(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_03_s21_exp) {
    double x = -S21_EPS;
    long double s21_res = s21_exp(x), res = exp(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_04_s21_exp) {
    double x = S21_EPS;
    long double s21_res = s21_exp(x), res = exp(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_05_s21_exp) {
    double x = 1.11231;
    long double s21_res = s21_exp(x), res = exp(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_06_s21_exp) {
    double x = -1.15413;
    long double s21_res = s21_exp(x), res = exp(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_07_s21_exp) {
    double x = -1;
    long double s21_res = s21_exp(x), res = exp(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST


START_TEST(test_08_s21_exp) {
    double x = -10;
    long double s21_res = s21_exp(x), res = exp(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_09_s21_exp) {
    double x = 11;
    long double s21_res = s21_exp(x), res = exp(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_10_s21_exp) {
    double x = 1101010101010;
    long double s21_res = s21_exp(x), res = exp(x);
    int suc = 0;

    if (isinf(s21_res) && isinf(res))
        suc = 1;

    ck_assert_int_eq(1, suc);
}

START_TEST(test_11_s21_exp) {
    double x = DBL_MAX;
    long double s21_res = s21_exp(x), res = exp(x);
    int suc = 0;

    if (isinf(s21_res) && isinf(res))
        suc = 1;

    ck_assert_int_eq(1, suc);
} END_TEST

START_TEST(test_12_s21_exp) {
    double x = -1101010101010;
    long double s21_res = s21_exp(x), res = exp(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

Suite * s21_exp_suite(void) {
    Suite * suite = suite_create("group of exp tests");

    TCase * tc_insert = tcase_create("exp_tests");

    tcase_add_test(tc_insert, test_01_s21_exp);
    tcase_add_test(tc_insert, test_02_s21_exp);
    tcase_add_test(tc_insert, test_03_s21_exp);
    tcase_add_test(tc_insert, test_04_s21_exp);
    tcase_add_test(tc_insert, test_05_s21_exp);
    tcase_add_test(tc_insert, test_06_s21_exp);
    tcase_add_test(tc_insert, test_07_s21_exp);
    tcase_add_test(tc_insert, test_08_s21_exp);
    tcase_add_test(tc_insert, test_09_s21_exp);
    tcase_add_test(tc_insert, test_10_s21_exp);
    tcase_add_test(tc_insert, test_11_s21_exp);
    tcase_add_test(tc_insert, test_12_s21_exp);
    suite_add_tcase(suite, tc_insert);

    return suite;
}
