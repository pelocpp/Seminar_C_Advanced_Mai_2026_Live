
#include <stdio.h>

int x = 123;  // globale Variable

extern int anotherGlobal;

void pointer_demo()
{
	int n = 123;
	int m = 124;

	printf("n = %d\n", n);
	printf("m = %d\n", m);

	int anzahlBytesInt = sizeof(int);
	printf("anzahlBytesInt = %d\n", anzahlBytesInt);

	// Adresse von n
	int* ip = &n;  // &:  Adresse von // referenzieren

	// Weise der Variablen n den Wert 99 zu
	// ohne den Variablennamen n zu verwenden
	*ip = 99;  // *: indirekter Zugriff // gehe über die Adresse
	           // oder auch: dereferenzieren

	ip = ip + 1;   // 0x1024 => 0x1028, weil ein int 4 Bytes belegt

    // Geht das ?????? Nein
	*ip = 100;
}

void pointer_demo_02()
{
	int a = 10;
	int b = 11;
}

void pointer_demo_01()
{
	int n = 123;

	pointer_demo_02();

    printf("anotherGlobal=%d", anotherGlobal);

	printf("n=%d", n);

	printf("x=%d", x);

	// Wo liegt n im Speicher
}