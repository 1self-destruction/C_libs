#include "s21_math.h"

// https://en.wikipedia.org/wiki/Natural_logarithm#High_precision

long double s21_log(double x) {
    long double res = 0;
    long double arg = 1;
    int exp_pow = 0;

    if (x == S21_INF) {
        res = S21_INF;
    } else if (x == 0) {
        res = -S21_INF;
    } else if (x < 0) {
        res = -S21_NAN;
    } else if (x == 1) {
        res = 0;
    } else {
        for (; x >= S21_EXP; x /= S21_EXP, exp_pow++) continue;

        while (S21_EPS < (arg - res) || S21_EPS < (res - arg)) {
            arg = res;
            res = arg + 2 * (x - s21_exp(arg)) / (x + s21_exp(arg));
            // if (++n > 100) break;
        }
    }

    return res + exp_pow;
}
