#include "s21_math.h"

// release_fabs_v1
long double s21_fabs(double x) {
    if (x == S21_NAN) {
        return S21_NAN;
    } else if (x == 0) {
        return 0;
    } else if (x == S21_INF) {
        return S21_INF;
    } else {
        return x < 0 ? -x : x;
    }
}
