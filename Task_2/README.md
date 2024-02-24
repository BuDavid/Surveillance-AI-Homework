# File Matrix Sorter | Class implementation

## Description
    This is a simple program that sorts matrix stored in a file.
    The program prompts the user to input the file name and select a sorting option. 
    After receiving the input, it executes the sorting algorithm on the matrix within the file and saves the output to a new file.

## Code Testing
    For code compilation use cmake. 
    To test the code, a test file named 'matrix.txt' is provided in the test directory.

```terminal
$ cmake ./ 

$ make 
```
```css
.terminal {
    background-color: black;
    color: white;
    font-family: 'Courier New', Courier, monospace;
    padding: 10px;
    border-radius: 5px;
}
```

## Showcase

```C++
#include "sorting_application.cpp" 

int main() {

	SortingApplication app;

	if (app.start_application() == 1) {
		printf("error\n");
		return 1;
	}
	printf("success\n");
}
```
