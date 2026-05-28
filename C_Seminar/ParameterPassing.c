#include <stdio.h>

// will ein Unterprgramm schreiben,
// das eine Variable mal Zwei nimmt:
// ERSTE Variante

int malZwei(int value)
{
	int result = 2 * value;

	return result;
}

// oder

void malZweiEx(int value)
{
	value = 2 * value;
}

void malZweiExEx(int* adresse)
{
	int tmp = *adresse;

	tmp = 2 * tmp;

	*adresse = tmp;
}




void demo_parameter_passing()
{
	int wert = 17;

	/*int x = */ printf("Wert: %d\n", wert);

	// int ergebnis = malZwei(wert);

	malZweiEx(wert);

	printf("Wert: %d\n", wert);

	malZweiExEx(&wert);

	printf("Wert: %d\n", wert);
}