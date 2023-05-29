#include "s21_tests_suite.h"

START_TEST(test_remove_1) {
  matrix_t a;
  s21_create_matrix(3, 3, &a);
  s21_remove_matrix(&a);

  ck_assert_int_eq(0, a.rows);
  ck_assert_int_eq(0, a.columns);
  ck_assert_ptr_eq(NULL, a.matrix);
}
END_TEST

START_TEST(test_remove_2) {
  matrix_t a;
  s21_create_matrix(100, 100, &a);
  s21_remove_matrix(&a);

  ck_assert_int_eq(0, a.rows);
  ck_assert_int_eq(0, a.columns);
  ck_assert_ptr_eq(NULL, a.matrix);
}
END_TEST

Suite *remove_matrix() {
  Suite *s = suite_create("REMOVE_MATRIX");
  TCase *tc = tcase_create("tc_remove_matrix");

  tcase_add_test(tc, test_remove_1);
  tcase_add_test(tc, test_remove_2);

  suite_add_tcase(s, tc);

  return s;
}
