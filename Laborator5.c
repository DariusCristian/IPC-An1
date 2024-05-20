// LABORATOR 5-03.04.2024
  
 // 1. Se citeste un sir de n numere reale. Să se afișeze: suma acestor numere, valoarea maximă
// din șir. 
    
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // pentru constanta INT_MIN adica minus infinit

/* Se citeste un sir de n numere reale. Sa se afiseze suma acestor numere,
 * valoarea maxima din sir.*/

int main(){
    int n, i; // n - lungimea sirului,
    // a[20] - sir de 20 de caractere.
    // i - pt. a folosi ca index in bucle
    // s=0 - suma a[i]-urilor
    // max - valoarea maxima pe care o poate lua s, adica -infinit
    float a[20], s=0, max = INT_MIN;
    // prin float a[20] declaram un sir de numere reale
    // sirul a are dimensiunea de maxim 20 elemente
    // in variabila max vom stoca maximul din sir
    // initial maximul (necunoscut) presupunem ca e minus infinit
    printf("Introduceti lungimea sirului n=");
    scanf("%d", &n);
    for (i=0; i<n; i++){ // parcurgem sirul de indici de la 0
        printf("a[%d]=", i);
        scanf("%f", &a[i]);
        s+=a[i]; // reactualizam suma numerelor
        if (a[i]>max) {
            max = a[i];
        }
    }
    printf("Suma numerelor este %.2f\n", s);
    printf("Valoarea maxima din sir este: %.2f\n", max);
    return 0;
}










	// 2. Se citeste un sir de n+1 numere reale a0, a1, …, an reprezentând coeficienții unui polinom de
// gradul n . Se citeste o valoare reală x. să se calculeze valoarea polinomului in punctul x. 
// !!!!!!!!!!!!!!!!!!!!!! N-AM INTELES-O DELOC
// VARIANTA 1
    
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, a[100], pol=0, x,i,x_la_i;
    printf("n=");
    scanf("%i", &n);
    printf("x=");
    scanf("%i", &x);
    for(i=0, x_la_i=1; i<=n; i++, x_la_i=x_la_i*x)
    {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
        pol=pol+a[i]*x_la_i;
    }
    printf("P(%d)=%d", x,pol );
    return 0;
}

// VARIANTA 2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // variabila "v" va stoca valoarea polinomului
    int n,i;
    float x,a[20],v=0,xp;

    printf("n=");
    scanf("%d", &n);

    printf("x=");
    scanf("%f", &x);

    for (i=0;i<=n;i++){
        // sunt n+1 coeficienti, de la 0 la inclusiv 'n'
        // citim coeficientii si calculam valoarea polinomului
        printf("Coeficient de ordin %d este ", i);
        scanf("%f", &a[i]);
        xp = powf(x,n-i); //calculam x la puterea n adica x^n
        v = v+xp*a[i]; // echivalent cu v+=xp*a[i]
    }
    printf("\nPolinomul este:\n");
    for (i=n;i>=0;i--){
        printf("%.2f", a[i]);
        if (i>0) printf("X^%d+", i);
        else printf("*X^%d", i);
    }
    printf("\nValoarea polinomului este: %.2f\n", v);
    return 0;
}






  
//  3. Se citeste o matrice pătratică A de dimensiune n x n. 
//  Să se calculeze transpusa matricii A. 
    
  
#include <stdio.h>
#include <stdlib.h>

void citeste_matrice(int a[][100], int n, char nume[]) {
    int i, j;
    for (i=0;i<n;i++)
        for (j=0;j<n; j++) {
            printf("%s[%d][%d]=", nume, i, j);
            scanf("%d", &a[i][j]);
        }
}
void scrie_matrice(int a[][100], int n, char nume[]){
    int i,j;
    printf("\n%s=\n", nume);
    for (i=0;i<n;i++){
        for (j=0; j<n; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}
void transpune_matrice(int a[][100], int n, int t[][100],char nume[]) {
    int i,j;
    for (i=0;i<n;i++){
        for (j=0; j<n; j++)
            t[i][j]=a[j][i];
    }
}

int main() {
    int a[100][100], n, t[100][100], tt[100][100];
    // tt - dubla transpusa
    printf("n=");
    scanf("%d", &n);

    citeste_matrice(a, n, "A");
    scrie_matrice(a,n,"A");

    transpune_matrice(a,n,t, "T");
    scrie_matrice(t,n,"T");

    transpune_matrice(t,n,tt, "TT");
    scrie_matrice(tt,n,"TT");

    return 0;
    }
