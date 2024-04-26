 LABORATORUL 6
  
  1. Se citește un număr natural n. să se genereze coeficienții dezvoltării binomului (x+1)^n
(triunghiul lui Pascal).

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j, a[100][100]= {0},n;
    printf("n=");
    scanf("%d", &n);
    for(i=0; i<=n; i++)
        for(j=0; j<=n; j++)
        {
            if(j==0|| i==j)
                a[i][j]=1;
            else if(i>j)
                a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=i; j++)
            printf("%5d",a[i][j]);
        printf("\n");
    }
    return 0;
}


	2. Se citesc 2 numere naturale n și k , k<n și un sir a0, a1, …, an reprezentând coeficienții unui
polinom de gradul n. să se afiseze derivata de ordinul k a acestui polinom. Se citește o
valoare reală x. să se calculeze valoarea polinomului si a derivatei in punctul x.


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
