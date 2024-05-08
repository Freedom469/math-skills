#include <math.h>
#include "../utils.h"

long double StdDeviation(int numbers[], int length, long double average){
    return sqrt(Variance(numbers, length, average));
}