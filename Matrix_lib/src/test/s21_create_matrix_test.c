#include "s21_tests_suite.h"

START_TEST(test_create_1) {
  matrix_t m;
  int result = s21_create_matrix(5, 7, &m);

  ck_assert_int_eq(m.columns, 7);
  ck_assert_int_eq(m.rows, 5);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_create_2) {
  matrix_t m;
  int result = s21_create_matrix(1, 1, &m);

  ck_assert_int_eq(m.columns, 1);
  ck_assert_int_eq(m.rows, 1);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_create_3) {
  matrix_t m;
  int result = s21_create_matrix(100, 100, &m);

  ck_assert_int_eq(m.columns, 100);
  ck_assert_int_eq(m.rows, 100);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_create_4) {
  matrix_t m;
  int result = s21_create_matrix(0, 10, &m);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_create_5) {
  matrix_t m;
  int result = s21_create_matrix(2, 0, &m);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_create_6) {
  matrix_t m;
  int result = s21_create_matrix(-1, 0, &m);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_create_7) {
  matrix_t m;
  int result = s21_create_matrix(0, 0, &m);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_create_8) {
  matrix_t m;
  int result = s21_create_matrix(-10, -10, &m);
  ck_assert_int_eq(result, 1);
}
END_TEST

Suite *create_matrix() {
  Suite *s = suite_create("CREATE_MATRIX");
  TCase *tc1 = tcase_create("tc_create_matrix");
  TCase *tc2 = tcase_create("tc_create_error_matrix");

  tcase_add_test(tc1, test_create_1);
  tcase_add_test(tc1, test_create_2);
  tcase_add_test(tc1, test_create_3);

  tcase_add_test(tc2, test_create_4);
  tcase_add_test(tc2, test_create_5);
  tcase_add_test(tc2, test_create_6);
  tcase_add_test(tc2, test_create_7);
  tcase_add_test(tc2, test_create_8);

  suite_add_tcase(s, tc1);
  suite_add_tcase(s, tc2);

  return s;
}
