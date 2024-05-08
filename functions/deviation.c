#include <math.h>

int StandardDeviation(int variance) {
    double res = 0;
    res = sqrt(variance);

    return ceil(res);
}