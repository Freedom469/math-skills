#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"

int main(int argc, char *argv[])
{
    // initializing all necessary variables
    long long int sum = 0;
    long double average = 0;
    long double median = 0;
    long double variance = 0;
    long double stdDeviation = 0;

    // reading the file from the arguments passed by user
    FILE *file;

    // checking if all requrements are met to run the programme
    if (argc != 2)
    {
        printf("Usage: ./<your Programe name> <name of the data.txt>");
        exit(-1);
    }

    // opening the input file in read mode
    file = fopen(argv[1], "r");

    // checking if the file opening was successfull
    if (file == NULL)
    {
        printf("Error reading '%s'.", argv[1]);
        exit(-1);
    }

    // reading the number of lines in the file to determine the length of the file items
    int lineCount = 0;
    int num;
    while (fscanf(file, "%d", &num) == 1)
    {
        lineCount++;
    }

    // Dynamically creating an array to store the values from the file.
    int *numbers = malloc(sizeof(int) * lineCount);

    // returning the file to start reading from the top
    rewind(file);

    int i = 0;
    // reading the values in the file and appending them to the numbers array
    while (fscanf(file, "%d", &num) == 1)
    {
        numbers[i] = num;
        i++;
    }

    // closing the file
    fclose(file);

    // Sorting the numbers in ascending order
    SortInt(numbers, lineCount);

    // calculating the median
    if (lineCount % 2 == 0)
    {
        median = (numbers[lineCount / 2 - 1] + numbers[lineCount / 2]) / 2.0;
        // printf("first: %.0lf\n second: %.0lf\n", ceil(numbers[lineCount / 2]), ceil(numbers[lineCount / 2 - 1]));
    }
    else
    {
        median = numbers[lineCount / 2];
    }

    // calculating the sum of all the values
    for (int i = 0; i < lineCount; i++)
    {
        sum += numbers[i];
    }

    // calculating the average of the given values
    average = sum / lineCount;

    // calculating the variance of the values
    for (int i = 0; i < lineCount; i++)
    {
        variance += (numbers[i] - average) * (numbers[i] - average);
    }

    // calculating the standard deviation of the values
    stdDeviation = sqrt(variance / lineCount);

    // printing out the final values
    printf("Average: %.0lf\n", ceil(average));
    printf("Median: %.0lf\n", round(median));
    printf("Variance: %.0lf\n", round(variance / lineCount));
    printf("Standard Deviation: %.0lf\n", round(stdDeviation));
    return 0;
}