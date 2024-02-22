#include "image.h"

Image::Image() {
	m_rows = 0;
	m_cols = 0;
}

// Creates a black image.

void Image::init(int row, int col) {
	std::vector<Pixel> tmp;
	Pixel pix_tmp;
	for (int i = 0; i < col; i++) {
		tmp.push_back(pix_tmp);
	}

	for (int i = 0; i < row; i++) {
		m_img.push_back(tmp);
	}
	m_rows = row;
	m_cols = col;
}

void Image::create_rand_img(int row, int col) {
	clear();
	srand(time(0));
	std::vector<Pixel> tmp;
	Pixel pix_tmp;
	for (int i = 0; i < col; i++) {
		pix_tmp = {rand() % 255,
				   rand() % 255,
				   rand() % 255};
		tmp.push_back(pix_tmp);
	}

	for (int i = 0; i < row; i++) {
		m_img.push_back(tmp);
	}
	m_rows = row;
	m_cols = col;
}

std::ostream& operator<<(std::ostream& os, const Image& image) {
	if (image.m_img.empty()) {
		return os;
	}
	for (int i = 0; i < image.m_rows; i++) {
		for (int j = 0; j < image.m_cols; j++) {
			os << image.m_img[i][j] << ' ';
		}
		os << std::endl;
	}
	return os;
}

void Image::print_pixel(int x, int y) {
	if (x >= m_cols || y >= m_rows) {
		std::cerr << "Out of range\n";
		return;
	}
	std::cout << m_img[x][y];
}

// Pixel setter and getter.

Pixel& Image::pixel(int x, int y) {
	if (x >= m_cols || y >= m_rows) {
		std::cerr << "Out of range\n";
	}
	return m_img[x][y];
}

void Image::clear() {
	m_img.clear();
	m_rows = 0;
	m_cols = 0;
}

Image::~Image() {
	clear();
}

