#include <stdio.h>

#include "Dictionary.h"

// #define MaxKeyValuePairs  10

// Implementierung

// Ersten, einfacher Ansatz:
// Globale Variable
// struct KeyValuePair dictionary[MaxKeyValuePairs];   // 20 Strukturvariablen // Global

// füge einen neuen Mitarbeiter in das Dictionary ein
int insertPerson(struct KeyValuePair* dictionary, size_t maxPairs, size_t number, const char* name)
{
	// key may not exist so far
	for (int i = 0; i < maxPairs; i++) {

		if (dictionary[i].m_number == number) {
		
			printf("Key %zu already exists !\n", number);
			return 0;   // 0 : no success
		}
	}

	// search empty slot  // suche in dem Array einen freien Platz
	for (int i = 0; i < maxPairs; i++) {

		// is this slot empty
		if (dictionary[i].m_number == 0) {

			dictionary[i].m_number = number;  // set key
			dictionary[i].m_name = name;      // set value

			return 1;   // success
		}
	}

	printf("Dictionary is full !\n");
	return 0;  // no success // no empty slot found
}

const char* searchPerson(struct KeyValuePair* dictionary, size_t maxPairs, size_t number)
{
	// search key
	for (int i = 0; i < maxPairs; i++) {

		if (dictionary[i].m_number == number) {

			// found
			return dictionary[i].m_name;
		}
	}

	// not found
	return NULL;
}

void printDictionary(struct KeyValuePair* dictionary, size_t maxPairs)
{
	printf("Dictionary:\n");

	for (int i = 0; i < maxPairs; i++) {

		if (dictionary[i].m_number != 0) {
			printf("Number: %zu - Name: %s\n", 
				dictionary[i].m_number, dictionary[i].m_name);
		}
	}
}



// Anwendung

// Zweiter Ansatz:
// Globale Variable / Name für die Funktionen aber nicht verfügbar

// const size_t MaxPairs = 10;
#define MaxPairs 10

struct KeyValuePair myDictionary[MaxPairs];   // 20 Strukturvariablen // Global

void test_dictionary()
{
	// Dritter Ansatz:
    // Lokale Variable / Name für die Funktionen aber nicht verfügbar
	// struct KeyValuePair myDictionary[MaxPairs] = {};

	// ABER: Hmmm, ein Dictionary könnte groß sein / werden
	// Dann vielleicht doch nicht als lokale Variable

	printDictionary(myDictionary, MaxPairs);

	insertPerson(myDictionary, MaxPairs, 101, "Hans");
	insertPerson(myDictionary, MaxPairs, 102, "Anton");
	insertPerson(myDictionary, MaxPairs, 103, "Guenther");

	printDictionary(myDictionary, MaxPairs);

	insertPerson(myDictionary, MaxPairs, 101, "Franz");

	const char* name = searchPerson(myDictionary, MaxPairs, 102);
	if (name != NULL) {
		printf("Number 102 belongs to %s\n", name);
	}

	name = searchPerson(myDictionary, MaxPairs, 111);
	if (name != NULL) {
		printf("Number 111 belongs to %s\n", name);
	}
	else {
		printf("Number 111 not found !\n");
	}
}