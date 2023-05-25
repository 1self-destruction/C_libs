#include "s21_tests_suite.h"

START_TEST(test_01_s21_cos) {
    double x = 4 * S21_PI;
    long double s21_res = s21_cos(x), res = cos(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_02_s21_cos) {
    double x = 0;
    long double s21_res = s21_cos(x), res = cos(x);

    ck_assert_double_eq(s21_res, res);
} END_TEST

START_TEST(test_03_s21_cos) {
    double x = 1/(2*S21_PI);
    long double s21_res = s21_cos(x), res = cos(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_04_s21_cos) {
    double x = -0.99999;
    long double s21_res = s21_cos(x), res = cos(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_05_s21_cos) {
    double x = 0.99999;
    long double s21_res = s21_cos(x), res = cos(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_06_s21_cos) {
    double x = NAN;
    long double s21_res = s21_cos(x), res = cos(x);
    int suc = 0;

    if (isnan(s21_res) && isnan(res))
        suc = 1;

    ck_assert_int_eq(1, suc);
} END_TEST

START_TEST(test_07_s21_cos) {
    double x = INFINITY;
    long double s21_res = s21_cos(x), res = cos(x);
    int suc = 0;

    if (isnan(s21_res) && isnan(res))
        suc = 1;

    ck_assert_int_eq(1, suc);
} END_TEST

START_TEST(test_08_s21_cos) {
    double x = S21_PI;
    long double s21_res = s21_cos(x), res = cos(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_09_s21_cos) {
    double x = -S21_PI;
    long double s21_res = s21_cos(x), res = cos(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_10_s21_cos) {
    double x = 2*S21_PI;
    long double s21_res = s21_cos(x), res = cos(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_11_s21_cos) {
    double x = -2*S21_PI;
    long double s21_res = s21_cos(x), res = cos(x);

    ck_assert_double_eq_tol(s21_res, res, S21_EPS);
} END_TEST

START_TEST(test_12_s21_cos) {
    double x = -INFINITY;
    long double s21_res = s21_cos(x), res = cos(x);
    int suc = 0;

    if (isnan(s21_res) && isnan(res))
        suc = 1;

    ck_assert_int_eq(1, suc);
} END_TEST

START_TEST(test_13_s21_cos) {
    double x = 4.88692191;
    ck_assert_double_eq_tol(s21_cos(x), cos(x), S21_EPS);
} END_TEST

START_TEST(test_14_s21_cos) {
    double x = -174.532925199433;
    ck_assert_double_eq_tol(s21_cos(x), cos(x), S21_EPS);
} END_TEST

Suite * s21_cos_suite(void) {
    Suite * suite = suite_create("group of cos tests");

    TCase *tc_insert = tcase_create("cos_tests");

    tcase_add_test(tc_insert, test_01_s21_cos);
    tcase_add_test(tc_insert, test_02_s21_cos);
    tcase_add_test(tc_insert, test_03_s21_cos);
    tcase_add_test(tc_insert, test_04_s21_cos);
    tcase_add_test(tc_insert, test_05_s21_cos);
    tcase_add_test(tc_insert, test_06_s21_cos);
    tcase_add_test(tc_insert, test_07_s21_cos);
    tcase_add_test(tc_insert, test_08_s21_cos);
    tcase_add_test(tc_insert, test_09_s21_cos);
    tcase_add_test(tc_insert, test_10_s21_cos);
    tcase_add_test(tc_insert, test_11_s21_cos);
    tcase_add_test(tc_insert, test_12_s21_cos);
    tcase_add_test(tc_insert, test_13_s21_cos);
    tcase_add_test(tc_insert, test_14_s21_cos);

    suite_add_tcase(suite, tc_insert);

    return suite;
}
