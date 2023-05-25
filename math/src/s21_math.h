#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <float.h>

#define S21_PI 3.14159265358979323846264338327950288
#define S21_PI 3.14159265358979323846264338327950288
#define S21_PI_2 1.570796326794896558
#define S21_PI_3 1.047197551196597853
#define S21_PI_6 0.523598775598298926
#define S21_PI_4 0.785398163397448309

#define S21_EXP 2.7182818284590452353602874713526624
#define S21_EPS 1e-6

#define S21_INF 1.0 / 0.0
#define S21_NAN -(0.0f / 0.0f)

#define S21_DBL_MAX 1E+37
#define S21_DBL_MIN 1E-37

typedef long unsigned s21_size_t;

#define is_fin(x) __builtin_isfinite(x)
#define is_nan(x) __builtin_isnan(x)
#define is_inf(x) __builtin_isinf(x)

int s21_abs(int num);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_fabs(double x);
long double s21_exp(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_exp(double x);
long double s21_powi(double base, int exp);
long double s21_log(double x);

long int s21_factorial(int n);


#endif  // SRC_S21_MATH_H_
