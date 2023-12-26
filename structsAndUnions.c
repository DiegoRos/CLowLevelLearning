#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_IDS 1064
#define MAX_EMPLOYEES 1000

// Creating a basic structure
struct employee_t {
	int id;
	char first_name[64];
	char last_name[64];
	float income;
	bool is_manager;
};

// struct modifiers
// 	There can be different struct modifiers that can be added in different systems
// 	that are sometimes added on systems that create optimizatoins under the hood.

__attribute__((__packed__)) struct employee_t2 {
	int id;
	char first_name[64];
	char last_name[64];
	float income;
	bool is_manager;
};
// This could poentially create a structure that is less than the original 140 bytes
// 		- 4 bytes from int id.
// 		- 64 bytes from char first_name.
// 		- 64 bytes from char last_name.
// 		- 4 bytes from float income.
// 		- 4 bytes from bool is_manager.
// 	In this case it does not do that but it could in some circumstances.


// Creating a basic Union
// 	The union creates a type that creates enough room for the largest variable
// 	In this case the larget variable is int x (it has a size of 4 bytes),
// 	  the char variable has a size of 1 byte so it is smaller.
// 	This is very usefull in embedded coding and will not be a focus of this course.
union myunion_u{
	int x;
	char c;
	short s;
};



int main () {
	// Array of mystruct structures
	struct employee_t employees[MAX_EMPLOYEES];

	for (int i = 0; i < MAX_EMPLOYEES; i++) {
		employees[i].income = 0;
		employees[i].is_manager = false;
	}
	strcpy(employees[5].first_name, "Diego");

	printf("%s's salary is: %f\n", employees[5].first_name, employees[5].income);


	// Looking at unions
	union myunion_u u;
	u.x = 0x41424344;
	printf("%x %hx %hhx\n", u.x, u.s, u.c);
	// This prints: 41424344 4344 44
	// 41424344 is the full hexadecimal code with 4 bytes (8 hex numbers) like an int.
	// 4344 is 2 bytes of the hexadecimal value since it is a short (4 hex numbers = 2 bytes).
	// 44 is 1 byte of the hexadecimal value since it is a char (2 hex numbers = 1 byte).

	printf("Size of employee_t struct %d, size of employee_t2 struct: %d\n",
			sizeof(struct employee_t), sizeof(struct employee_t2));

	return 0;
}
