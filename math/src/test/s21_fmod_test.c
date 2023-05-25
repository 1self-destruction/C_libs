#include "s21_tests_suite.h"

START_TEST(test_01_s21_fmod) {
    double x = 0, y = 2;
    long double s21_res = s21_fmod(x, y), res = fmod(x, y);

    ck_assert_ldouble_eq(s21_res, res);
} END_TEST

START_TEST(test_02_s21_fmod) {
    double x = 1.1, y = 2;
    long double s21_res = s21_fmod(x, y), res = fmod(x, y);

    ck_assert_ldouble_eq(s21_res, res);
} END_TEST

START_TEST(test_03_s21_fmod) {
    double x = -1.1, y = 0.5;
    long double s21_res = s21_fmod(x, y), res = fmod(x, y);

    ck_assert_ldouble_eq(s21_res, res);
} END_TEST

START_TEST(test_04_s21_fmod) {
    double x = 11, y = 2;
    long double s21_res = s21_fmod(x, y), res = fmod(x, y);

    ck_assert_ldouble_eq(s21_res, res);
} END_TEST

START_TEST(test_05_s21_fmod) {
    int ret = 0;
    double x = NAN, y = 2;
    long double s21_res = s21_fmod(x, y), res = fmod(x, y);

    if (isnan(res) == isnan(s21_res)) ret = 1;

    ck_assert_int_eq(1, ret);
} END_TEST

START_TEST(test_06_s21_fmod) {
    int ret = 0;
    double x = 11.11, y = NAN;
    long double s21_res = s21_fmod(x, y), res = fmod(x, y);

    if (isnan(res) == isnan(s21_res)) ret = 1;

    ck_assert_int_eq(1, ret);
} END_TEST

START_TEST(test_07_s21_fmod) {
    int ret = 0;
    double x = INFINITY, y = 2;
    long double s21_res = s21_fmod(x, y), res = fmod(x, y);

    if (isnan(res) == isnan(s21_res)) ret = 1;

    ck_assert_int_eq(1, ret);
} END_TEST

START_TEST(test_08_s21_fmod) {
    int ret = 0;
    double x = 2, y = 0;
    long double s21_res = s21_fmod(x, y), res = fmod(x, y);

    if (isnan(res) == isnan(s21_res)) ret = 1;

    ck_assert_int_eq(1, ret);
} END_TEST

Suite * s21_fmod_suite(void) {
    Suite * suite = suite_create("group of fmod tests");

    TCase *tc_insert = tcase_create("fmod_tests");

    tcase_add_test(tc_insert, test_01_s21_fmod);
    tcase_add_test(tc_insert, test_02_s21_fmod);
    tcase_add_test(tc_insert, test_03_s21_fmod);
    tcase_add_test(tc_insert, test_04_s21_fmod);
    tcase_add_test(tc_insert, test_05_s21_fmod);
    tcase_add_test(tc_insert, test_06_s21_fmod);
    tcase_add_test(tc_insert, test_07_s21_fmod);
    tcase_add_test(tc_insert, test_08_s21_fmod);

    suite_add_tcase(suite, tc_insert);

    return suite;
}
