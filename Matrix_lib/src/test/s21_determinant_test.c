#include "s21_tests_suite.h"

START_TEST(determinant_1) {
  matrix_t test_matrix_1;
  double test_num_1;
  double result_num = 0.0;
  s21_create_matrix(3, 3, &test_matrix_1);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[0][2] = 3.0;
  test_matrix_1.matrix[1][0] = 4.0;
  test_matrix_1.matrix[1][1] = 5.0;
  test_matrix_1.matrix[1][2] = 6.0;
  test_matrix_1.matrix[2][0] = 7.0;
  test_matrix_1.matrix[2][1] = 8.0;
  test_matrix_1.matrix[2][2] = 9.0;

  int res = s21_determinant(&test_matrix_1, &test_num_1);

  ck_assert_double_eq(test_num_1, result_num);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t test_matrix_1;
  double test_num_1;
  double result_num = 89.0;
  s21_create_matrix(2, 2, &test_matrix_1);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = -4.0;
  test_matrix_1.matrix[1][0] = 21.0;
  test_matrix_1.matrix[1][1] = 5.0;

  int res = s21_determinant(&test_matrix_1, &test_num_1);

  ck_assert_double_eq(test_num_1, result_num);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t test_matrix_1;
  double test_num_1;
  double result_num = -666.0;
  s21_create_matrix(1, 1, &test_matrix_1);

  test_matrix_1.matrix[0][0] = -666.0;

  int res = s21_determinant(&test_matrix_1, &test_num_1);

  ck_assert_double_eq(test_num_1, result_num);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(determinant_4) {
  matrix_t test_matrix_1;
  double test_num_1;
  s21_create_matrix(2, 1, &test_matrix_1);

  test_matrix_1.matrix[0][0] = -666.0;

  int res = s21_determinant(&test_matrix_1, &test_num_1);

  ck_assert_int_eq(res, CALC_ERROR);
  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(determinant_5) {
  matrix_t test_matrix_1;
  double test_num_1;
  double result_num = -191.0;
  s21_create_matrix(4, 4, &test_matrix_1);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 4.0;
  test_matrix_1.matrix[0][2] = 5.0;
  test_matrix_1.matrix[0][3] = 6.0;
  test_matrix_1.matrix[1][0] = 4.0;
  test_matrix_1.matrix[1][1] = 1.0;
  test_matrix_1.matrix[1][2] = 5.0;
  test_matrix_1.matrix[1][3] = 2.0;
  test_matrix_1.matrix[2][0] = 1.0;
  test_matrix_1.matrix[2][1] = 2.0;
  test_matrix_1.matrix[2][2] = 4.0;
  test_matrix_1.matrix[2][3] = 5.0;
  test_matrix_1.matrix[3][0] = 3.0;
  test_matrix_1.matrix[3][1] = 7.0;
  test_matrix_1.matrix[3][2] = 1.0;
  test_matrix_1.matrix[3][3] = 6.0;

  int res = s21_determinant(&test_matrix_1, &test_num_1);

  ck_assert_double_eq(test_num_1, result_num);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&test_matrix_1);
}
END_TEST

Suite *determinant_matrix() {
  Suite *s = suite_create("DETERMINANT_MATRIX");
  TCase *tc = tcase_create("tc_determinant_matrix");

  tcase_add_test(tc, determinant_1);
  tcase_add_test(tc, determinant_2);
  tcase_add_test(tc, determinant_3);
  tcase_add_test(tc, determinant_4);
  tcase_add_test(tc, determinant_5);

  suite_add_tcase(s, tc);

  return s;
}
