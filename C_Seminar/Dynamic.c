
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


void demo_dynamic_frage()
{
	int kleinesFeld[10];
}

void demo_dynamic_01()
{
	// Speicher für eine int-Variable dynamisch anlegen
	// malloc: Kennt NICHT int, double, ...: NUR BYTES

	int* var = malloc(1 * sizeof(int));
	// ..............
	free(var);
}

int* demo_dynamic_anlegen(int wieViel)  // soll int-Werte anlegen
{
	int* ptr = malloc(wieViel * sizeof(int));
	return ptr;
}

void demo_dynamic_freigeben(int* adr)
{
	//free(adr);

	// ............

//	free(adr);   // No

}

void demo_mit_dyn_speicher_arbeiten()
{
	int anzahlInteger = 5;

	// adr ist die Adresse des ANFANGS // des ersten int-Wert's
	int* adr = demo_dynamic_anlegen(anzahlInteger);

	// arbeiten
	for (int i = 0; i < anzahlInteger; i++) {

		// *(adr + i) = 2 * i;   // Schreibweise // Syntax // Geht das besser ???

		adr[i] = 2 * i;          // Leichter lesbar
	}

	demo_dynamic_freigeben(adr);
}


void demo_dynamic()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	demo_mit_dyn_speicher_arbeiten();
}