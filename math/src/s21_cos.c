#include "s21_math.h"

// release_cos_v1.0
long double s21_cos(double x) {
    long double ret = 1.0;

    for (; (x < -2*S21_PI || 2*S21_PI < x) && !is_inf(x);) {
        if (x > 2*S21_PI) {
            x -= 2*S21_PI;
        } else {
            x += 2*S21_PI;
        }
    }

    if (x == 0 || x == 2*S21_PI || x == -2*S21_PI) {
        return ret;
    } else if (x == S21_NAN || x == S21_INF || x == -S21_INF) {
        return S21_NAN;
    } else if (x == -S21_PI || x == S21_PI) {
        ret = -ret;
        return ret;
    } else {
        long double val = 1.0;

        for (int k = 1; s21_fabs(val / ret) > 1e-100; k++) {
            val = (-val * x * x) / ((2.0 * k - 1) * (2.0 * k));
            ret += val;
        }
    }

    return ret;
}

// my_cos_v0.9
// long double s21_cos(double x) {
//    long double ret = 1.0;
//
//    for (; (x < -2*S21_PI || 2*S21_PI < x) && !is_inf(x);) {
//        if (x > 2*S21_PI) {
//            x -= 2*S21_PI;
//        } else {
//            x += 2*S21_PI;
//        }
//    }
//
//    if (x == 0 || x == 2*S21_PI || x == -2*S21_PI) {
//        return ret;
//    } else if (x == S21_NAN || x == S21_INF || x == -S21_INF) {
//        return S21_NAN;
//    } else if (x == -S21_PI || x == S21_PI) {
//        ret = -ret;
//        return ret;
//    } else {
//        long double val = 0.;
//        for(int k = 1; k < 500; k++) {
//            val = s21_powi((-1.0), k) * s21_powi(x, 2 * k) / s21_factorial(2 * k);
//            ret += val;
//        }
//    }
//
//    return ret;
// }
