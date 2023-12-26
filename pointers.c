#include <stdio.h>
#include <stdbool.h>

struct employee_t {
	int id;
	int income;
	bool staff;
};

void initialize_employee(struct employee_t *e) {
	e->id = 0;
	e->income = 0;
	e->staff = true;

	return;
}


int main () {
	// Pointers are addresses to memory locations that contain a type of variable.
	int x = 3;

	int *px = &x; // Setting px equal to the address of variable x.

	// %p is utilized to print adress of variable
	printf("Value in px: %p.\nAdress of x: %p.\n", px, &x);

	// We can derefference the pointer with the * operator before the variable.
	// This allows to print the value stored at the direction that px points to.
	printf("\nValue px points to %d.\nValue of x: %d.\n", *px, x);


	struct employee_t Ana;
	// We can use pointers to our advantage to set values inside existing variables
	// and structures that are outside the scope of our function. In this case
	// we are calling the initialize_employee function which edits our main
	// scope struct employee_t Ana.
	initialize_employee(&Ana);

	printf("\nEmployee id: %d\n", Ana.id);

	return 0;
}
