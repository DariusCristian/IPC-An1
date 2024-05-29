// Problema de laborator
/* Se citeşte un număr întreg n după care se citesc n propoziţii 
(fiecare terminată cu tasta enter). Să se
sorteze aceste propoziţii (sortare de şiruri de caractere). */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"


void citeste_propozitii(char sir_propozitii[25][80], int n){
    int i;
    puts("Introduceti propozitiile, apasand tasta enter dupa fiecare:");
    fflush(stdin);
    for (i=0;i<n; i++){
        gets("sir_propozitii[i]");
    }
}
void sorteaza_propozitii(char sir_propozitii[25][80], int n){
    int i,j;
    char temp[80];
    for (i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){
            if(strcmp(sir_propozitii[i], sir_propozitii[j])>0){
                strcpy(temp, sir_propozitii[i]);
                strcpy(sir_propozitii[i], sir_propozitii[j]);
                strcpy(sir_propozitii[j], temp);
            }
        }
    }
}
void afiseaza_propozitii (char sir_propozitii[25][80], int n){
    int i;
    for (i=0;i<n;i++){
        puts(sir_propozitii[i]);
    }
}
int main(void) {
    int n;
    char sir_propozitii[25][80];

    printf("Introduceti numarul de propozitii n=");
    scanf("%d", &n);

    citeste_propozitii(sir_propozitii,n);
    printf("\nPropozitiile introduce de la tastatura sunt:\n");
    afiseaza_propozitii(sir_propozitii,n); // pentru verificare

    sorteaza_propozitii(sir_propozitii, n);
    printf("\nPropozitiile sortate sunt:\n");
    afiseaza_propozitii(sir_propozitii,n);
    return 0;
}
