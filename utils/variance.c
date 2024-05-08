#include <math.h>

long double Variance(int numbers[], int length, long double average){
    long double variance = 0;
    for (int i = 0; i < length; i++){
        variance += (numbers[i] - average) * (numbers[i] - average);
    }
    return variance / length;
}