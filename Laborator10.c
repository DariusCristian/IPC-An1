// Laborator 10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define atoa(x) #x

#define FALSE 0
#define TRUE !(FALSE)

//definim structura cu numele persoana 
typedef struct persoana {
	char nume[20];
	char prenume[20];
	int varsta;
	char localitate[25];
} Persoana;

Persoana sir[100];//variabila sir[100]va fi de tip Persoana 

//funcția pentru citirea înregistrărilor din fișier
int citeste_persoane(FILE* fp) {
	int i = 0;//nr. de persoane citite din fisier
	while (fscanf(fp, "%s %s %d %s", &sir[i].nume, &sir[i].prenume, &sir[i].varsta, &sir[i].localitate) == 4)
		i++;
	return i;
}

int compara_dupa_varsta(Persoana p1, Persoana p2) {
	return p1.varsta < p2.varsta;
}

int compara_dupa_localitate(Persoana p1, Persoana p2) {
	return strcmp(p1.localitate, p2.localitate) < 0;//comparam descrescator dupa localitate
}

int compara_dupa_varsta_descrescator(Persoana p1, Persoana p2) {
    return (p1.varsta < p2.varsta || (p1.varsta == p2.varsta && strcmp(p1.prenume, p2.prenume) > 0));
}

//funcția de ordonare generica a persoanelor 
void sortare(int n, int (*comparare_persoane)(Persoana p1, Persoana p2)) {
	Persoana tmp;
	int i, schimbare;
	do {
		//la inceput presupunem ca sirul este ordonat crescator
		//deci schimbare este FALSE (fiindca nodurile adiacente snt pozitionate in ordinea corecta)
		for (schimbare = FALSE, i = 0; i < n - 1; i++)//parcurg toate personale de la prima la penultima
		{
			if ((*comparare_persoane)(sir[i], sir[i + 1])) {//verific daca doua poersoane adiacente sunt corect pozitionate
				//adica in ordinea ceruta de functia de sortare

				//daca nu este cazul le interschimb folosind metoda celor trei pahare
				tmp = sir[i];
				sir[i] = sir[i + 1];
				sir[i + 1] = tmp;
				schimbare = TRUE;//cel putin cele doua persoane adiacente nu erau bine pozitionate
			}
		}
	} while (schimbare == TRUE);//repet cata vreme sirul nu este complet ordonat 
	//adica, fac cel putin o interschimbare de persoane adiacente
}

int compara_egalitate_varsta(Persoana p1, Persoana p2) {
	return p1.varsta == p2.varsta;
}

int compara_egalitate_localitate(Persoana p1, Persoana p2) {
	return strcmp(p1.localitate, p2.localitate) == 0;//comparam descrescator dupa localitate
}

char* get_varsta(Persoana* p) {
	char* buffer = (char*)malloc(20 * sizeof(char));
	return _itoa(p->varsta, buffer, 10);
}

char* get_localitate(Persoana* p) {
	return p->localitate;
}

//numaram persoanele din fiecare grup citit
void grupare_persoane(int n, int (*comparare_persoane)(Persoana p1, Persoana p2), char* (*getter)(Persoana* p), const char* criteriu) {
	int i = 0, numar = 1;

	do {
		//cata vreme nu am ajuns la sfarsitul grupului curent de persoane sau 
		//nu am amparcurs toate persoanele
		while ((i + 1 < n) && (*comparare_persoane)(sir[i], sir[i + 1]))
			i++, numar++;//mareste numarul de persoane din grup

		printf("\nAferent grupului de %s %s avem %d persoane\n", criteriu, (*getter)(&sir[i]), numar);

		i++;//treci la urmatoare persoane
		numar = 1;//numarul de persoane din urmatorul grup este cel putin 1
	} while (i < n);//cata vreme nu am amparcurs toate persoanele
}


void afiseaza_persoane(int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%s %s %d %s\n", sir[i].nume, sir[i].prenume, sir[i].varsta, sir[i].localitate);
}

int main() {
	int nrpersoane, numar = 1;
	int (*cmp_varsta)(Persoana p1, Persoana p2) = &compara_dupa_varsta;
	int (*cmp_varsta_descrescator)(Persoana p1, Persoana p2) = &compara_dupa_varsta_descrescator;
	int (*cmp_localitate)(Persoana p1, Persoana p2) = &compara_dupa_localitate;
	int (*cmp_egal_varsta)(Persoana p1, Persoana p2) = &compara_egalitate_varsta;
	int (*cmp_egal_localitate)(Persoana p1, Persoana p2) = &compara_egalitate_localitate;
	char* (*getter_varsta)(Persoana * p) = &get_varsta;
	char* (*getter_localitate)(Persoana * p) = &get_localitate;
	FILE* fp;
	fp = fopen("persoane.txt", "r");
	//deschidemfișierul în mod citire
	if (fp == NULL)// în caz de eroare
	{
		printf("Nu am reusit deschiderea fisierului!\n");
		return -1;
	}

	nrpersoane = citeste_persoane(fp);
	sortare(nrpersoane, cmp_varsta_descrescator);
    afiseaza_persoane(nrpersoane);
    
    /*sortare(nrpersoane, cmp_varsta);//sortam persoanele din sir după varsta
	printf("\nInregistrarile sortate dupa varsta:\n");
	afiseaza_persoane(nrpersoane);

	//numaram persoanele din fiecare varsta citita
	grupare_persoane(nrpersoane, cmp_egal_varsta, get_varsta, "varsta");

	sortare(nrpersoane, cmp_localitate);//sortam persoanele după localitate
	printf("\nInregistrarile sortate dupa localitate:\n");
	afiseaza_persoane(nrpersoane);

	//numaram persoanele din fiecare localitate
	grupare_persoane(nrpersoane, compara_egalitate_localitate, get_localitate, "localitate");
    */
	
    fclose(fp);//închidem fișierul
	return 0;
}

