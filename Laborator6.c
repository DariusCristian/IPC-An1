 LABORATORUL 6
  
  1. Se citește un număr natural n. să se genereze coeficienții dezvoltării binomului (x+1)^n
(triunghiul lui Pascal).

#include <stdio.h>
#include <stdlib.h>

int main () {
    int n,i,j,a[20][20];
    // n - numarul de linii din triunghiul lui Pascal
    // i,j - variabile de iteratie folosite in bucle
    // a[20][20[ - matrice fixa de 20x20, unde se va construi triunghul lui Pascal


    // Citirea valorii lui n
    printf("n=");
    scanf("%d", &n);
    // Se cere utilizatorului sa introduca nr. de linii ale triunghiului lui Pascal.


    // vom pune 1 in prima coloana si 1 pe diagonala principala
    // ( cele 2 laturi ale triunghiului )
    // si 0 in rest


    // Initializarea Matricei A
    for(i=0;i<n;i++) { // parcurge liniile matricei a
        for (j=0; j<n; j++){ // parcurge coloanele matricei a.
            if ((j==0)||(i==j))
                // j == 0 Aceasta verifică dacă suntem în prima coloană a matricei (j este 0).
                // i == j Aceasta verifică dacă suntem pe diagonala principală a matricei
                // (elementele unde indicele de linie i este egal cu indicele de coloană j).
                a[i][j]=1; // Daca una dintre conditiile din if este adevarata
                // pune 1 pe prima coloana si pe diagonala
                // daca nici una dintre conditii nu este adeavarata, a[i][j] este setat la 0
            else a[i][j]=0; // 0 in rest
        }
    }
    // Se parcurge matricea A si se initializeaza:
    // a[i][j] = 1 pentru elementele din prima coloană (unde j == 0) și
    // pentru elementele de pe diagonala principală (unde i == j).
    // a[i][j] = 0 pentru toate celelalte elemente.



    // Calcularea valorilor din interiorul triunghiului lui Pascal:
    for (i=2;i<n;i++)
        // parcurge liniile matricei a începând de la linia 2
        // (a treia linie, deoarece indexarea începe de la 0).
        for (j=1;j<i;j++)
            // parcurge coloanele matricei a pentru fiecare linie i,
            // începând de la coloana 1 până la coloana i-1
            a[i][j]=a[i-1][j]+a[i-1][j-1];
    /*Începând de la linia 2 (index i=2) și coloana 1 (index j=1), fiecare element a[i][j]
     * este calculat ca suma dintre elementul
     * de deasupra (a[i-1][j]) și elementul din stânga sus (a[i-1][j-1]).
     * Aceasta este regula pentru a construi triunghiul lui Pascal.*/



    // Afisarea triunghiului lui Pascal:
    for (i=0;i<n;i++){
        for (j=0;j<=i;j++) // si egal ca sa mi ia val de pe diagonala pp
            printf("%5d", a[i][j]);
        printf("\n");
    }
    // Se parcurge matricea si se afiseaza fiecare linie a triunghiului
    // %5d = pt a alinia frumos valorile afisate, cu o latime de 5 caractere pentru
    // fiecare numar.
    return 0;
}


	2. Se citesc 2 numere naturale n și k , k<n și un sir a0, a1, …, an reprezentând coeficienții unui
polinom de gradul n. să se afiseze derivata de ordinul k a acestui polinom. Se citește o
valoare reală x. să se calculeze valoarea polinomului si a derivatei in punctul x.

// VARIANTA 1
#include "stdio.h"
/* N - gradul polinomului
 * P(x) - formula
 * Derivata lui P(x) e suma derivatelor monoamelor a[i]*X^(n-1)
 * a[i]*X^(n-i)*X^(n-i-1
 * deci coeficientul a[i] devine a[i]*(n-i)
 * iar gradul lui P(x) scade cu 1
 *
 * Definim o functie ce afiseaza un polinom de gradul n*/


void scrie_pol(int a[100], int n) {
    int i;
    for (i=0; i<=n; i++)
        if(i!=n)
            printf("%dX^%d%s", a[i], n-1, a[i+1]>=0?"+":"");
        else
            printf("%dX^%d", a[n]);
}
int main() {
    int a[100], n, nrDev, i ,k;

    printf("n=");
    scanf("%d", &n);

    do {
        printf("nrDev(<%d)=", n);
        scanf("%d", &nrDev);
    } while (nrDev<0 || nrDev>=n);

    // citim coeficientii lu P(x)
    for (i=0; i<=n; i++){
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
    }

    // tiparim pe P(x)

    printf("P(X)="); scrie_pol(a, n);

    // Derivam P de nrDev ori si il afisam
    for (k=1;k<=nrDev; k++) {
        for (i=0; i<=n; i++) a[i]=a[i]*(n-i), n = n-1;

        // afisam p(x)

        printf("P");
        for (i=0; i<=n; i++) printf("'"); printf("(X)="); scrie_pol(a, n);
    }

    return 0;
}



// VARIANTA 2, Varianta mai buna


#include <stdio.h>
#include <stdlib.h>

int main () {
    // n ordinul polinomului, k ordinul derivatei, nrder - contor pt ordinea derivatelor
    int n,k,i,a[10], nrder;

    // Citirea gradului polinomului:
    printf("Introduceti gradul polinomului:");
    scanf("%d", &n);


    // Citirea si validarea ordinului derivatei
    do {
        printf("Introduceti ordinul derivatei (<%d): ", n);
        scanf("%d", &k);
        if (k>=n){
            printf("Valoarea adaugata nu corespunde cerintei. "
                   "Trebuie sa fie mai mica decat %d. ",n);
        }
    } while (k>=n); // citim k cu validare



    // Citirea coeficientilor polinomului:
    // findca k trebuie sa fie strict mai mic decat n
    printf("Introduceti coeficintii polinomului \n");
    for (i=0;i<=n;i++) {
        // n+1 coeficinti
        // polinomul a[0]*x^n+a[1]*x^(n-1)+...+a[i]*x^(n-1)+...+a[n-1]*x+a[n]
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
    }


    // Calcularea derivarei pana la ordinul k:
    for (nrder = 1 ; nrder <= k ; nrder++) {
        // contorul nrder tine evidenta derivatelor de ordin mai mic sau egal cu k
        for (i = 0 ; i < n ; i++) {
            a[i] = a[i] * (n - i);
        }
        n--; // dupa ce construim o derivata, decrementam puterea n cu o unitate


        // Afisarea derivatei
        printf("\n\n Derivata de ordinul %d a polinomului este:\n", nrder);

        for (i=0;i<=n;i++){
            if (i<n){
                printf("%d*X^%d+", a[i], n-i);
            }
            else {
                printf("%d", a[i]);
            }
        }
    }
    return 0;
}
