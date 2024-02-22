#include <vector>

#define MAX_OP 4

typedef void (*Sort)(std::vector<int>&);

enum SortingStrategy {
	Bubble_sort,
	Select_sort,
	Insert_sort,
	Quicksort
};

struct SortingOption {
	SortingStrategy strategy;
	Sort sort;
};

void init_options(std::vector<SortingOption>& options);
void w_quicksort(std::vector<int>& arr);
void quicksort(std::vector<int>& arr, int low, int high);
int partition(std::vector<int>& arr, int low, int high); 
void select(std::vector<int>& arr);
void insert(std::vector<int>& arr);
void bubble(std::vector<int>& arr);

