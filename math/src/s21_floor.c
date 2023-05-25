#include "s21_math.h"

long double s21_floor(double x) {
    long double floor_x = (long long int)x;

    if (is_nan(x) || is_inf(x) || x == 0) return x;

    if (s21_fabs(x) > 0.) {
        if (x < 0.) {
            floor_x -= 1;
        }
    }

    return floor_x;
}
