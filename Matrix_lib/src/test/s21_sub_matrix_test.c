#include "s21_tests_suite.h"

START_TEST(sub_matrix_1) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  matrix_t test_matrix_4;
  s21_create_matrix(3, 3, &test_matrix_1);
  s21_create_matrix(3, 3, &test_matrix_2);
  s21_create_matrix(3, 3, &test_matrix_3);
  s21_create_matrix(3, 3, &test_matrix_4);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[0][2] = 3.0;
  test_matrix_1.matrix[1][0] = 0.0;
  test_matrix_1.matrix[1][1] = 4.0;
  test_matrix_1.matrix[1][2] = 5.0;
  test_matrix_1.matrix[2][0] = 0.0;
  test_matrix_1.matrix[2][1] = 0.0;
  test_matrix_1.matrix[2][2] = 6.0;

  test_matrix_2.matrix[0][0] = 1.0;
  test_matrix_2.matrix[0][1] = 0.0;
  test_matrix_2.matrix[0][2] = 0.0;
  test_matrix_2.matrix[1][0] = 2.0;
  test_matrix_2.matrix[1][1] = 0.0;
  test_matrix_2.matrix[1][2] = 0.0;
  test_matrix_2.matrix[2][0] = 3.0;
  test_matrix_2.matrix[2][1] = 4.0;
  test_matrix_2.matrix[2][2] = 1.0;

  test_matrix_3.matrix[0][0] = 0.0;
  test_matrix_3.matrix[0][1] = 2.0;
  test_matrix_3.matrix[0][2] = 3.0;
  test_matrix_3.matrix[1][0] = -2.0;
  test_matrix_3.matrix[1][1] = 4.0;
  test_matrix_3.matrix[1][2] = 5.0;
  test_matrix_3.matrix[2][0] = -3.0;
  test_matrix_3.matrix[2][1] = -4.0;
  test_matrix_3.matrix[2][2] = 5.0;

  int ret_val =
      s21_sub_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_4);
  int eq_val = s21_eq_matrix(&test_matrix_4, &test_matrix_3);
  ck_assert_int_eq(eq_val, SUCCESS);
  ck_assert_int_eq(ret_val, OK);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
  s21_remove_matrix(&test_matrix_4);
}
END_TEST

START_TEST(sub_matrix_2) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  s21_create_matrix(3, 3, &test_matrix_1);
  s21_create_matrix(2, 2, &test_matrix_2);
  s21_create_matrix(2, 2, &test_matrix_3);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[0][2] = 3.0;
  test_matrix_1.matrix[1][0] = 0.0;
  test_matrix_1.matrix[1][1] = 4.0;
  test_matrix_1.matrix[1][2] = 5.0;
  test_matrix_1.matrix[2][0] = 0.0;
  test_matrix_1.matrix[2][1] = 0.0;
  test_matrix_1.matrix[2][2] = 6.0;

  test_matrix_2.matrix[0][0] = 1.0;
  test_matrix_2.matrix[0][1] = 0.0;
  test_matrix_2.matrix[1][0] = 2.0;
  test_matrix_2.matrix[1][1] = 0.0;

  int ret_val =
      s21_sub_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_3);
  ck_assert_int_eq(ret_val, CALC_ERROR);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(sub_matrix_3) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_3;
  s21_create_matrix(3, 3, &test_matrix_1);
  s21_create_matrix(2, 2, &test_matrix_3);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[0][2] = 3.0;
  test_matrix_1.matrix[1][0] = 0.0;
  test_matrix_1.matrix[1][1] = 4.0;
  test_matrix_1.matrix[1][2] = 5.0;
  test_matrix_1.matrix[2][0] = 0.0;
  test_matrix_1.matrix[2][1] = 0.0;
  test_matrix_1.matrix[2][2] = 6.0;

  int ret_val = s21_sub_matrix(&test_matrix_1, NULL, &test_matrix_3);
  ck_assert_int_eq(ret_val, ERROR);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

Suite *sub_matrix() {
  Suite *s = suite_create("SUB_MATRIX");
  TCase *tc = tcase_create("tc_sub_matrix");

  tcase_add_test(tc, sub_matrix_1);
  tcase_add_test(tc, sub_matrix_2);
  tcase_add_test(tc, sub_matrix_3);

  suite_add_tcase(s, tc);

  return s;
}
