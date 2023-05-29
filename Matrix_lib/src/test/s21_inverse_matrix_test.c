#include "s21_tests_suite.h"

START_TEST(inverse_matrix_1) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  s21_create_matrix(3, 3, &test_matrix_1);
  s21_create_matrix(3, 3, &test_matrix_3);

  test_matrix_1.matrix[0][0] = 2.0;
  test_matrix_1.matrix[0][1] = 5.0;
  test_matrix_1.matrix[0][2] = 7.0;
  test_matrix_1.matrix[1][0] = 6.0;
  test_matrix_1.matrix[1][1] = 3.0;
  test_matrix_1.matrix[1][2] = 4.0;
  test_matrix_1.matrix[2][0] = 5.0;
  test_matrix_1.matrix[2][1] = -2.0;
  test_matrix_1.matrix[2][2] = -3.0;

  test_matrix_3.matrix[0][0] = 1.0;
  test_matrix_3.matrix[0][1] = -1.0;
  test_matrix_3.matrix[0][2] = 1.0;
  test_matrix_3.matrix[1][0] = -38.0;
  test_matrix_3.matrix[1][1] = 41.0;
  test_matrix_3.matrix[1][2] = -34.0;
  test_matrix_3.matrix[2][0] = 27.0;
  test_matrix_3.matrix[2][1] = -29.0;
  test_matrix_3.matrix[2][2] = 24.0;

  int res = s21_inverse_matrix(&test_matrix_1, &test_matrix_2);

  int eq = s21_eq_matrix(&test_matrix_2, &test_matrix_3);
  ck_assert_int_eq(eq, SUCCESS);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t test_matrix_1 = {NULL, 0, 0};
  matrix_t test_matrix_2;

  int res = s21_inverse_matrix(&test_matrix_1, &test_matrix_2);

  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  s21_create_matrix(3, 3, &test_matrix_1);

  test_matrix_1.matrix[0][0] = 5.0;
  test_matrix_1.matrix[0][1] = 3.0;
  test_matrix_1.matrix[0][2] = 1.0;
  test_matrix_1.matrix[1][0] = 2.0;
  test_matrix_1.matrix[1][1] = 4.0;
  test_matrix_1.matrix[1][2] = 6.0;
  test_matrix_1.matrix[2][0] = -1.0;
  test_matrix_1.matrix[2][1] = -2.0;
  test_matrix_1.matrix[2][2] = -3.0;

  int res = s21_inverse_matrix(&test_matrix_1, &test_matrix_2);

  ck_assert_int_eq(res, CALC_ERROR);
  s21_remove_matrix(&test_matrix_1);
}
END_TEST

Suite *inverse_matrix() {
  Suite *s = suite_create("INVERSE_MATRIX");
  TCase *tc = tcase_create("tc_inverse_matrix");

  tcase_add_test(tc, inverse_matrix_1);
  tcase_add_test(tc, inverse_matrix_2);
  tcase_add_test(tc, inverse_matrix_3);

  suite_add_tcase(s, tc);

  return s;
}