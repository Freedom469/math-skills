# Statistical Analysis Program

This program reads a list of integers from a file, calculates various statistical measures, and prints the results.

## Usage

To use the program, compile the source code using the provided Makefile and run the executable with the input file as a command-line argument:

```bash
make
./programName input.txt
Input File Format
The input file should contain a list of integers, each on a separate line.

## Output
The program calculates the following statistical measures:

Average
Median
Variance
Standard Deviation
The results are printed to the console.

## Testing
To test the program:

Prepare an input file with a list of integers.
Run the program with the input file as an argument.
Verify that the output matches the expected statistical measures for the input data.

## Input Example
Input:
1
2
3
4
5

## Output Example
Output:
Average: 3
Median: 3
Variance: 2
Standard Deviation: 1

## Dependencies
The program depends on the following header file:

utils.h
Make sure to include it in your project.

## Compilation
Compile the program using the provided Makefile. Simply run the following command:

make

This will compile the source code and create an executable named programName.

## License
This program is provided under the MIT License.