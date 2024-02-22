#include "pixel.hpp"

class Image {
public:
	Image();
	void init(int row, int col);   // Creates a black image.
	void create_rand_img(int row, int col);
	friend std::ostream& operator<<(std::ostream& os, const Image& imag);
	void print_pixel(int x, int y);
	Pixel& pixel(int x, int y);   // Pixel setter & getter.
	void clear();
	~Image();
	
private:
	std::vector<std::vector<Pixel>> m_img;
	size_t m_rows;
	size_t m_cols;
};

