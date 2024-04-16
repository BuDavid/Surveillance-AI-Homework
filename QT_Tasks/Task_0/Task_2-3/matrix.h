#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include <algorithm>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

class Matrix {
public:
	Matrix();
	int count_segments();
	void reverse();
	void invert();
	friend std::ostream& operator<< (std::ostream& os, const Matrix& matrix); 
	int& cell(int x, int y);   // Cell setter and getter.
	void init(int row, int col); 
	void clear();
	~Matrix();

private:
	
	// Helper functions for count_segments().

	void expand_segment(int i, int j, std::vector<std::tuple<int, int>>& seen);
	bool is_seen(int x, int y, std::vector<std::tuple<int, int>>& seen);

	std::vector<std::vector<int>> m_mtx;
	size_t m_rows;
	size_t m_cols;
};

