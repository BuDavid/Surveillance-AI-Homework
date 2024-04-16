#ifndef SA
#define SA

#include <iostream>
#include <vector>

#include "sorting_strategy.h"
#include "file_handler.h"

#define MAX_OP 4

class SortingApplication {
public:
	SortingApplication();
	bool start_application();
	void clear();
	~SortingApplication();

private:
	void get_input();
	void get_sorting_strategy(int strategy); 
	bool get_matrix(); 
	void sort_matrix();
	bool save_matrix();

	FileHandler m_file_handler;
	std::string m_in_file;
	std::string m_out_file;
	std::vector<std::vector<int>> m_matrix;
	SortingStrategy* m_sort_strategy;
};

#endif  // SA

