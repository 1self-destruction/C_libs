#include "s21_tests_suite.h"

START_TEST(test_01_s21_sin) {
    double x = 2.3;
    ck_assert_double_eq_tol(s21_sin(x), sin(x), 1e-6);
} END_TEST

START_TEST(test_02_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(0.0), sin(0), 1e-6);
} END_TEST

START_TEST(test_03_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(1), sin(1), 1e-6);
} END_TEST

START_TEST(test_04_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(-1), sin(-1), 1e-6);
} END_TEST

START_TEST(test_05_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(0.234234123), sin(0.234234123), 1e-6);
} END_TEST

START_TEST(test_06_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(-0.99999), sin(-0.99999), 1e-6);
} END_TEST

START_TEST(test_07_s21_sin) {
    ck_assert_ldouble_nan(s21_sin(NAN));
    ck_assert_ldouble_nan(sin(NAN));
} END_TEST

START_TEST(test_08_s21_sin) {
    ck_assert_ldouble_nan(s21_sin(INFINITY));
    ck_assert_ldouble_nan(sin(INFINITY));
} END_TEST

START_TEST(test_09_s21_sin) {
    ck_assert_ldouble_nan(s21_sin(-INFINITY));
    ck_assert_ldouble_nan(sin(-INFINITY));
} END_TEST

START_TEST(test_10_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(S21_PI / 6), sin(S21_PI / 6), 1e-06);
} END_TEST

START_TEST(test_11_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(S21_PI / 4), sin(S21_PI / 4), 1e-06);
} END_TEST

START_TEST(test_12_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(S21_PI / 3), sin(S21_PI / 3), 1e-06);
} END_TEST

START_TEST(test_13_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(S21_PI / 2), sin(S21_PI / 2), 1e-06);
} END_TEST

START_TEST(test_14_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(3 * S21_PI / 2), sin(3 * S21_PI / 2), 1e-06);
} END_TEST

START_TEST(test_15_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(2 * S21_PI), sin(2 * S21_PI), 1e-06);
} END_TEST

START_TEST(test_16_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(-2 * S21_PI), sin(-2 * S21_PI), 1e-06);
} END_TEST

START_TEST(test_17_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(-3 * S21_PI), sin(-3 * S21_PI), 1e-06);
} END_TEST

START_TEST(test_18_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(324.532925199433), sin(324.532925199433), 1e-06);
} END_TEST

START_TEST(test_19_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(-333.532925199433), sin(-333.532925199433), 1e-06);
} END_TEST

START_TEST(test_20_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(-S21_PI), sin(-S21_PI), 1e-06);
} END_TEST

START_TEST(test_21_s21_sin) {
    ck_assert_double_eq_tol(s21_sin(30 * S21_PI), sin(30 * S21_PI), 1e-06);
} END_TEST


Suite * s21_sin_suite(void) {
    Suite * suite = suite_create("group of sin tests");

    // <INSERT>
    TCase * tc_insert = tcase_create("sin_tests");

    tcase_add_test(tc_insert, test_01_s21_sin);
    tcase_add_test(tc_insert, test_02_s21_sin);
    tcase_add_test(tc_insert, test_03_s21_sin);
    tcase_add_test(tc_insert, test_04_s21_sin);
    tcase_add_test(tc_insert, test_05_s21_sin);
    tcase_add_test(tc_insert, test_06_s21_sin);
    tcase_add_test(tc_insert, test_07_s21_sin);
    tcase_add_test(tc_insert, test_08_s21_sin);
    tcase_add_test(tc_insert, test_09_s21_sin);
    tcase_add_test(tc_insert, test_10_s21_sin);
    tcase_add_test(tc_insert, test_11_s21_sin);
    tcase_add_test(tc_insert, test_12_s21_sin);
    tcase_add_test(tc_insert, test_13_s21_sin);
    tcase_add_test(tc_insert, test_14_s21_sin);
    tcase_add_test(tc_insert, test_15_s21_sin);
    tcase_add_test(tc_insert, test_16_s21_sin);
    tcase_add_test(tc_insert, test_17_s21_sin);
    tcase_add_test(tc_insert, test_18_s21_sin);
    tcase_add_test(tc_insert, test_19_s21_sin);
    tcase_add_test(tc_insert, test_20_s21_sin);
    tcase_add_test(tc_insert, test_21_s21_sin);

    suite_add_tcase(suite, tc_insert);

    return suite;
}
