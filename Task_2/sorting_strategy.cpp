#include "sorting_strategy.h"

void Bubble::sort(std::vector<int>& vec) {
	bool flag = 1;
	for (int i = 0; i < vec.size()-1; i++) {
		flag = 1;
		for (int j = 0; j < vec.size()-i-1; j++) {
			if (vec[j] > vec[j+1]) {
				std::swap(vec[j], vec[j+1]);
				flag = 0;
			}
		}
		if (flag) {
			break;
		}
	}
}

void Insert::sort(std::vector<int>& vec) {
	for (int i = 1; i < vec.size(); i++) {
		int key = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > key) {
			vec[j+1] = vec[j];
			j--;
		}
		vec[j+1] = key;
	}
}

void Select::sort(std::vector<int>& vec) {
	int min_idx = 0;
	for (int i = 0; i < vec.size()-1; i++) {
		min_idx = i;
		for (int j = i+1; j < vec.size(); j++) {
			if (vec[j] < vec[min_idx]) {
				min_idx = j;
			}
		}
		std::swap(vec[i], vec[min_idx]);
	}
}

void Quick::sort(std::vector<int>& vec) {
	quicksort(vec, 0, vec.size()-1);
}

void Quick::quicksort(std::vector<int>& vec, int low, int high) {
	if (low < high) {
		int pivot = partition(vec, low, high);

		quicksort(vec, low, pivot-1);
		quicksort(vec, pivot+1, high);
	}
}

int Quick::partition(std::vector<int>& vec, int low, int high) {
	int pivot = vec[high];
	int i = low;

	for (int j = low; j < high; j++) {
		if (vec[j] <= pivot) {

			std::swap(vec[i], vec[j]);
			i++;
		}
	}
	std::swap(vec[i], vec[high]);
	return i;
}

/* void init_options(std::vector<SortingOption>& options) { */	
/* 	SortingOption tmp = {SortingStrategy::Bubble_sort, bubble}; */ 
/* 	options.push_back(tmp); */
/* 	tmp = {SortingStrategy::Select_sort, select}; */ 
/* 	options.push_back(tmp); */
/* 	tmp = {SortingStrategy::Insert_sort, insert}; */ 
/* 	options.push_back(tmp); */
/* 	tmp = {SortingStrategy::Quicksort, w_quicksort}; */ 
/* 	options.push_back(tmp); */
/* } */
