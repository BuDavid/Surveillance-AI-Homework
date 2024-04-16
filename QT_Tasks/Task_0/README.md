# Surveillance AI
## Description
	This project is a homework assignment. It is comprised of 3 tasks.
	The libraries are included in header files for convenience.
# Components
	Tasks:
		1. Simple image implementation.
		2. Matrix reversal and inversion.
		3. Matrix segmentation.
# Task 1
	The task is solved using 2 classes: Pixel and Image. 
	The latter depends on the former.

	Test code:
```C++
#include "image.hpp"

int main() {
	Image img;
	img.create_rand_img(5, 5);
	std::cout << img;
	img.pixel(2, 1) = {1, 234, 53};
	img.pixel(0, 0).set_red(65);
	std::cout << img;
}
```

# Task 2
	Both tasks 2 and 3 are solved using Matrix class.
	The task is solved using reverse() and invert() methods.

	Test code:
```C++
#include "matrix.hpp"

int main() {
	Matrix matrix;
	matrix.init(10, 15);
	std::cout << matrix;
	matrix.reverse();
	std::cout << matrix;
	matrix.invert();
	std::cout << matrix;
}
```

# Task 3
	Both tasks 2 and 3 are solved using Matrix class.
	The task is solved using count_segments(), expand_segment() and is_seen() methods.

	Test code:
```C++
#include "matrix.hpp"

int main() {
	Matrix matrix;
	matrix.init(12, 13); 
	std::cout << matrix;
	std::cout << matrix.count_segments() << std::endl;
}
```
	
