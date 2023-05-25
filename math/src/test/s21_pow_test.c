#include "s21_tests_suite.h"

START_TEST(test_01_s21_pow) {
    double base = 456.789;
    double exp = 1.1;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
} END_TEST

START_TEST(test_02_s21_pow) {
    double base = INFINITY;
    double exp = 1.1;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
} END_TEST

START_TEST(test_03_s21_pow) {
    double base = NAN;
    double exp = 1.1;
    ck_assert_ldouble_nan(s21_pow(base, exp));
    ck_assert_ldouble_nan(pow(base, exp));
} END_TEST

START_TEST(test_04_s21_pow) {
    double base = NAN;
    double exp = NAN;
    ck_assert_ldouble_nan(s21_pow(base, exp));
    ck_assert_ldouble_nan(pow(base, exp));
} END_TEST

START_TEST(test_05_s21_pow) {
    double base = 0.001;
    double exp = NAN;
    ck_assert_ldouble_nan(s21_pow(base, exp));
    ck_assert_ldouble_nan(pow(base, exp));
} END_TEST

START_TEST(test_06_s21_pow) {
    double base = INFINITY;
    double exp = INFINITY;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
} END_TEST

START_TEST(test_07_s21_pow) {
    long double base = -16.161435;
    long double exp = 9.;
    ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
} END_TEST

START_TEST(test_08_s21_pow) {
    long double base = -10.1261;
    long double exp = -0.72;
    ck_assert_double_nan(s21_pow(base, exp));
    ck_assert_double_nan(pow(base, exp));
} END_TEST

START_TEST(test_09_s21_pow) {
    long double base = +0;
    long double exp = -0.33;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
} END_TEST

START_TEST(test_10_s21_pow) {
    long double base = -0;
    long double exp = -0.33;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
} END_TEST

START_TEST(test_11_s21_pow) {
    long double base = -0;
    long double exp = S21_INF;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_EPS);
} END_TEST

START_TEST(test_12_s21_pow) {
    long double base = +0;
    long double exp = 123;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
} END_TEST

START_TEST(test_13_s21_pow) {
    long double base = -0;
    long double exp = 123;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
} END_TEST

START_TEST(test_14_s21_pow) {
    long double base = -0;
    long double exp = S21_INF;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
} END_TEST

START_TEST(test_15_s21_pow) {
    long double base = -1;
    long double exp = S21_INF;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
} END_TEST

START_TEST(test_16_s21_pow) {
    long double base = -1;
    long double exp = S21_NAN;
    ck_assert_double_nan(pow(base, exp));
    ck_assert_double_nan(s21_pow(base, exp));
} END_TEST

START_TEST(test_17_s21_pow) {
    long double base = S21_NAN;
    long double exp = 0;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
} END_TEST

START_TEST(test_18_s21_pow) {
    long double base = -123;
    long double exp = S21_NAN;
    ck_assert_double_nan(s21_pow(base, exp));
    ck_assert_double_nan(pow(base, exp));
} END_TEST

START_TEST(test_19_s21_pow) {
    long double base = 0.5591951;
    long double exp = -S21_INF;
    ck_assert_ldouble_infinite(pow(base, exp));
    ck_assert_ldouble_infinite(s21_pow(base, exp));
} END_TEST

START_TEST(test_20_s21_pow) {
    long double base = 1.5591951;
    long double exp = -S21_INF;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
} END_TEST

START_TEST(test_21_s21_pow) {
    long double base = 0.5591951;
    long double exp = S21_INF;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
} END_TEST

START_TEST(test_22_s21_pow) {
    long double base = 1.5591951;
    long double exp = S21_INF;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
} END_TEST

START_TEST(test_23_s21_pow) {
    long double base = -S21_INF;
    long double exp = -193491;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
} END_TEST

START_TEST(test_24_s21_pow) {
    long double base = -S21_INF;
    long double exp = -142;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
} END_TEST

START_TEST(test_25_s21_pow) {
    long double base = -S21_INF;
    long double exp = 141;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
} END_TEST

START_TEST(test_26_s21_pow) {
    long double base = -S21_INF;
    long double exp = 142;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
} END_TEST

START_TEST(test_27_s21_pow) {
    long double base = S21_INF;
    long double exp = -1;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
} END_TEST

START_TEST(test_28_s21_pow) {
    long double base = S21_INF;
    long double exp = 1;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
} END_TEST

START_TEST(test_29_s21_pow) {
    ck_assert_ldouble_eq_tol(s21_pow(0.0, 0.0), pow(0.0, 0.0), 1e-6);
} END_TEST

START_TEST(test_30_s21_pow) {
    ck_assert_ldouble_eq_tol(s21_pow(-1, 4), pow(-1, 4), 1e-6);
} END_TEST

START_TEST(test_31_s21_pow) {
    ck_assert_ldouble_eq_tol(s21_pow(2, 18), pow(2, 18), 1e-6);
} END_TEST

START_TEST(test_32_s21_pow) {
    ck_assert_ldouble_eq_tol(s21_pow(2.1, 11), pow(2.1, 11), 1e-6);
} END_TEST

START_TEST(test_33_s21_pow) {
    ck_assert_ldouble_eq_tol(s21_pow(1.23456e-7, 2.21), pow(1.23456e-7, 2.21), 1e-6);
} END_TEST

START_TEST(test_34_s21_pow) {
    ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), 1e-6);
} END_TEST

START_TEST(test_35_s21_pow) {
    ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), 1e-6);
} END_TEST

START_TEST(test_36_s21_pow) {
    long double base = 2.1234567e-7;
    long double exp = -2.45e4;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
} END_TEST

START_TEST(test_37_s21_pow) {
    ck_assert_ldouble_eq_tol(s21_pow(9.99999999e3, 9.95e-4),
                           pow(9.99999999e3, 9.95e-4), 1e-6);
} END_TEST

START_TEST(test_38_s21_pow) {
    long double exp = -12;
    ck_assert_ldouble_infinite(s21_pow(+0, exp));
    ck_assert_ldouble_infinite(pow(+0, exp));
} END_TEST

START_TEST(test_39_s21_pow) {
    long double exp = -12;
    ck_assert_ldouble_infinite(s21_pow(-0, exp));
    ck_assert_ldouble_infinite(pow(-0, exp));
} END_TEST

START_TEST(test_40_s21_pow) {
    long double exp = 0;
    ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
} END_TEST

START_TEST(test_41_s21_pow) {
    long double exp = S21_NAN;
    ck_assert_double_nan(s21_pow(+0, exp));
    ck_assert_double_nan(pow(+0, exp));
} END_TEST

START_TEST(test_42_s21_pow) {
    long double exp = 2.456;
    ck_assert_ldouble_eq_tol(s21_pow(+0, exp), pow(+0, exp), 1e-6);
} END_TEST

START_TEST(test_43_s21_pow) {
    long double exp = -S21_INF;
    ck_assert_ldouble_infinite(s21_pow(+0, exp));
    ck_assert_ldouble_infinite(pow(+0, exp));
} END_TEST

START_TEST(test_44_s21_pow) {
    long double exp = 56;
    ck_assert_ldouble_eq_tol(s21_pow(+0, exp), pow(+0, exp), 1e-6);
} END_TEST

START_TEST(test_45_s21_pow) {
    long double exp = 56;
    ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
} END_TEST

START_TEST(test_46_s21_pow) {
    long double exp = 56.345;
    ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
} END_TEST

START_TEST(test_47_s21_pow) {
    long double exp = S21_INF;
    ck_assert_ldouble_eq_tol(s21_pow(-1, exp), pow(-1, exp), 1e-6);
} END_TEST

START_TEST(test_48_s21_pow) {
    long double exp = -S21_INF;
    ck_assert_ldouble_eq_tol(s21_pow(-1, exp), pow(-1, exp), 1e-6);
} END_TEST

START_TEST(test_49_s21_pow) {
    long double exp = S21_NAN;
    ck_assert_ldouble_eq_tol(s21_pow(+1, exp), pow(+1, exp), 1e-6);
} END_TEST

START_TEST(test_50_s21_pow) {
    long double exp = -0;
    ck_assert_ldouble_eq_tol(s21_pow(4567, exp), pow(4567, exp), 1e-6);
} END_TEST

START_TEST(test_51_s21_pow) {
    long double exp = +0;
    ck_assert_ldouble_eq_tol(s21_pow(34567, exp), pow(34567, exp), 1e-6);
} END_TEST

START_TEST(test_52_s21_pow) {
    long double exp = -0;
    ck_assert_ldouble_eq_tol(s21_pow(S21_NAN, exp), pow(S21_NAN, exp), 1e-6);
} END_TEST

START_TEST(test_53_s21_pow) {
    long double exp = +0;
    ck_assert_ldouble_eq_tol(s21_pow(S21_NAN, exp), pow(S21_NAN, exp), 1e-6);
} END_TEST

START_TEST(test_54_s21_pow) {
    long double exp = S21_NAN;
    ck_assert_double_nan(s21_pow(S21_NAN, exp));
    ck_assert_double_nan(pow(S21_NAN, exp));
} END_TEST

START_TEST(test_55_s21_pow) {
    long double exp = S21_INF;
    ck_assert_ldouble_infinite(s21_pow(S21_INF, exp));
    ck_assert_ldouble_infinite(pow(S21_INF, exp));
} END_TEST

START_TEST(test_56_s21_pow) {
    long double exp = -S21_INF;
    ck_assert_ldouble_eq_tol(s21_pow(-S21_INF, exp), pow(-S21_INF, exp), 1e-6);
} END_TEST

START_TEST(test_57_s21_pow) {
    double exp = S21_INF;
    ck_assert_ldouble_infinite(s21_pow(-S21_INF, exp));
    ck_assert_ldouble_infinite(pow(-S21_INF, exp));
} END_TEST

START_TEST(test_58_s21_pow) {
    for (double exp = 0.0; exp > -1000; exp -= 0.1) {
        double res1 = pow(S21_INF, exp);
        long double res2 = s21_pow(S21_INF, exp);
        ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
    }
} END_TEST

START_TEST(test_59_s21_pow) {
    for (double base = 1.1; base < 10; base += 0.1) {
        double res1 = pow(base, S21_INF);
        long double res2 = s21_pow(base, S21_INF);
        ck_assert_ldouble_infinite(res1);
        ck_assert_ldouble_infinite(res2);
    }
} END_TEST

START_TEST(test_60_s21_pow) {
    for (double base = -1.1; base > -10; base -= 0.1) {
        double res1 = pow(base, S21_INF);
        long double res2 = s21_pow(base, S21_INF);
        ck_assert_ldouble_infinite(res1);
        ck_assert_ldouble_infinite(res2);
    }
} END_TEST

START_TEST(test_61_s21_pow) {
    for (double exp = 0.0; exp > -10; exp -= 0.1) {
      if (fmod(exp, 2) != 0) {
          double res1 = pow(-S21_INF, exp);
          long double res2 = s21_pow(-S21_INF, exp);
          ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
      }
    }
} END_TEST

START_TEST(test_62_s21_pow) {
    for (double exp = 0.0; exp < 10; exp += 0.1) {
        if (fmod(exp, 2) != 0) {
            double res1 = pow(-S21_INF, exp);
            long double res2 = s21_pow(-S21_INF, exp);
            ck_assert_ldouble_infinite(res1);
            ck_assert_ldouble_infinite(res2);
        }
    }
} END_TEST


START_TEST(test_63_s21_pow) {
    long double exp = 3;
    ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), 1e-6);
} END_TEST

START_TEST(test_64_s21_pow) {
    long double exp = -3;
    ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), 1e-6);
} END_TEST

START_TEST(test_65_s21_pow) {
    long double exp = -3;
    ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), 1e-6);
} END_TEST

START_TEST(test_66_s21_pow) {
    long double exp = 3;
    ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), 1e-6);
} END_TEST

START_TEST(test_67_s21_pow) {
    long double base = -0;
    long double exp = S21_INF;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
} END_TEST

START_TEST(test_68_s21_pow) {
    for (long double exp = 0.0; exp < 10; exp += 0.1) {
        if (fmod(exp, 2) != 0) {
            long double base = -0;
            long double res = pow(base, exp);
            long double res1 = s21_pow(base, exp);
            ck_assert_ldouble_eq_tol(res, res1, 1e-6);
        }
    }
} END_TEST

START_TEST(test_69_s21_pow) {
    ck_assert_ldouble_eq_tol(pow(-S21_INF, 0), s21_pow(-S21_INF, 0), 1e-6);
} END_TEST


Suite * s21_pow_suite(void) {
    Suite * suite = suite_create("group of pow tests");

    // <INSERT>
    TCase * tc_insert = tcase_create("pow_tests");

    tcase_add_test(tc_insert, test_01_s21_pow);
    tcase_add_test(tc_insert, test_02_s21_pow);
    tcase_add_test(tc_insert, test_03_s21_pow);
    tcase_add_test(tc_insert, test_04_s21_pow);
    tcase_add_test(tc_insert, test_05_s21_pow);
    tcase_add_test(tc_insert, test_06_s21_pow);
    tcase_add_test(tc_insert, test_07_s21_pow);
    tcase_add_test(tc_insert, test_08_s21_pow);
    tcase_add_test(tc_insert, test_09_s21_pow);
    tcase_add_test(tc_insert, test_10_s21_pow);
    tcase_add_test(tc_insert, test_11_s21_pow);
    tcase_add_test(tc_insert, test_12_s21_pow);
    tcase_add_test(tc_insert, test_13_s21_pow);
    tcase_add_test(tc_insert, test_14_s21_pow);
    tcase_add_test(tc_insert, test_15_s21_pow);
    tcase_add_test(tc_insert, test_16_s21_pow);
    tcase_add_test(tc_insert, test_17_s21_pow);
    tcase_add_test(tc_insert, test_18_s21_pow);
    tcase_add_test(tc_insert, test_19_s21_pow);
    tcase_add_test(tc_insert, test_20_s21_pow);
    tcase_add_test(tc_insert, test_21_s21_pow);
    tcase_add_test(tc_insert, test_22_s21_pow);
    tcase_add_test(tc_insert, test_23_s21_pow);
    tcase_add_test(tc_insert, test_24_s21_pow);
    tcase_add_test(tc_insert, test_25_s21_pow);
    tcase_add_test(tc_insert, test_26_s21_pow);
    tcase_add_test(tc_insert, test_27_s21_pow);
    tcase_add_test(tc_insert, test_28_s21_pow);
    tcase_add_test(tc_insert, test_29_s21_pow);
    tcase_add_test(tc_insert, test_30_s21_pow);
    tcase_add_test(tc_insert, test_31_s21_pow);
    tcase_add_test(tc_insert, test_32_s21_pow);
    tcase_add_test(tc_insert, test_33_s21_pow);
    tcase_add_test(tc_insert, test_34_s21_pow);
    tcase_add_test(tc_insert, test_35_s21_pow);
    tcase_add_test(tc_insert, test_36_s21_pow);
    tcase_add_test(tc_insert, test_37_s21_pow);
    tcase_add_test(tc_insert, test_38_s21_pow);
    tcase_add_test(tc_insert, test_39_s21_pow);
    tcase_add_test(tc_insert, test_40_s21_pow);
    tcase_add_test(tc_insert, test_41_s21_pow);
    tcase_add_test(tc_insert, test_42_s21_pow);
    tcase_add_test(tc_insert, test_43_s21_pow);
    tcase_add_test(tc_insert, test_44_s21_pow);
    tcase_add_test(tc_insert, test_45_s21_pow);
    tcase_add_test(tc_insert, test_46_s21_pow);
    tcase_add_test(tc_insert, test_47_s21_pow);
    tcase_add_test(tc_insert, test_48_s21_pow);
    tcase_add_test(tc_insert, test_49_s21_pow);
    tcase_add_test(tc_insert, test_50_s21_pow);
    tcase_add_test(tc_insert, test_51_s21_pow);
    tcase_add_test(tc_insert, test_52_s21_pow);
    tcase_add_test(tc_insert, test_53_s21_pow);
    tcase_add_test(tc_insert, test_54_s21_pow);
    tcase_add_test(tc_insert, test_55_s21_pow);
    tcase_add_test(tc_insert, test_56_s21_pow);
    tcase_add_test(tc_insert, test_57_s21_pow);
    tcase_add_test(tc_insert, test_58_s21_pow);
    tcase_add_test(tc_insert, test_59_s21_pow);
    tcase_add_test(tc_insert, test_60_s21_pow);
    tcase_add_test(tc_insert, test_61_s21_pow);
    tcase_add_test(tc_insert, test_62_s21_pow);
    tcase_add_test(tc_insert, test_63_s21_pow);
    tcase_add_test(tc_insert, test_64_s21_pow);
    tcase_add_test(tc_insert, test_65_s21_pow);
    tcase_add_test(tc_insert, test_66_s21_pow);
    tcase_add_test(tc_insert, test_67_s21_pow);
    tcase_add_test(tc_insert, test_68_s21_pow);
    tcase_add_test(tc_insert, test_69_s21_pow);

    suite_add_tcase(suite, tc_insert);

    return suite;
}
