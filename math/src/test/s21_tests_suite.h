#ifndef SRC_TEST_S21_TESTS_SUITE_H_
#define SRC_TEST_S21_TESTS_SUITE_H_

#include <check.h>
#include "../s21_math.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>

Suite * s21_abs_suite(void);
Suite * s21_acos_suite(void);
Suite * s21_asin_suite(void);
Suite * s21_atan_suite(void);
Suite * s21_ceil_suite(void);
Suite * s21_pow_suite(void);
Suite * s21_log_suite(void);
Suite * s21_sin_suite(void);
Suite * s21_sqrt_suite(void);
Suite * s21_tan_suite(void);
Suite * s21_cos_suite(void);
Suite * s21_fabs_suite(void);
Suite * s21_exp_suite(void);
Suite * s21_floor_suite(void);
Suite * s21_fmod_suite(void);

#define SUITE_FUNCS (Suite*(*[])(void)) {  \
    s21_abs_suite,                         \
    s21_acos_suite,                        \
    s21_asin_suite,                        \
    s21_atan_suite,                        \
    s21_ceil_suite,                        \
    s21_pow_suite,                         \
    s21_log_suite,                         \
    s21_sin_suite,                         \
    s21_sqrt_suite,                        \
    s21_tan_suite,                         \
    s21_cos_suite,                         \
    s21_fabs_suite,                        \
    s21_exp_suite,                         \
    s21_floor_suite,                       \
    s21_fmod_suite                         \
}

#define ARRAY_SUITE_LEN 15

#endif  // SRC_TEST_S21_TESTS_SUITE_H_
