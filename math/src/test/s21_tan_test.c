#include "s21_tests_suite.h"
#include <stdlib.h>

START_TEST(test_01_s21_tan) {
    ck_assert_float_eq(s21_tan(-15.01), tan(-15.01));
} END_TEST

START_TEST(test_02_s21_tan) {
    double x = 0.55;
    ck_assert_double_eq_tol(s21_tan(x), tan(x), 1e-06);
} END_TEST

START_TEST(test_03_s21_tan) {
    double x = 0;
    ck_assert_double_eq_tol(s21_tan(x), tan(x), 1e-06);
} END_TEST

START_TEST(test_04_s21_tan) {
    ck_assert_ldouble_nan(s21_tan(-INFINITY));
    ck_assert_ldouble_nan(tan(-INFINITY));
} END_TEST

START_TEST(test_05_s21_tan) {
  ck_assert_ldouble_nan(s21_tan(INFINITY));
  ck_assert_ldouble_nan(tan(INFINITY));
} END_TEST

START_TEST(test_06_s21_tan) {
  ck_assert_ldouble_nan(s21_tan(NAN));
  ck_assert_ldouble_nan(tan(NAN));
} END_TEST

START_TEST(test_07_s21_tan) {
    ck_assert_double_eq_tol(s21_tan(0.0), tan(0.0), 1e-06);
} END_TEST

START_TEST(test_08_s21_tan) {
    ck_assert_double_eq_tol(s21_tan(S21_PI / 6), tan(S21_PI / 6), 1e-06);
} END_TEST

START_TEST(test_09_s21_tan) {
    ck_assert_double_eq_tol(s21_tan(S21_PI / 4), tan(S21_PI / 4), 1e-06);
} END_TEST

START_TEST(test_10_s21_tan) {
    ck_assert_double_eq_tol(s21_tan(-2 * S21_PI), tan(-2 * S21_PI), 1e-06);
} END_TEST

START_TEST(test_11_s21_tan) {
    ck_assert_double_eq_tol(s21_tan(S21_PI), tan(S21_PI), 1e-06);
} END_TEST

START_TEST(test_12_s21_tan) {
    ck_assert_double_eq_tol(s21_tan(S21_PI / 3), tan(S21_PI / 3), 1e-06);
} END_TEST

START_TEST(test_13_s21_tan) {
    ck_assert_double_eq_tol(s21_tan(3 * S21_PI / 3), tan(3 * S21_PI / 3), 1e-06);
} END_TEST

START_TEST(test_14_s21_tan) {
    ck_assert_double_eq_tol(s21_tan(4.88692191), tan(4.88692191), 1e-06);
} END_TEST

START_TEST(test_15_s21_tan) {
    ck_assert_double_eq_tol(s21_tan(-174.532925199433), tan(-174.532925199433),
                          1e-06);
} END_TEST

START_TEST(test_16_s21_tan) {
    ck_assert_double_eq_tol(s21_tan(S21_PI / 2), tan(S21_PI / 2), 1e-06);
} END_TEST

START_TEST(test_17_s21_tan) {
    ck_assert_double_eq_tol(s21_tan(-S21_PI / 2), tan(-S21_PI / 2), 1e-06);
} END_TEST

START_TEST(test_18_s21_tan) {
    ck_assert_double_eq_tol(s21_tan(0), tan(0), 1e-06);
} END_TEST



Suite * s21_tan_suite(void) {
    Suite * suite = suite_create("group of tan tests");

    // <INSERT>
    TCase * tc_insert = tcase_create("tan_tests");

    tcase_add_test(tc_insert, test_01_s21_tan);
    tcase_add_test(tc_insert, test_02_s21_tan);
    tcase_add_test(tc_insert, test_03_s21_tan);
    tcase_add_test(tc_insert, test_04_s21_tan);
    tcase_add_test(tc_insert, test_05_s21_tan);
    tcase_add_test(tc_insert, test_06_s21_tan);
    tcase_add_test(tc_insert, test_07_s21_tan);
    tcase_add_test(tc_insert, test_08_s21_tan);
    tcase_add_test(tc_insert, test_09_s21_tan);
    tcase_add_test(tc_insert, test_10_s21_tan);
    tcase_add_test(tc_insert, test_11_s21_tan);
    tcase_add_test(tc_insert, test_12_s21_tan);
    tcase_add_test(tc_insert, test_13_s21_tan);
    tcase_add_test(tc_insert, test_14_s21_tan);
    tcase_add_test(tc_insert, test_15_s21_tan);
    tcase_add_test(tc_insert, test_16_s21_tan);
    tcase_add_test(tc_insert, test_17_s21_tan);
    tcase_add_test(tc_insert, test_18_s21_tan);

    suite_add_tcase(suite, tc_insert);

    return suite;
}
