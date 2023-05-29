#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (A != NULL && B != NULL && A->matrix != NULL && B->matrix != NULL) {
    if (A->columns == B->rows) {
      res = s21_create_matrix(A->rows, B->columns, result);
      if (res == OK) {
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            double sum = 0;
            for (int k = 0; k < A->columns; k++) {
              sum += A->matrix[i][k] * B->matrix[k][j];
            }
            result->matrix[i][j] = sum;
          }
        }
      }
    } else {
      res = CALC_ERROR;
    }
  } else {
    res = ERROR;
  }
  return res;
}
