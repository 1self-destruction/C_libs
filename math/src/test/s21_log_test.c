#include "s21_tests_suite.h"

START_TEST(test_01_s21_log) {
    ck_assert_ldouble_eq_tol(log(63.125), s21_log(63.125), 1e-6);
} END_TEST

START_TEST(test_02_s21_log) {
    ck_assert_ldouble_nan(log(NAN));
    ck_assert_ldouble_nan(s21_log(NAN));
} END_TEST

START_TEST(test_03_s21_log) {
    ck_assert_ldouble_eq_tol(log(0.001), s21_log(0.001), 1e-6);
} END_TEST

START_TEST(test_04_s21_log) {
    ck_assert_ldouble_eq_tol(log(0.1), s21_log(0.1), 1e-6);
} END_TEST

START_TEST(test_05_s21_log) {
    ck_assert_ldouble_nan(log(-INFINITY));
    ck_assert_ldouble_nan(s21_log(-INFINITY));
} END_TEST

START_TEST(test_06_s21_log) {
  ck_assert_ldouble_infinite(log(INFINITY));
    ck_assert_ldouble_infinite(s21_log(INFINITY));
} END_TEST

START_TEST(test_07_s21_log) {
    ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), 1e-6);
} END_TEST

START_TEST(test_08_s21_log) {
    ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), 1e-6);
} END_TEST

START_TEST(test_09_s21_log) {
    ck_assert_ldouble_eq_tol(s21_log(10000), log(10000), 1e-6);
} END_TEST

START_TEST(test_10_s21_log) {
    ck_assert_ldouble_eq_tol(s21_log(DBL_MAX), log(DBL_MAX), 1e-6);
} END_TEST

START_TEST(test_11_s21_log) {
    ck_assert_ldouble_eq_tol(s21_log(S21_PI / 3), log(S21_PI / 3), 1e-6);
} END_TEST

START_TEST(test_12_s21_log) {
    ck_assert_ldouble_eq_tol(s21_log(9.234578353457e-6), log(9.234578353457e-6), 1e-6);
} END_TEST

START_TEST(test_13_s21_log) {
    ck_assert_ldouble_eq_tol(s21_log(9.234578353457e6), log(9.234578353457e6), 1e-6);
} END_TEST

START_TEST(test_14_s21_log) {
    ck_assert_ldouble_nan(log(-DBL_MAX));
    ck_assert_ldouble_nan(s21_log(-DBL_MAX));
}
END_TEST

START_TEST(test_15_s21_log) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-45), log(1.1e-45), 1e-6);
}
END_TEST

START_TEST(test_16_s21_log) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-18), log(1.1e-18), 1e-6);
}
END_TEST

START_TEST(test_17_s21_log) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-19), log(1.1e-19), 1e-6);
}
END_TEST

START_TEST(test_18_s21_log) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-23), log(1.1e-23), 1e-6);
}
END_TEST

START_TEST(test_19_s21_log) {
    ck_assert_ldouble_eq_tol(s21_log(987654321123.123e-30),
                           log(987654321123.123e-30), 1e-6);
}
END_TEST

START_TEST(test_20_s21_log) {
    ck_assert_ldouble_eq_tol(s21_log(98765.123e-11), log(98765.123e-11), 1e-6);
}
END_TEST

START_TEST(test_21_s21_log) {
    ck_assert_ldouble_infinite(s21_log(0));
    ck_assert_ldouble_infinite(log(0));
}
END_TEST

START_TEST(test_22_s21_log) {
    ck_assert_ldouble_eq_tol(s21_log(1e-80), log(1e-80), 1e-6);
}
END_TEST

Suite * s21_log_suite(void) {
    Suite * suite = suite_create("group of log tests");

    // <INSERT>
    TCase * tc_insert = tcase_create("pow_tests");

    tcase_add_test(tc_insert, test_01_s21_log);
    tcase_add_test(tc_insert, test_02_s21_log);
    tcase_add_test(tc_insert, test_03_s21_log);
    tcase_add_test(tc_insert, test_04_s21_log);
    tcase_add_test(tc_insert, test_05_s21_log);
    tcase_add_test(tc_insert, test_06_s21_log);
    tcase_add_test(tc_insert, test_07_s21_log);
    tcase_add_test(tc_insert, test_08_s21_log);
    tcase_add_test(tc_insert, test_09_s21_log);
    tcase_add_test(tc_insert, test_10_s21_log);
    tcase_add_test(tc_insert, test_11_s21_log);
    tcase_add_test(tc_insert, test_12_s21_log);
    tcase_add_test(tc_insert, test_13_s21_log);
    tcase_add_test(tc_insert, test_14_s21_log);
    tcase_add_test(tc_insert, test_15_s21_log);
    tcase_add_test(tc_insert, test_16_s21_log);
    tcase_add_test(tc_insert, test_17_s21_log);
    tcase_add_test(tc_insert, test_18_s21_log);
    tcase_add_test(tc_insert, test_19_s21_log);
    tcase_add_test(tc_insert, test_20_s21_log);
    tcase_add_test(tc_insert, test_21_s21_log);
    tcase_add_test(tc_insert, test_22_s21_log);
    suite_add_tcase(suite, tc_insert);

    return suite;
}
