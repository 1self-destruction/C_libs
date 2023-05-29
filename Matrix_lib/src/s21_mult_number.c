#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = OK;
  if (A != NULL && A->matrix != NULL) {
    int rows = A->rows;
    int columns = A->columns;
    int tmp = s21_create_matrix(rows, columns, result);
    if (tmp == 0) {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          result->matrix[i][j] = number * A->matrix[i][j];
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
