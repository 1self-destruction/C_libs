#include "s21_math.h"

long double s21_sin(double x) {
    int n = 0;
    long double res = 0;
    int sign = 1;

    if (is_nan(x) || x == -S21_INF || x == S21_INF) {
        res = S21_NAN;
    } else {
        if (x < 0) {
            x = -x;
            sign = -1;
        }

        while (x >= S21_PI) {
            x -= S21_PI;
            sign *= -1;
        }

        if (x - S21_EPS <= 2 * S21_PI && x + S21_EPS >= 2 * S21_PI) {
            res = 0;
        } else if (x - S21_EPS <= S21_PI / 2 && x + S21_EPS >= S21_PI / 2) {
            res = 1;
        } else {
            long double arg = 1;

            while (S21_EPS < arg && n <= 100) {
                arg = s21_pow((-1), n) * 1.0 / s21_factorial(2 * n + 1) * s21_pow(x, 2 * n + 1);
                res += arg;

                if (arg < 0) arg = (-1) * arg;
                n++;
            }
        }
    }

    return res * sign;
}
