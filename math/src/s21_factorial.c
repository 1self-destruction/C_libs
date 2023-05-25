#include "s21_math.h"

long int s21_factorial(int n) {
    long double res = 1;

    if (n >= 0) {
        if (n != 0) {
            int arr[n + 1][2];

            for (int i = 0; i < n + 1; i++) {
                arr[i][0] = i;
                arr[i][1] = 0;
            }

            arr[1][0] = 0;

            for (int i = 2; i < n + 1; i++) {
                if (arr[i][0] != 0) {
                    for (int j = i*2; j < n + 1; j += i) {
                        arr[j][0] = 0;
                    }
                }

                if (arr[i][0] != 0) {
                    int k = (int) n / i;
                    while (k > 0) {
                        arr[i][1] += k;
                        k /= i;
                    }
                }
            }

            for (int i = 0; i < n + 1; i++) {
                if (arr[i][0] != 0) {
                    res *= s21_pow(arr[i][0], arr[i][1]);
                }
            }
        }
    } else {
        res = 0;
    }

    return res;
}
