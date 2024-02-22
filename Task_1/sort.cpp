#include "sort.h"

void init_options(std::vector<SortingOption>& options) {	
	SortingOption tmp = {SortingStrategy::Bubble_sort, bubble}; 
	options.push_back(tmp);
	tmp = {SortingStrategy::Select_sort, select}; 
	options.push_back(tmp);
	tmp = {SortingStrategy::Insert_sort, insert}; 
	options.push_back(tmp);
	tmp = {SortingStrategy::Quicksort, w_quicksort}; 
	options.push_back(tmp);
}

void w_quicksort(std::vector<int>& arr) {
	quicksort(arr, 0, arr.size()-1);
}

void quicksort(std::vector<int>& arr, int low, int high) {
	if (low < high) {
		int pivot = partition(arr, low, high);

		quicksort(arr, low, pivot-1);
		quicksort(arr, pivot+1, high);
	}
}

int partition(std::vector<int>& arr, int low, int high) {
	int pivot = arr[high];
	int i = low;

	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {

			std::swap(arr[i], arr[j]);
			i++;
		}
	}
	std::swap(arr[i], arr[high]);
	return i;
}

void select(std::vector<int>& arr) {
	int min_idx = 0;
	for (int i = 0; i < arr.size()-1; i++) {
		min_idx = i;
		for (int j = i+1; j < arr.size(); j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		std::swap(arr[i], arr[min_idx]);
	}
}

void insert(std::vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void bubble(std::vector<int>& arr) {
	bool flag = 1;
	for (int i = 0; i < arr.size()-1; i++) {
		flag = 1;
		for (int j = 0; j < arr.size()-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				std::swap(arr[j], arr[j+1]);
				flag = 0;
			}
		}
		if (flag) {
			break;
		}
	}
}

