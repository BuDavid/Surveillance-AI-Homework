#include "matrix.h"

Matrix::Matrix() {
	m_rows = 0;
	m_cols = 0;
}

int Matrix::count_segments() {
	std::vector<std::tuple<int, int>> seen;
	int count = 0;
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			if (m_mtx[i][j] == 1 && !(is_seen(i, j, seen))) {
				expand_segment(i, j, seen);
				count++;
			}
		}
	}
	return count;
}

// Helper function for count_segments(). Recusively expands the segment.

void Matrix::expand_segment(int i, int j, std::vector<std::tuple<int, int>>& seen) {
	if (!(i >= 0 && i < m_rows) || !(j >= 0 && j < m_cols)) {
		return;
	}

	if (is_seen(i, j, seen)) {
		return;
	}

	if (!m_mtx[i][j]) {
		return;
	}

	seen.push_back(std::make_tuple(i, j));

	expand_segment(i+1, j, seen);
	expand_segment(i-1, j, seen);
	expand_segment(i, j+1, seen);
	expand_segment(i, j-1, seen);
}

// Helper function for count_segments(). Checks if the cell has been seen.

bool Matrix::is_seen(int x, int y, std::vector<std::tuple<int, int>>& seen) {
    auto tmp = std::find(seen.begin(), 
                         seen.end(), 
                         std::make_tuple(x, y));

	return tmp == seen.end() ? false : true;
}

void Matrix::invert() {
	if (m_mtx.empty()) {
		return;
	}
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			m_mtx[i][j] = !m_mtx[i][j];
		}
	}
}

void Matrix::reverse() {
	if (m_mtx.empty()) {
		return;
	}
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols/2; j++) {
			std::swap(m_mtx[i][j], m_mtx[i][m_cols-1-j]);
		}
	}
}

std::ostream& operator<< (std::ostream& os, const Matrix& matrix) {
	if (matrix.m_mtx.empty()) {
		std::cerr << "Error\n";
		return os;
	}
	for (int i = 0; i < matrix.m_rows; i++) {
		for (int j = 0; j < matrix.m_cols; j++) {
			if (matrix.m_mtx[i][j]) {
				os << GREEN << 1 << RESET << ' ';
			} else {
				os << BLUE << 0 << RESET << ' ';
			}
		}
		os << std::endl;
	}
	os << std::endl;
	return os;
}

// Cell setter and getter.

int& Matrix::cell(int x, int y) {
	if (x >= m_rows || y >= m_cols) {
		std::cerr << "Error" << std::endl;
	}
	return m_mtx[x][y];
}

// Creates a matrix randomly filled with ones and zeros.

void Matrix::init(int row, int col) {
	srand(time(0));
	for (int i = 0; i < row; i++) {
		std::vector<int> tmp;
		for (int i = 0; i < col; i++) {
			tmp.push_back(rand() % 2);
		}
		m_mtx.push_back(tmp);
	}
	m_rows = row;
	m_cols = col;
}

void Matrix::clear() {
	m_mtx.clear();
	m_rows = 0;
	m_cols = 0;
}

Matrix::~Matrix() {
	clear();
}

