#include "s21_tests_suite.h"

START_TEST(mult_matrix_1) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  matrix_t test_matrix_4;

  s21_create_matrix(2, 2, &test_matrix_1);
  s21_create_matrix(2, 2, &test_matrix_2);
  s21_create_matrix(2, 2, &test_matrix_4);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[1][0] = 3.0;
  test_matrix_1.matrix[1][1] = 4.0;

  test_matrix_2.matrix[0][0] = 4.0;
  test_matrix_2.matrix[0][1] = 3.0;
  test_matrix_2.matrix[1][0] = 2.0;
  test_matrix_2.matrix[1][1] = 1.0;

  test_matrix_4.matrix[0][0] = 8.0;
  test_matrix_4.matrix[0][1] = 5.0;
  test_matrix_4.matrix[1][0] = 20.0;
  test_matrix_4.matrix[1][1] = 13.0;

  int res = s21_mult_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_3);

  int eq = s21_eq_matrix(&test_matrix_3, &test_matrix_4);
  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
  s21_remove_matrix(&test_matrix_4);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t *test_matrix_3 = NULL;
  matrix_t test_matrix_4;

  s21_create_matrix(2, 2, &test_matrix_1);
  s21_create_matrix(4, 4, &test_matrix_2);
  s21_create_matrix(4, 4, &test_matrix_4);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[1][0] = 3.0;
  test_matrix_1.matrix[1][1] = 4.0;

  test_matrix_2.matrix[0][0] = 4.0;
  test_matrix_2.matrix[0][1] = 3.0;
  test_matrix_2.matrix[1][0] = 2.0;
  test_matrix_2.matrix[1][1] = 1.0;

  test_matrix_4.matrix[0][0] = 8.0;
  test_matrix_4.matrix[0][1] = 5.0;
  test_matrix_4.matrix[1][0] = 20.0;
  test_matrix_4.matrix[1][1] = 13.0;

  int res = s21_mult_matrix(&test_matrix_1, &test_matrix_2, test_matrix_3);

  int eq = s21_eq_matrix(test_matrix_3, &test_matrix_4);
  ck_assert_int_eq(res, CALC_ERROR);
  ck_assert_int_eq(eq, FAILURE);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_4);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t *test_matrix_1 = NULL;
  matrix_t test_matrix_2;
  matrix_t *test_matrix_3 = NULL;
  matrix_t test_matrix_4;

  s21_create_matrix(4, 4, &test_matrix_2);
  s21_create_matrix(4, 4, &test_matrix_4);

  test_matrix_2.matrix[0][0] = 4.0;
  test_matrix_2.matrix[0][1] = 3.0;
  test_matrix_2.matrix[1][0] = 2.0;
  test_matrix_2.matrix[1][1] = 1.0;

  test_matrix_4.matrix[0][0] = 8.0;
  test_matrix_4.matrix[0][1] = 5.0;
  test_matrix_4.matrix[1][0] = 20.0;
  test_matrix_4.matrix[1][1] = 13.0;

  int res = s21_mult_matrix(test_matrix_1, &test_matrix_2, test_matrix_3);

  int eq = s21_eq_matrix(test_matrix_3, &test_matrix_4);
  ck_assert_int_eq(res, ERROR);
  ck_assert_int_eq(eq, FAILURE);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_4);
}
END_TEST

Suite *mult_matrix() {
  Suite *s = suite_create("MULT_MATRIX");
  TCase *tc = tcase_create("tc_mult_matrix");

  tcase_add_test(tc, mult_matrix_1);
  tcase_add_test(tc, mult_matrix_2);
  tcase_add_test(tc, mult_matrix_3);

  suite_add_tcase(s, tc);

  return s;
}
