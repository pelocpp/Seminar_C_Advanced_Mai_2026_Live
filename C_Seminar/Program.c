#include <stdio.h>

#include "Common.h"

//extern void pointer_demo();
//extern void demo_parameter_passing();
//extern void demo_structs();

int anotherGlobal = 11;

static demo_static()
{
	static int n = 100;   // globale Variable, ist aber nur in dieser Funktion verfügbar
	n = n + 1;
	printf("n = %d\n", n);
}

int main()
{
	//demo_static();
	//demo_static();
	//demo_static();

	test_dictionary();

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

