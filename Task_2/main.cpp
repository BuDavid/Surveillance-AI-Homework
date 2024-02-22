#include "sorting_application.cpp" 

int main() {

	SortingApplication app;

	if (app.start_application() == 1) {
		printf("error\n");
		return 1;
	}
	printf("success\n");
}
