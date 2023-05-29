#include "s21_tests_suite.h"

START_TEST(calc_complements_1) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  s21_create_matrix(3, 3, &test_matrix_1);
  s21_create_matrix(3, 3, &test_matrix_3);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[0][2] = 3.0;
  test_matrix_1.matrix[1][0] = 0.0;
  test_matrix_1.matrix[1][1] = 4.0;
  test_matrix_1.matrix[1][2] = 2.0;
  test_matrix_1.matrix[2][0] = 5.0;
  test_matrix_1.matrix[2][1] = 2.0;
  test_matrix_1.matrix[2][2] = 1.0;

  test_matrix_3.matrix[0][0] = 0.0;
  test_matrix_3.matrix[0][1] = 10.0;
  test_matrix_3.matrix[0][2] = -20.0;
  test_matrix_3.matrix[1][0] = 4.0;
  test_matrix_3.matrix[1][1] = -14.0;
  test_matrix_3.matrix[1][2] = 8.0;
  test_matrix_3.matrix[2][0] = -8.0;
  test_matrix_3.matrix[2][1] = -2.0;
  test_matrix_3.matrix[2][2] = 4.0;

  int res = s21_calc_complements(&test_matrix_1, &test_matrix_2);
  int eq = s21_eq_matrix(&test_matrix_2, &test_matrix_3);
  ck_assert_int_eq(eq, SUCCESS);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(calc_complements_2) {
  matrix_t *test_matrix_1 = NULL;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  s21_create_matrix(3, 3, &test_matrix_2);
  s21_create_matrix(3, 3, &test_matrix_3);

  test_matrix_3.matrix[0][0] = 0.0;
  test_matrix_3.matrix[0][1] = 10.0;
  test_matrix_3.matrix[0][2] = -20.0;
  test_matrix_3.matrix[1][0] = 4.0;
  test_matrix_3.matrix[1][1] = -14.0;
  test_matrix_3.matrix[1][2] = 8.0;
  test_matrix_3.matrix[2][0] = -8.0;
  test_matrix_3.matrix[2][1] = -2.0;
  test_matrix_3.matrix[2][2] = 4.0;

  int res = s21_calc_complements(test_matrix_1, &test_matrix_2);
  int eq = s21_eq_matrix(&test_matrix_2, &test_matrix_3);
  ck_assert_int_eq(eq, FAILURE);
  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

Suite *calc_complements_matrix() {
  Suite *s = suite_create("CALC_COMPLEMENTS_MATRIX");
  TCase *tc = tcase_create("tc_calc_complements_matrix");

  tcase_add_test(tc, calc_complements_1);
  tcase_add_test(tc, calc_complements_2);

  suite_add_tcase(s, tc);

  return s;
}
