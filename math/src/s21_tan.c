#include "s21_math.h"
#include <stdio.h>

long double s21_tan(double x) {
    long double res = 0;

    if (is_nan(x)) {
        res = S21_NAN;
    } else if (x == S21_PI / 2) {
        res = 16331239353195370L;
    } else if (x == -S21_PI / 2) {
        res = -16331239353195370L;
    } else {
        res = s21_sin(x) / s21_cos(x);
    }

    return res;
}
