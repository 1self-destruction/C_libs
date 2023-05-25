#include "s21_tests_suite.h"

START_TEST(test_01_s21_floor) {
    double x = 0;
    long double s21_res = s21_floor(x), res = floor(x);

    ck_assert_ldouble_eq(s21_res, res);
} END_TEST

START_TEST(test_02_s21_floor) {
    double x = 1.1;
    long double s21_res = s21_floor(x), res = floor(x);

    ck_assert_ldouble_eq(s21_res, res);
} END_TEST

START_TEST(test_03_s21_floor) {
    double x = -1.1;
    long double s21_res = s21_floor(x), res = floor(x);

    ck_assert_ldouble_eq(s21_res, res);
} END_TEST

START_TEST(test_04_s21_floor) {
    double x = 1e+16;
    long double s21_res = s21_floor(x), res = floor(x);

    ck_assert_ldouble_eq(s21_res, res);
} END_TEST

START_TEST(test_05_s21_floor) {
    ck_assert_ldouble_infinite(s21_floor(INFINITY));
    ck_assert_ldouble_infinite(floor(INFINITY));
} END_TEST

START_TEST(test_06_s21_floor) {
    ck_assert_ldouble_nan(s21_floor(NAN));
    ck_assert_ldouble_nan(floor(NAN));
} END_TEST

START_TEST(test_07_s21_floor) {
    double x = 8743517471375.4134143134134134;
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
}

Suite * s21_floor_suite(void) {
    Suite * suite = suite_create("group of floor tests");

    TCase *tc_insert = tcase_create("floor_tests");

    tcase_add_test(tc_insert, test_01_s21_floor);
    tcase_add_test(tc_insert, test_02_s21_floor);
    tcase_add_test(tc_insert, test_03_s21_floor);
    tcase_add_test(tc_insert, test_04_s21_floor);
    tcase_add_test(tc_insert, test_05_s21_floor);
    tcase_add_test(tc_insert, test_06_s21_floor);
    tcase_add_test(tc_insert, test_07_s21_floor);
    suite_add_tcase(suite, tc_insert);

    return suite;
}
