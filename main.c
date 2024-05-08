#include <stdio.h>
#include <stdlib.h>
#include "maths.h"

int main(int argc, char *argv[])
{
	double average = 0;
	double median = 0;
	double variance = 0;
	double deviation = 0;

	if (argc != 2)
	{
		printf("Usage: ./<your-programName> <data.txt>\n");
		exit(EXIT_FAILURE);
	}
	FILE *file;

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("The Provided File '%s' Does Not Exist.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	char dummyBuffer[10000];
	int length = 0;
	while (fgets(dummyBuffer, sizeof(dummyBuffer), file))
	{
		length++;
	}

	if (length == 0)
	{
		printf("File '%s' Is Empty\n", argv[1]);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	rewind(file);
	int sum = 0;
	int *numbers = malloc(length * sizeof(int)); // Allocate memory for storing integers
	if (numbers == NULL)
	{
		printf("Memory allocation failed.\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}

	int i = 0;
	while (fgets(dummyBuffer, sizeof(dummyBuffer), file))
	{
		// printf("%s", dummyBuffer);
		int num = atoi(dummyBuffer);
		sum += num;
		numbers[i++] = num;
	}

	SortInt(numbers, length);
	// printf("The sum of the file content is: %d\n", sum);
	// printf("The length of the file is: %d\n", length);

	average = sum / length;

	if (length % 2 == 1)
	{
		median = numbers[length / 2];
	}
	else
	{
		int first = numbers[length / 2];
		int sec = numbers[length / 2 - 1];
		median = (first + sec) / 2;
	}

	variance = VarianceAndStdDeviation(numbers, length, average);
	int round_variance = ceil(variance);
	int round_median = ceil(median);
	int round_average = ceil(average);
	deviation = StandardDeviation(variance);
	int round_deviation = ceil(deviation);
	printf("Average: %d\n", round_average);
	printf("Median: %d\n", round_median);
	printf("Variance: %d\n", round_variance);
	printf("Standard Deviation: %d\n", round_deviation);
	fclose(file);
	free(numbers); // Free dynamically allocated memory
	return 0;
}
