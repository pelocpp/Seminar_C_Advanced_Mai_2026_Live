#include <stdio.h>

extern void pointer_demo();
extern void demo_parameter_passing();

int anotherGlobal = 11;

int main()
{
	demo_parameter_passing();

	return 0;
}

void main_hello_world()
{
	int a, b, c;

	a = 1;
	b = 2;

	c = a + b;

	printf("Hallo Seminar");
}

