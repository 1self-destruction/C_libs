#include "s21_tests_suite.h"

START_TEST(test_eq_1x1_1) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = 3.0;
  b.matrix[0][0] = 3.0;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_1x1_2) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = 0.0;
  b.matrix[0][0] = 0.0;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_1x1_3) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = -10.5;
  b.matrix[0][0] = -10.5;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_1x1_4) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = -100;
  b.matrix[0][0] = -100;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_1x1_5) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = 666.6;
  b.matrix[0][0] = 666.6;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_2x2_1) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);

  a.matrix[0][0] = 3.0;
  a.matrix[0][1] = 2.0;
  a.matrix[1][0] = 1.0;
  a.matrix[1][1] = 0.0;

  b.matrix[0][0] = 3.0;
  b.matrix[0][1] = 2.0;
  b.matrix[1][0] = 1.0;
  b.matrix[1][1] = 0.0;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_2x2_2) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);

  a.matrix[0][0] = 3.5643;
  a.matrix[0][1] = -2.0;
  a.matrix[1][0] = 1.2100001;
  a.matrix[1][1] = 0.31428;

  b.matrix[0][0] = 3.5643;
  b.matrix[0][1] = -2.0;
  b.matrix[1][0] = 1.2100001;
  b.matrix[1][1] = 0.31428;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_2x2_3) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);

  a.matrix[0][0] = 33000.5643;
  a.matrix[0][1] = -2.5676897;
  a.matrix[1][0] = -1000.2100001;
  a.matrix[1][1] = 0.0000001;

  b.matrix[0][0] = 33000.5643;
  b.matrix[0][1] = -2.5676897;
  b.matrix[1][0] = -1000.2100001;
  b.matrix[1][1] = 0.0000001;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_3x3_1) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);

  a.matrix[0][0] = 3300.5643;
  a.matrix[0][1] = -2.5676897;
  a.matrix[0][2] = -20000.564610;
  a.matrix[1][0] = -1000.2100001;
  a.matrix[1][1] = 0.0000001;
  a.matrix[1][2] = 0.0;
  a.matrix[2][0] = 0.0000023;
  a.matrix[2][1] = 0.0;
  a.matrix[2][2] = 0.0000456;

  b.matrix[0][0] = 3300.5643;
  b.matrix[0][1] = -2.5676897;
  b.matrix[0][2] = -20000.564610;
  b.matrix[1][0] = -1000.2100001;
  b.matrix[1][1] = 0.0000001;
  b.matrix[1][2] = 0.0;
  b.matrix[2][0] = 0.0000023;
  b.matrix[2][1] = 0.0;
  b.matrix[2][2] = 0.0000456;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_3x3_2) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);

  a.matrix[0][0] = 330000.5643;
  a.matrix[0][1] = -20054.5676897;
  a.matrix[0][2] = -20000.564610;
  a.matrix[1][0] = -1000.2100001;
  a.matrix[1][1] = 0.0000001;
  a.matrix[1][2] = -89070.02357957;
  a.matrix[2][0] = 0.0000023;
  a.matrix[2][1] = 1000000.0;
  a.matrix[2][2] = 4567783.0000456;

  b.matrix[0][0] = 330000.5643;
  b.matrix[0][1] = -20054.5676897;
  b.matrix[0][2] = -20000.564610;
  b.matrix[1][0] = -1000.2100001;
  b.matrix[1][1] = 0.0000001;
  b.matrix[1][2] = -89070.02357957;
  b.matrix[2][0] = 0.0000023;
  b.matrix[2][1] = 1000000.0;
  b.matrix[2][2] = 4567783.0000456;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_noteq_1x1_1) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = -10.5;
  b.matrix[0][0] = -10.49;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_noteq_1x1_2) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = 0;
  b.matrix[0][0] = 0.000001;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_noteq_1x1_3) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = 3;
  b.matrix[0][0] = 1000.0000000001;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_noteq_1x1_4) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = -56;
  b.matrix[0][0] = 1000.0451;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_noteq_2x2_1) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);

  a.matrix[0][0] = 3.5643;
  a.matrix[0][1] = -2.0;
  a.matrix[1][0] = 1.2;
  a.matrix[1][1] = 0;

  b.matrix[0][0] = 3.5643;
  b.matrix[0][1] = -2.0;
  b.matrix[1][0] = 1.2100001;
  b.matrix[1][1] = 0.31428;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_noteq_2x2_2) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);

  a.matrix[0][0] = 0;
  a.matrix[0][1] = 0;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 0.000001;

  b.matrix[0][0] = 0;
  b.matrix[0][1] = 0;
  b.matrix[1][0] = 0;
  b.matrix[1][1] = 0;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_noteq_3x3_1) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);

  a.matrix[0][0] = 330000.5643;
  a.matrix[0][1] = -20054.5676897;
  a.matrix[0][2] = -20000.564610;
  a.matrix[1][0] = -1000.2100001;
  a.matrix[1][1] = 0.0000001;
  a.matrix[1][2] = -89070.02357957;
  a.matrix[2][0] = 0.0000023;
  a.matrix[2][1] = 10000.0;
  a.matrix[2][2] = 4567783.0000456;

  b.matrix[0][0] = 330000.5643;
  b.matrix[0][1] = -20054.5676895;
  b.matrix[0][2] = -20.564610;
  b.matrix[1][0] = -1000.2100001;
  b.matrix[1][1] = 0.0000001;
  b.matrix[1][2] = -89070.02357957;
  b.matrix[2][0] = 0.0000023;
  b.matrix[2][1] = 1000000.0;
  b.matrix[2][2] = 4567783.0000456;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_noteq_3x3_2) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = -1;
  a.matrix[0][2] = 0;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 0.0000001;
  a.matrix[1][2] = 0;
  a.matrix[2][0] = 0;
  a.matrix[2][1] = 0;
  a.matrix[2][2] = 0;

  b.matrix[0][0] = 0;
  b.matrix[0][1] = 0;
  b.matrix[0][2] = 0;
  b.matrix[1][0] = 0;
  b.matrix[1][1] = 0;
  b.matrix[1][2] = 0;
  b.matrix[2][0] = 0;
  b.matrix[2][1] = 0;
  b.matrix[2][2] = 0;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_err_eq_1) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(2, 2, &b);

  a.matrix[0][0] = -10.5;
  b.matrix[0][0] = -10.49;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_err_eq_2) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(5, 5, &a);
  s21_create_matrix(2, 2, &b);

  a.matrix[0][0] = -10.5;
  b.matrix[0][0] = -10.49;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_err_eq_3) {
  matrix_t a;
  matrix_t b = {NULL, 0, 0};
  s21_create_matrix(5, 5, &a);

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_err_eq_4) {
  matrix_t a = {NULL, 0, 0};
  matrix_t b = {NULL, 0, 0};

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_err_eq_5) {
  matrix_t a = {NULL, 0, 0};
  matrix_t b;
  s21_create_matrix(5, 5, &b);

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

Suite *equal_matrix() {
  Suite *s = suite_create("EQUAL_MATRIX");
  TCase *tc1 = tcase_create("tc_iseq_matrix");
  TCase *tc2 = tcase_create("tc_isnoteq_matrix");
  TCase *tc3 = tcase_create("tc_null_matrix");

  tcase_add_test(tc1, test_eq_1x1_1);
  tcase_add_test(tc1, test_eq_1x1_2);
  tcase_add_test(tc1, test_eq_1x1_3);
  tcase_add_test(tc1, test_eq_1x1_4);
  tcase_add_test(tc1, test_eq_1x1_5);
  tcase_add_test(tc1, test_eq_2x2_1);
  tcase_add_test(tc1, test_eq_2x2_2);
  tcase_add_test(tc1, test_eq_2x2_3);
  tcase_add_test(tc1, test_eq_3x3_1);
  tcase_add_test(tc1, test_eq_3x3_2);

  tcase_add_test(tc2, test_noteq_1x1_1);
  tcase_add_test(tc2, test_noteq_1x1_2);
  tcase_add_test(tc2, test_noteq_1x1_3);
  tcase_add_test(tc2, test_noteq_1x1_4);
  tcase_add_test(tc2, test_noteq_2x2_1);
  tcase_add_test(tc2, test_noteq_2x2_2);
  tcase_add_test(tc2, test_noteq_3x3_1);
  tcase_add_test(tc2, test_noteq_3x3_2);

  tcase_add_test(tc3, test_err_eq_1);
  tcase_add_test(tc3, test_err_eq_2);
  tcase_add_test(tc3, test_err_eq_3);
  tcase_add_test(tc3, test_err_eq_4);
  tcase_add_test(tc3, test_err_eq_5);

  suite_add_tcase(s, tc1);
  suite_add_tcase(s, tc2);
  suite_add_tcase(s, tc3);

  return s;
}
