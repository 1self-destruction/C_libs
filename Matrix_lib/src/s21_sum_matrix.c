#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (A != NULL && B != NULL && A->matrix != NULL && B->matrix != NULL) {
    if (A->rows == B->rows && A->columns == B->columns) {
      int rows = A->rows;
      int columns = A->columns;
      int tmp = s21_create_matrix(rows, columns, result);
      if (tmp == 0) {
        for (int i = 0; i < rows; i++) {
          for (int j = 0; j < columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
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
