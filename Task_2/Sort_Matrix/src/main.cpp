#include "sorting_application.h" 

int main() {

	SortingApplication app;

	if (app.start_application() == 1) {
		printf("error\n");
		return 1;
	}
	printf("success\n");
}
