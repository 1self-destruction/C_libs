#include "./s21_math.h"

long double check_edges(double base, double exp) {
    long double res = 46;

    int base_nan = is_nan(base);
    int base_fin = is_fin(base);
    int exp_nan = is_nan(exp);
    int exp_fin = is_fin(exp);
    int exp_is_int = ((exp - (int) exp) < S21_EPS) || (((int) exp - exp) < S21_EPS);
    int base_is_int = ((base - (int) base) < S21_EPS) || (((int) base - base) < S21_EPS);

    if (!exp_fin && !exp_nan && base == -1) {
        res = (long double)(-base);
    } else if (exp_nan && base == 1.) {
        res = 1;
    } else if (base_fin && (base > 0 && base <= S21_EPS) &&  \
        !exp_nan && exp_is_int && exp < 0) {
        res = S21_INF;
    } else if (base_fin && (base < 0 && base >= -S21_EPS) &&  \
        !exp_nan && exp_is_int && exp < 0) {
        res = -1 * S21_INF;
    } else if (base_fin && (base_is_int && (base >= -S21_EPS && base <= S21_EPS)) &&  \
                !exp_nan && exp_fin) {
        if (exp == 0) {
            res = 1;
        } else if (exp > 0) {
            res = 0;
        } else {
            res = S21_INF;
        }
    } else if (base_fin && (base >= -S21_EPS && base <= S21_EPS) &&  \
                !exp_fin && !exp_nan) {
        if (exp > 0) {
            res = 0;
        } else {
            res = S21_INF;
        }
    } else if (!base_fin && !base_nan && base > 0 && exp_fin) {
        if (exp > 0) {
            res = S21_INF;
        } else if (exp == 0) {
            res = 1;
        } else {
            res = 0;
        }
    } else if (!base_fin && !base_nan && base < 0 && exp_fin) {
        if (exp > 0) {
            res = -S21_INF;
        } else if (exp == 0) {
            res = 1;
        } else {
            res = -0;
        }
    } else if (base_nan && exp_fin && (exp < -S21_EPS || exp > S21_EPS)) {
        res = S21_NAN;
    } else if (base_nan && exp_nan) {
        res = S21_NAN;
    } else if (base_fin && exp_nan) {
        res = S21_NAN;
    } else if (base_nan && (exp >= -S21_EPS && exp <= S21_EPS)) {
        res = 1;
    } else if ((base < 1 && base > 0) && (!exp_fin && !exp_nan)) {
        if (exp > 0) {
            res = 0;
        } else {
            res = S21_INF;
        }
    } else if ((base > -1 && base < 0) && (!exp_fin && !exp_nan)) {
        if (exp > 0) {
            res = 0;
        } else {
            res = S21_INF;
        }
    } else if (base > 1 && (!exp_fin && !exp_nan)) {
        if (exp > 0) {
            res = S21_INF;
        } else {
            res = 0;
        }
    } else if (base < -1 && (!exp_fin && !exp_nan)) {
        if (exp > 0) {
            res = -S21_INF;
        } else {
            res = 0;
        }
    }

    return res;
}

long double s21_powi(double base, int exp) {
    double res = 1;

    while (exp) {
      if (exp & 1) {
        res *= base;
      }
      base *= base;
      exp >>= 1;
    }

    return res;
}

long double _powf(double base, double exp) {
    return s21_exp(exp * s21_log(base));
}

long double s21_pow(double base, double exp) {
    double res = 1;
    res = check_edges(base, exp);

    if (res == 46) {
        int inverce = 0;

        if (exp < 0) {
            exp = (-1) * exp;
            inverce = 1;
        }
        double pow_int = 1;
        double pow_fract = 1;

        pow_int = s21_powi(base, (long int) exp);

        if ((exp - (long int) exp) != 0 && ((long int) base != 0))
            pow_fract = _powf(base, exp - (long int) exp);

        res = pow_int * pow_fract;

        if (inverce) res = 1.0 / res;
    }

    return res;
}
