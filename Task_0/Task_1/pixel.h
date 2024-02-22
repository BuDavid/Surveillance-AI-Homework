#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Pixel {
public:	
	Pixel();
	Pixel(const std::vector<int>& vals);
	Pixel& operator= (const std::vector<int>& vals);
	friend std::ostream& operator<< (std::ostream& os, const Pixel& pix); 
	void set_red(int value); 
	void set_green(int value);
	void set_blue(int value);
	int get_red(); 
	int get_green(); 
	int get_blue(); 
	void clear();
	~Pixel();
	
private:
	unsigned char m_red;
	unsigned char m_green;
	unsigned char m_blue;
};

