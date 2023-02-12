#include <stdio.h>
#include <string.h>

struct emp{
	char name[25];
	unsigned int id;
};

int main(void) {
	struct emp Emp1 = {"Alex", 1001};
	struct emp Emp2 = {"Abdalla Emad", 1002};

	// Array of pointers to structures
	struct emp *arr[5] = {&Emp1, &Emp2};

	// Pointer to array of pointers to structures
	struct emp *(*ptr)[5] = &arr;

	printf("Employee 1 name: %s\n", (*ptr)[0]->name);
	printf("Employee 1 ID: %d\n", (*ptr)[0]->id);
	printf("Employee 2 name: %s\n", (*ptr)[1]->name);
	printf("Employee 2 ID: %d\n", (*ptr)[1]->id);

	return 0;
}
