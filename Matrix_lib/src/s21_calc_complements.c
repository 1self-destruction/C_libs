#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (A != NULL && A->matrix != NULL) {
    if (A->columns == A->rows) {
      int grade = A->rows;
      int tmp = s21_create_matrix(grade, grade, result);
      if (tmp == 0) {
        for (int i = 0; i < grade; i++) {
          for (int j = 0; j < grade; j++) {
            matrix_t buffer = {NULL, 0, 0};
            s21_create_matrix(grade - 1, grade - 1, &buffer);
            fill_minor(A, &buffer, i, j);  // not exist
            double minor_determinant = 0;
            s21_determinant(&buffer, &minor_determinant);  // not works
            result->matrix[i][j] = minor_determinant;
            s21_remove_matrix(&buffer);
          }
        }
        for (int i = 0; i < grade; i++) {
          for (int j = 0; j < grade; j++) {
            result->matrix[i][j] = result->matrix[i][j] * pow((-1), i + j);
          }
        }
      } else {
        res = ERROR;
      }
    } else {
      res = CALC_ERROR;
    }
  } else {
    res = ERROR;
  }
  return res;
}
