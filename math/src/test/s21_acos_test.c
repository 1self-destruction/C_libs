#include "s21_tests_suite.h"

START_TEST(test_01_s21_acos) {
    long double x = 0.7071067811865475244;
    long double res = acos(x), s21_res = s21_acos(x);

    ck_assert_ldouble_eq(res, s21_res);
} END_TEST

START_TEST(test_02_s21_acos) {
    int ret = 0;
    double x = 1.2;
    long double res = acos(x), s21_res = s21_acos(x);

    if (isnan(res) == isnan(s21_res)) ret = 1;

    ck_assert_int_eq(1, ret);
} END_TEST

START_TEST(test_03_s21_acos) {
    int ret = 0;
    double x = -1.2;
    long double res = acos(x), s21_res = s21_acos(x);

    if (isnan(res) == isnan(s21_res)) ret = 1;

    ck_assert_int_eq(1, ret);
} END_TEST

START_TEST(test_04_s21_acos) {
    double x = -0.12;
    long double res = acos(x), s21_res = s21_acos(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_05_s21_acos) {
    double x = 0.43;
    long double res = acos(x), s21_res = s21_acos(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_06_s21_acos) {
    long double x = 1.;
    long double res = acos(x), s21_res = s21_acos(x);

    ck_assert_ldouble_eq(res, s21_res);
} END_TEST

START_TEST(test_07_s21_acos) {
    long double x = -1.;
    long double res = acos(x), s21_res = s21_acos(x);

    ck_assert_ldouble_eq(res, s21_res);
} END_TEST

START_TEST(test_08_s21_acos) {
    long double x = 0;
    long double res = acos(x), s21_res = s21_acos(x);

    ck_assert_ldouble_eq(res, s21_res);
} END_TEST

START_TEST(test_09_s21_acos) {
    long double x = -0.7071067811865475244;
    long double res = acos(x), s21_res = s21_acos(x);

    ck_assert_ldouble_eq(res, s21_res);
} END_TEST

Suite * s21_acos_suite(void) {
    Suite * suite = suite_create("group of acos tests");

    TCase *tc_insert = tcase_create("acos_tests");

    tcase_add_test(tc_insert, test_01_s21_acos);
    tcase_add_test(tc_insert, test_02_s21_acos);
    tcase_add_test(tc_insert, test_03_s21_acos);
    tcase_add_test(tc_insert, test_04_s21_acos);
    tcase_add_test(tc_insert, test_05_s21_acos);
    tcase_add_test(tc_insert, test_06_s21_acos);
    tcase_add_test(tc_insert, test_07_s21_acos);
    tcase_add_test(tc_insert, test_08_s21_acos);
    tcase_add_test(tc_insert, test_09_s21_acos);

    suite_add_tcase(suite, tc_insert);

    return suite;
}
