# File Array Sorter

## Description
    This is a simple program that sorts arrays stored in a file.
    The program prompts the user to input the file name and select a sorting option. 
    After receiving the input, it executes the sorting algorithm on the arrays within the file and saves the output to a new file.

## Code Testing
    To test the code, a test file named 'matrix.txt' is provided.

```C++
#include "file_op.cpp"

int main() {
	std::string file;
	int op = 0;

	get_input(file, op);

	std::vector<std::vector<int>> input;

	if (read_file(file, input) < 0) {
		return -1;
	}

	sort_input(input, op);

	if (write_file("sorted_file", input) < 0) {
		return -1;
	}
}
```
