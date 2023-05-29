#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = OK;
  if (A != NULL && A->matrix != NULL) {
    if (A->columns == A->rows) {
      int grade = A->rows;
      if (grade == 1) {
        *result = A->matrix[0][0];
      } else if (grade == 2) {
        *result = (A->matrix[0][0] * A->matrix[1][1]) -
                  (A->matrix[0][1] * A->matrix[1][0]);
      } else if (grade > 2) {
        *result = 0.0;
        for (int j = 0; j < grade; j++) {
          matrix_t buffer = {NULL, 0, 0};
          s21_create_matrix(grade - 1, grade - 1, &buffer);
          fill_minor(A, &buffer, 0, j);
          double minor_determinant = 0;
          s21_determinant(&buffer, &minor_determinant);
          s21_remove_matrix(&buffer);
          *result += pow(-1, j) * A->matrix[0][j] * (minor_determinant);
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
