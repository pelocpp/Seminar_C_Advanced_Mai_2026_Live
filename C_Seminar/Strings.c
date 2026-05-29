
#include <stdio.h>

void demo_character()
{
	// Ein Zeichen
	char ch;

	ch = 'A';   // Wie sieht das intern im Speicher aus ???  ASCII - Tabelle

	printf("ch: %c\n", ch);

	int n = ch;

	printf("n: %d\n", n);

	ch = 35;

	printf("ch: %c\n", ch);

	printf("sizeof(int): %llu\n", sizeof(int));
	printf("sizeof(char): %llu\n", sizeof(char));
}

void demo_strings_01()
{
	const char* s = "ABCDE";

	printf("s: %s\n", s);

	// ein einzelnes Zeichen aus der Zeichkette extrahieren

	char ch = *(s + 3);

	// besser lesbar
	ch = s[3];

	// Zeichen ver‰ndern: Geht nicht bei konstanten Zeichenketten !!!
	// s[3] = '!';
}

char zeichenkette[10];   //  Global !!!!!!!!!!!!!!!

void demo_strings_02()
{
	// char zeichenkette[10];   // Stack !!!!!!!!!!!!!!!

	zeichenkette[0] = 'A';
	zeichenkette[1] = 'B';
	zeichenkette[2] = 'C';
	zeichenkette[3] = 'D';
	zeichenkette[4] = 'E';
	// zeichenkette[5] = '0'; // Zeichen // Ziffer 0 // NICHT: terminierende Null // Falsch
	// zeichenkette[5] = 0;   // bin‰re, terminierende Null // Korrekt
	zeichenkette[5] = '\0';   // backslash Null // bin‰re Null

	printf("s: %s\n", zeichenkette);

	zeichenkette[0] = '!';
	printf("s: %s\n", zeichenkette);

}

// Arbeiten mit Zeichenketten

// i) L‰nge einer Zeichenkette

size_t string_length(const char* cp)
{
	size_t n = 0;  // n = length

	while (cp[n] != '\0') {
		// n = n + 1;
		n++;
	}

	return n;
}

void demo_strings_03()
{
	size_t len = string_length("ABCDE");

	printf("Len: %zu\n", len);
}

void string_append(const char* s1, const char* s2, char* result)
{
	// erste Zeichenkette umkopieren
	int n = 0;
	while (s1[n] != '\0') {

		result[n] = s1[n];
		n++;
	}

	// zweite Zeichenkette umkopieren
	int m = 0;
	while (s2[m] != '\0') {

		result[n] = s2[m];
		n++;
		m++;
	}

	// Ergebniszeichenkette mit 0 abschlieﬂen
	result[n] = '\0';
}

void demo_strings_04()
{
	char ergebnis[20];

	string_append("ABCDE", "123", ergebnis);

	printf("string_append: %s\n", ergebnis);
}

void demo_strings()
{
	demo_strings_04();
}

