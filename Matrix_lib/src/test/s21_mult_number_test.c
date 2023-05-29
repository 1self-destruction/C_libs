#include "s21_tests_suite.h"

START_TEST(mult_number_1) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  double num = 2.0;
  s21_create_matrix(2, 2, &test_matrix_1);
  s21_create_matrix(2, 2, &test_matrix_2);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[1][0] = 3.0;
  test_matrix_1.matrix[1][1] = 4.0;

  test_matrix_2.matrix[0][0] = 2.0;
  test_matrix_2.matrix[0][1] = 4.0;
  test_matrix_2.matrix[1][0] = 6.0;
  test_matrix_2.matrix[1][1] = 8.0;

  int mult_num_return_value =
      s21_mult_number(&test_matrix_1, num, &test_matrix_3);
  int eq = s21_eq_matrix(&test_matrix_3, &test_matrix_2);
  ck_assert_int_eq(mult_num_return_value, OK);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(mult_number_2) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  double num = -2.0;
  s21_create_matrix(2, 2, &test_matrix_1);
  s21_create_matrix(2, 2, &test_matrix_2);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[1][0] = 3.0;
  test_matrix_1.matrix[1][1] = 4.0;

  test_matrix_2.matrix[0][0] = -2.0;
  test_matrix_2.matrix[0][1] = -4.0;
  test_matrix_2.matrix[1][0] = -6.0;
  test_matrix_2.matrix[1][1] = -8.0;

  int mult_num_return_value =
      s21_mult_number(&test_matrix_1, num, &test_matrix_3);
  int eq = s21_eq_matrix(&test_matrix_3, &test_matrix_2);
  ck_assert_int_eq(mult_num_return_value, OK);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(mult_number_3) {
  matrix_t test_matrix_1 = {NULL, 0, 0};
  matrix_t test_matrix_2;
  matrix_t test_matrix_3 = {NULL, 0, 0};
  double num = 2.0;
  s21_create_matrix(2, 2, &test_matrix_2);

  test_matrix_2.matrix[0][0] = -2.0;
  test_matrix_2.matrix[0][1] = -4.0;
  test_matrix_2.matrix[1][0] = -6.0;
  test_matrix_2.matrix[1][1] = -8.0;

  int mult_num_return_value =
      s21_mult_number(&test_matrix_1, num, &test_matrix_3);

  int eq = s21_eq_matrix(&test_matrix_3, &test_matrix_2);
  ck_assert_int_eq(mult_num_return_value, ERROR);
  ck_assert_int_eq(eq, FAILURE);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

Suite *mult_number() {
  Suite *s = suite_create("MULT_NUMBER");
  TCase *tc = tcase_create("tc_mult_number_matrix");

  tcase_add_test(tc, mult_number_1);
  tcase_add_test(tc, mult_number_2);
  tcase_add_test(tc, mult_number_3);

  suite_add_tcase(s, tc);

  return s;
}
