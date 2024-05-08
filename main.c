#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(int argc, char *argv[]){
    long double sum = 0;
    long double average = 0;
    long double variance = 0;
    long double stdDeviation = 0;
    long double median = 0;

    if (argc != 2){
        printf("Usage: ./<prgrameName> <inputFile>\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        printf("File not found\n");
        return 1;
    }
    int length = 0;
    char dummyBuffer[10000];
    while (fgets(dummyBuffer, 10000, file) != NULL){
        length++;
    }
    if (length == 0){
        printf("File is empty\n");
        return 1;
    } else {
        rewind(file);
        int numbers[length];
        int i = 0;
        while(fgets(dummyBuffer, 10000, file) != NULL){
            numbers[i++] = atoi(dummyBuffer);
            sum += atoi(dummyBuffer);
        }

        // for (int i = 0; i < length; i++){
        //     printf("%d\n", numbers[i]);
        // }
    BubbleSort(numbers, length);
    
    if (length % 2 == 0){
        median = (numbers[length / 2 - 1] + numbers[length / 2]) / 2;
    } else {
        median = numbers[length / 2];
    }
    average = sum / length;
    variance = Variance(numbers, length, average);
    stdDeviation = StdDeviation(numbers, length, average);
    }
    // printf("Length of file: %d\n", length);
    // printf("Sum of all numbers: %.0Lf\n", round(sum));
    printf("Average: %.0Lf\n", round(average));
    printf("Median: %.0Lf\n", ceil(median));
    printf("Variance: %.0Lf\n", round(variance));
    printf("Standard deviation: %.0Lf\n", round(stdDeviation));
    
}