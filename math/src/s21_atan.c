#include "s21_math.h"

long double s21_atan(double x) {
    long double y;

    if (x == S21_INF) {
        y = S21_PI_2;
    } else if (x == -S21_INF) {
        y = -S21_PI_2;
    } else {
        long double dx, abs;
        int n = 1, flag = 0, flagBad = 0;
        if (x < 0) {
            flagBad = 1;
            x *= -1;
        }
        if (x > 1) {
            x = 1/x;
            flag = 1;
        }
        dx = x;
        y = x;
        abs = x;
        if (x != 1) {
            while (abs > 0.000000000000001) {
                ++n;
                dx *= -x * x * (2 * n - 3) / (2 * n - 1);
                y += dx;
                if (dx < 0) {
                    abs *= -dx;
                } else {
                    abs = dx;
                }
            }
        } else {
            y = S21_PI_4;
        }
        if (flag == 1) {
            y = S21_PI_2 - y;
        }
        if (flagBad == 1) {
            y *= -1;
        }
    }
    return y;
}
