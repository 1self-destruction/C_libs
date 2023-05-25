#include "s21_math.h"

long double s21_exp(double x) {
    long double ret = 1, tmp = 1;
    long double i = 1;
    int flag_sign = 0;

    if (x < 0) {
        x *= -1;
        flag_sign = 1;
    }

    while (s21_fabs(tmp) > S21_EPS / 10) {
        tmp *= x / i;
        i += 1;
        ret += tmp;
        if (ret > DBL_MAX) {
            ret = S21_INF;
            break;
        }
    }

    if (flag_sign == 1) {
        if (ret > DBL_MAX) {
          ret = 0;
        } else {
          ret = 1. / ret;
        }
    }

    return ret;
}
