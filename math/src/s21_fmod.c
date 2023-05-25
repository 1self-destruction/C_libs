#include "s21_math.h"

long double s21_fmod(double x, double y) {
    long double ret = 0;

    if (x == S21_INF || x == S21_NAN || y == S21_NAN) {
        return S21_NAN;
    }
    if (y != 0 && x == 0) {
        return ret;
    } else if (y == 0) {
        return S21_NAN;
    }

    long long int n = x / y;

    ret = (long double)x - n * (long double)y;

    return ret;
}
