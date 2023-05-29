#ifndef SRC_TEST_S21_TESTS_SUITE_H_
#define SRC_TEST_S21_TESTS_SUITE_H_

#include "../s21_matrix.h"

#include <check.h>
#include <stdio.h>

Suite *create_matrix(void);
Suite *remove_matrix(void);
Suite *equal_matrix(void);
Suite *sum_matrix(void);
Suite *sub_matrix(void);
Suite *mult_number(void);
Suite *mult_matrix(void);
Suite *transpose_matrix(void);
Suite *calc_complements_matrix(void);
Suite *determinant_matrix(void);
Suite *inverse_matrix(void);

#define SUITE_FUNCS                                                            \
  (Suite * (*[])(void)) {                                                      \
    create_matrix, remove_matrix, equal_matrix, sum_matrix, sub_matrix,        \
        mult_number, mult_matrix, transpose_matrix, calc_complements_matrix,   \
        determinant_matrix, inverse_matrix                                     \
  }

#define ARRAY_SUITE_LEN 11

#endif // SRC_TEST_S21_TESTS_SUITE_H_
