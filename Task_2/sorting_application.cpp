#include "sorting_application.h" 

SortingApplication::SortingApplication() {
	m_sort_strategy = nullptr;
}

bool SortingApplication::start_application() {
	get_input();
	if (get_matrix() == 1) {
		return 1;
	}
	sort_matrix();
	if (save_matrix() == 1) {
		return 1;
	}
	return 0;
}

void SortingApplication::get_input() {
	std::cout << "Give the input file name: ";
	std::cin >> m_in_file;

	std::cout << "Give the output file name: ";
	std::cin >> m_out_file;

	while (true) {
		int strategy = 0;
		std::cout << "Give the sorting option:\n ";
		std::cout << " 	0| Bubble\n 	1| Insert\n 	2| Select\n 	3| Quick\n";

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (std::cin >> strategy) {
			if (strategy >= 0 || strategy < MAX_OP) {
				get_sorting_strategy(strategy);
				break;
			}
		}
	}
}

void SortingApplication::get_sorting_strategy(int strategy) { 
	switch(strategy) {
		case 0:
			m_sort_strategy = new Bubble();
			break;
		case 1:
			m_sort_strategy = new Insert(); 
			break;
		case 2:
			m_sort_strategy = new Select();
			break;
		case 3:
			m_sort_strategy = new Quick();
			break;
	}
}

bool SortingApplication::get_matrix() {
	if (m_file_handler.read_matrix_from_file(m_in_file, m_matrix) < 0) {
		return 1;
	}
	return 0;
}

void SortingApplication::sort_matrix() {
	for (int i = 0; i < m_matrix.size(); i++) {
		m_sort_strategy->sort(m_matrix[i]);
	}
}

bool SortingApplication::save_matrix() {
	if (m_file_handler.write_matrix_to_file(m_out_file, m_matrix) < 0) {
		return 1;
	}
	return 0;
}

void SortingApplication::clear() {
	m_in_file.clear();
	m_out_file.clear();
	m_matrix.clear();
	if (m_sort_strategy) {
		delete m_sort_strategy;
	}
	m_sort_strategy = nullptr;
}

SortingApplication::~SortingApplication() {
	clear();
}

