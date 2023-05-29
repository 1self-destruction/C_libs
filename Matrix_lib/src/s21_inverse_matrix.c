#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = OK;
  double r;
  if (A == NULL || A->rows < 1 || A->columns < 1) {
    res = ERROR;
  } else if (A->columns != A->rows) {
    res = ERROR;
  } else if (!s21_determinant(A, &r) && !r) {
    res = CALC_ERROR;
  } else {
    matrix_t complements, transpose;
    s21_calc_complements(A, &complements);
    s21_transpose(&complements, &transpose);
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = 1 / r * transpose.matrix[i][j];
      }
    }
    s21_remove_matrix(&complements);
    s21_remove_matrix(&transpose);
  }
  return res;
}
