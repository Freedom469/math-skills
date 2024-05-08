#include <math.h>

int VarianceAndStdDeviation(int *ArrInt, int len, int average) {
    double variance = 0;
    int rem = 0;
    for (int i = 0; i < len; i++) {
        rem += (ArrInt[i] - average) * (ArrInt[i] - average);
    }

    variance = rem / len;

    return ceil(variance);
}