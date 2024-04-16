#include "file_handler.h"

int FileHandler::read_matrix_from_file(std::string file, std::vector<std::vector<int>>& input) {
	std::ifstream in_file(file);

	if(!in_file.is_open()) {
		printf("Couldn't open the file\n");
		return -1;
	}

	std::string line;

	while (std::getline(in_file, line)) {
		std::vector<int> tmp; 
		if (split_arr_string(tmp, line) < 0) {
			printf("File corrupt\n");
			in_file.close();
			return -1;
		}

		std::vector<int> row;
		for (int i = 0; i < tmp.size(); i++) {
			int cell = 0;
			row.push_back(tmp[i]);
		}
		input.push_back(row);
	}
	in_file.close();
	return 0;
}

int FileHandler::write_matrix_to_file(std::string file, std::vector<std::vector<int>>& input) {
	std::ofstream out_file(file);

	if(!out_file.is_open()) {
		printf("Couldn't open the file\n");
		return -1;
	}

	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input[i].size(); j++) {
			out_file << input[i][j] << ' ';
		}
		out_file << std::endl;
	}

	out_file.close();
	return 0;
}

/* Splits the string and using string_to_int converts into numbers */

int FileHandler::split_arr_string(std::vector<int>& tokens, std::string& line) {
	std::string delimiter = " ";
    size_t pos = 0;
    std::string token;
	int num = 0;

    while ((pos = line.find(delimiter)) != std::string::npos) {
		num = 0;
        token = line.substr(0, pos);
		if (string_to_int(token, num)) {
			return -1;
		}
        tokens.push_back(num);
        line.erase(0, pos + delimiter.size());
    }
	num = 0;
    
	if (string_to_int(line, num)) {
		return -1;
	}
    tokens.push_back(num);
	return 0;
}

bool FileHandler::string_to_int(std::string& str, int& cell) {
	int idx = 0;
	bool minus_flag = 0;
	if (str[idx] == '-') {
		idx++;
		minus_flag = 1;
	}

	while (str[idx]) {
		if (str[idx] <= '9' || '0' >= str[idx]) {
			cell *= 10;
			cell += str[idx] - '0';
			idx++;
			continue;
		}
		return 1;
	}

	if (minus_flag) {
		cell = -cell;
	}
	return 0;
}

