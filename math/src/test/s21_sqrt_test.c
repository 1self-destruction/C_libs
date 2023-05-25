#include "s21_tests_suite.h"
#include <stdlib.h>

START_TEST(test_01_s21_sqrt) {
    ck_assert_ldouble_infinite(s21_sqrt(INFINITY));
    ck_assert_ldouble_infinite(sqrt(INFINITY));
} END_TEST

START_TEST(test_02_s21_sqrt) {
    ck_assert_ldouble_nan(s21_sqrt(-INFINITY));
    ck_assert_ldouble_nan(sqrt(-INFINITY));
} END_TEST

START_TEST(test_03_s21_sqrt) {
    ck_assert_ldouble_nan(s21_sqrt(-15));
    ck_assert_ldouble_nan(sqrt(-15));
} END_TEST

START_TEST(test_04_s21_sqrt) {
    ck_assert_ldouble_eq_tol(s21_sqrt(0.2342), sqrt(0.2342), 1e-6);
} END_TEST

START_TEST(test_05_s21_sqrt) {
    ck_assert_ldouble_nan(s21_sqrt(NAN));
    ck_assert_ldouble_nan(sqrt(NAN));
} END_TEST

START_TEST(test_06_s21_sqrt) {
    ck_assert_ldouble_eq_tol(s21_sqrt(1.0), sqrt(1.0), 1e-6);
} END_TEST

START_TEST(test_07_s21_sqrt) {
    ck_assert_ldouble_eq_tol(s21_sqrt(0.0), sqrt(0.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sqrt(-0.0), sqrt(-0.0), 1e-6);
} END_TEST

START_TEST(test_08_s21_sqrt) {
    ck_assert_ldouble_eq_tol(s21_sqrt(10e+32), sqrt(10e+32), 1e-6);
} END_TEST

START_TEST(test_09_s21_sqrt) {
    ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-6);
} END_TEST

START_TEST(test_10_s21_sqrt) {
    ck_assert_ldouble_eq_tol(s21_sqrt(100), sqrt(100), 1e-6);
} END_TEST

START_TEST(test_11_s21_sqrt) {
    ck_assert_ldouble_eq_tol(s21_sqrt(342423.4234), sqrt(342423.4234), 1e-6);
} END_TEST

START_TEST(test_12_s21_sqrt) {
    ck_assert_ldouble_eq_tol(s21_sqrt(981.123e-15), sqrt(981.123e-15), 1e-6);
} END_TEST

Suite * s21_sqrt_suite(void) {
    Suite * suite = suite_create("group of sqrt tests");

    // <INSERT>
    TCase * tc_insert = tcase_create("sqrt_tests");

    tcase_add_test(tc_insert, test_01_s21_sqrt);
    tcase_add_test(tc_insert, test_02_s21_sqrt);
    tcase_add_test(tc_insert, test_03_s21_sqrt);
    tcase_add_test(tc_insert, test_04_s21_sqrt);
    tcase_add_test(tc_insert, test_05_s21_sqrt);
    tcase_add_test(tc_insert, test_06_s21_sqrt);
    tcase_add_test(tc_insert, test_07_s21_sqrt);
    tcase_add_test(tc_insert, test_08_s21_sqrt);
    tcase_add_test(tc_insert, test_09_s21_sqrt);
    tcase_add_test(tc_insert, test_10_s21_sqrt);
    tcase_add_test(tc_insert, test_11_s21_sqrt);
    tcase_add_test(tc_insert, test_12_s21_sqrt);
    suite_add_tcase(suite, tc_insert);

    return suite;
}
