#include <iostream>
#include <fstream>
#include <limits>
#include "sort.cpp" 

void sort_input(std::vector<std::vector<int>>& input, int op); 
int write_file(std::string file, std::vector<std::vector<int>>& input);
void get_input(std::string& file, int& op); 
int read_file(std::string file, std::vector<std::vector<int>>& input);
int my_split(std::vector<int>& tokens, std::string& line);  // Splits the string and using get_num converts into numbers 
bool get_num(std::string& str, int& cell);  // Converts strings into numbers

