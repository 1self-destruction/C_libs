#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (A != NULL && A->matrix != NULL) {
    int rows = A->rows;
    int columns = A->columns;
    int tmp = s21_create_matrix(columns, rows, result);
    if (tmp == 0) {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    } else {
      res = ERROR;
    }
  } else {
    res = ERROR;
  }
  return res;
}
