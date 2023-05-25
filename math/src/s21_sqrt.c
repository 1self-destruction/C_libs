#include "s21_math.h"

long double s21_sqrt(double x) {
    double res = 1;
    double ort = 0;
    int sign = 1;

    if (x < 0) {
        sign = -1;
        res = S21_NAN;
    } else if (is_inf(x)) {
        res = S21_INF;
    } else if (is_nan(x)) {
        res = S21_NAN;
    } else {
        while ((ort - res) >= S21_EPS || (res - ort) >= S21_EPS) {
            ort = res;
            res = ((x / res) + res) / 2;
        }
    }

    return res * sign;
}
