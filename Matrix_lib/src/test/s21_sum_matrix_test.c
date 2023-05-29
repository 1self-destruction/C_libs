#include "s21_tests_suite.h"

START_TEST(test_sum_1) {
  matrix_t a, b, res_matrix, sum;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  s21_create_matrix(2, 2, &res_matrix);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[1][0] = 3;
  a.matrix[1][1] = 4;

  b.matrix[0][0] = 4;
  b.matrix[0][1] = 3;
  b.matrix[1][0] = 2;
  b.matrix[1][1] = 1;

  res_matrix.matrix[0][0] = 5;
  res_matrix.matrix[0][1] = 5;
  res_matrix.matrix[1][0] = 5;
  res_matrix.matrix[1][1] = 5;

  s21_sum_matrix(&a, &b, &sum);
  int res = s21_eq_matrix(&sum, &res_matrix);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&sum);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(test_sum_2) {
  matrix_t a, b, res_matrix, sum;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  s21_create_matrix(2, 2, &res_matrix);

  a.matrix[0][0] = 0;
  a.matrix[0][1] = 0;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 0;

  b.matrix[0][0] = 0;
  b.matrix[0][1] = 0;
  b.matrix[1][0] = 0;
  b.matrix[1][1] = 0;

  res_matrix.matrix[0][0] = 0;
  res_matrix.matrix[0][1] = 0;
  res_matrix.matrix[1][0] = 0;
  res_matrix.matrix[1][1] = 0;

  s21_sum_matrix(&a, &b, &sum);
  int res = s21_eq_matrix(&sum, &res_matrix);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&sum);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(test_sum_3) {
  matrix_t a, b, res_matrix, sum;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  s21_create_matrix(2, 2, &res_matrix);

  a.matrix[0][0] = 1.5;
  a.matrix[0][1] = -5;
  a.matrix[1][0] = 3.50001;
  a.matrix[1][1] = -1000;

  b.matrix[0][0] = -100;
  b.matrix[0][1] = 3;
  b.matrix[1][0] = 2.4;
  b.matrix[1][1] = -10;

  res_matrix.matrix[0][0] = -98.5;
  res_matrix.matrix[0][1] = -2;
  res_matrix.matrix[1][0] = 5.90001;
  res_matrix.matrix[1][1] = -1010;

  s21_sum_matrix(&a, &b, &sum);
  int res = s21_eq_matrix(&sum, &res_matrix);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&sum);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(test_sum_4) {
  matrix_t a, b, res_matrix, sum;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);
  s21_create_matrix(1, 1, &res_matrix);

  a.matrix[0][0] = 0;

  b.matrix[0][0] = -100;

  res_matrix.matrix[0][0] = -100;

  s21_sum_matrix(&a, &b, &sum);
  int res = s21_eq_matrix(&sum, &res_matrix);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&sum);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(test_sum_err_1) {
  matrix_t a = {NULL, 0, 0}, b, res_matrix, sum;
  s21_create_matrix(1, 1, &b);
  s21_create_matrix(1, 1, &res_matrix);

  int res = s21_sum_matrix(&a, &b, &sum);
  ck_assert_int_eq(ERROR, res);

  s21_remove_matrix(&b);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(test_sum_err_2) {
  matrix_t a, b = {NULL, 0, 0}, res_matrix, sum;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &res_matrix);

  int res = s21_sum_matrix(&a, &b, &sum);
  ck_assert_int_eq(ERROR, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(test_sum_err_3) {
  matrix_t a = {NULL, 0, 0}, b = {NULL, 0, 0}, res_matrix, sum;
  s21_create_matrix(1, 1, &res_matrix);

  int res = s21_sum_matrix(&a, &b, &sum);
  ck_assert_int_eq(ERROR, res);

  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(test_sum_calc_err_1) {
  matrix_t a, b, sum;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(2, 2, &b);

  int res = s21_sum_matrix(&a, &b, &sum);
  ck_assert_int_eq(CALC_ERROR, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_sum_calc_err_2) {
  matrix_t a, b, sum;
  s21_create_matrix(10, 10, &a);
  s21_create_matrix(2, 2, &b);

  int res = s21_sum_matrix(&a, &b, &sum);
  ck_assert_int_eq(CALC_ERROR, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_sum_calc_err_3) {
  matrix_t a, b, sum;
  s21_create_matrix(10, 10, &a);
  s21_create_matrix(11, 11, &b);

  int res = s21_sum_matrix(&a, &b, &sum);
  ck_assert_int_eq(CALC_ERROR, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

Suite *sum_matrix() {
  Suite *s = suite_create("SUM_MATRIX");
  TCase *tc1 = tcase_create("tc_sum_matrix");
  TCase *tc2 = tcase_create("tc_sum_err_matrix");
  TCase *tc3 = tcase_create("tc_sum_calc_err_matrix");

  tcase_add_test(tc1, test_sum_1);
  tcase_add_test(tc1, test_sum_2);
  tcase_add_test(tc1, test_sum_3);
  tcase_add_test(tc1, test_sum_4);

  tcase_add_test(tc2, test_sum_err_1);
  tcase_add_test(tc2, test_sum_err_2);
  tcase_add_test(tc2, test_sum_err_3);

  tcase_add_test(tc3, test_sum_calc_err_1);
  tcase_add_test(tc3, test_sum_calc_err_2);
  tcase_add_test(tc3, test_sum_calc_err_3);

  suite_add_tcase(s, tc1);
  suite_add_tcase(s, tc2);
  suite_add_tcase(s, tc3);

  return s;
}