#include "s21_tests_suite.h"

START_TEST(transpose_1) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  s21_create_matrix(3, 2, &test_matrix_1);
  s21_create_matrix(2, 3, &test_matrix_3);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 4.0;
  test_matrix_1.matrix[1][0] = 2.0;
  test_matrix_1.matrix[1][1] = 5.0;
  test_matrix_1.matrix[2][0] = 3.0;
  test_matrix_1.matrix[2][1] = 6.0;

  test_matrix_3.matrix[0][0] = 1.0;
  test_matrix_3.matrix[0][1] = 2.0;
  test_matrix_3.matrix[0][2] = 3.0;
  test_matrix_3.matrix[1][0] = 4.0;
  test_matrix_3.matrix[1][1] = 5.0;
  test_matrix_3.matrix[1][2] = 6.0;

  s21_transpose(&test_matrix_1, &test_matrix_2);
  int eq = s21_eq_matrix(&test_matrix_2, &test_matrix_3);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  s21_create_matrix(3, 2, &test_matrix_1);
  s21_create_matrix(2, 3, &test_matrix_3);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 4.0;
  test_matrix_1.matrix[1][0] = 2.0;
  test_matrix_1.matrix[1][1] = 5.0;
  test_matrix_1.matrix[2][0] = 3.0;
  test_matrix_1.matrix[2][1] = 6.0;

  test_matrix_3.matrix[0][0] = 1.0;
  test_matrix_3.matrix[0][1] = 2.0;
  test_matrix_3.matrix[0][2] = 3.0;
  test_matrix_3.matrix[1][0] = 4.0;
  test_matrix_3.matrix[1][1] = 5.0;
  test_matrix_3.matrix[1][2] = 6.0;

  int res = s21_transpose(NULL, &test_matrix_2);
  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

Suite *transpose_matrix() {
  Suite *s = suite_create("TRANSPOSE_MATRIX");
  TCase *tc = tcase_create("tc_transpose_matrix");

  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);

  suite_add_tcase(s, tc);

  return s;
}
