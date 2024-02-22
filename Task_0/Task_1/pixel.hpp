#include "pixel.h"

Pixel::Pixel() {
	m_red = 0;
	m_green = 0;
	m_blue = 0;
}

Pixel::Pixel(const std::vector<int>& vals) {
	if (vals.size() >= 3) {
		m_red = vals[0];
		m_green = vals[1];
		m_blue = vals[2];
	} else {
		std::cerr << "Error" << std::endl;
	}
}
		
Pixel& Pixel::operator= (const std::vector<int>& vals) {
	if (vals.size() >= 3) {
		m_red = vals[0];
		m_green = vals[1];
		m_blue = vals[2];
	} else {
		std::cerr << "Error" << std::endl;
	}
	return *this;
}

std::ostream& operator<< (std::ostream& os, const Pixel& pix) {
	os << '[' << pix.m_red - 0
	   << ", " << pix.m_green - 0
	   << ", " << pix.m_blue - 0
	   << ']';

	return os;
}

void Pixel::set_red(int value) {
	if (value > 255 || value < 0) {
		return;
	}
	m_red = value;
}

void Pixel::set_green(int value) {
	if (value > 255 || value < 0) {
		return;
	}
	m_green = value;
}

void Pixel::set_blue(int value) {
	if (value > 255 || value < 0) {
		return;
	}
	m_blue = value;
}
	
int Pixel::get_red() {
	return m_red - 0;
}

int Pixel::get_green() {
	return m_green - 0;
}

int Pixel::get_blue() {
	return m_blue - 0;
}

void Pixel::clear() {
	m_red = 0;
	m_green = 0;
	m_blue = 0;
}

Pixel::~Pixel() {
	clear();
}
	
