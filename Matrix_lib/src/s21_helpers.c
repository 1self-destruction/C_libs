#include "s21_matrix.h"

void fill_minor(matrix_t *A, matrix_t *B, int row, int column) {
  int grade = A->rows;
  int minor_column = 0;
  int minor_row = 0;
  for (int i = 0; i < grade; i++) {
    for (int j = 0; j < grade; j++) {
      if (i != row && j != column) {
        B->matrix[minor_row][minor_column] = A->matrix[i][j];
        if (minor_column == grade - 2) {
          minor_row++;
          minor_column = 0;
        } else {
          minor_column++;
        }
      }
    }
  }
}
