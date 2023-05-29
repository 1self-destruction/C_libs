#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (A != NULL && B != NULL && A->matrix != NULL && B->matrix != NULL) {
    if (A->rows == B->rows && A->columns == B->columns) {
      int rows = A->rows;
      int columns = A->columns;
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1E-7) {
            res = FAILURE;
            break;
          }
        }
        if (res == FAILURE) break;
      }
    } else {
      res = FAILURE;  // calcerror
    }
  } else {
    res = FAILURE;  // error
  }
  return res;
}
