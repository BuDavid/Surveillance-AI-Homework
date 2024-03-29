#ifndef FH
#define FH

#include <fstream>
#include <limits>
#include <vector>

class FileHandler {
public:
	int read_matrix_from_file(std::string file, std::vector<std::vector<int>>& input);
	int write_matrix_to_file(std::string file, std::vector<std::vector<int>>& input);

private:
	int split_arr_string(std::vector<int>& tokens, std::string& line);  // Splits the string and using string_to_int converts into numbers 
	bool string_to_int(std::string& str, int& cell); 
};

#endif  // FH

