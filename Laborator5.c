// LABORATOR 5-03.04.2024
  
 // 1. Se citeste un sir de n numere reale. Să se afișeze: suma acestor numere, valoarea maximă
// din șir. 
    
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
    
#define INFINIT INT_MAX

int main()
{
    int a[100], n, suma = 0, maxim = -INFINIT, i;
    printf("n=");
    scanf("%i", &n);
    for(i=0; i<n; i++)
    {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
        suma += a[i];
        if(a[i]>maxim)
            maxim=a[i];
    }
    printf("suma numerelor este %d si maximul este %d", suma, maxim);
    return 0;
}
  
	// 2. Se citeste un sir de n+1 numere reale a0, a1, …, an reprezentând coeficienții unui polinom de
// gradul n . Se citeste o valoare reală x. să se calculeze valoarea polinomului in punctul x. 
    
    
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
  
//  3. Se citeste o matrice pătratică A de dimensiune n x n. Să se calculeze transpusa matricii A. 
    
  
#include <stdio.h>
#include <stdlib.h>

void citeste_matrice(int a[][100], int n, char nume[])
{
    int i,j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            printf("%s[%d][%d]=", nume, i, j);
            scanf("%d", &a[i][j]);
        }
}
void scrie_matrice(int a[][100], int n, char nume[])
{
    int i,j;
    printf("\n%s=\n", nume);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)

            printf("%4d", a[i][j]);
        printf("\n");
    }
}
void transpune_matrice(int a[][100], int n, int t[][100])
{
    int i,j;
    printf("\n%s=\n", nume);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            t[i][j]=a[j][i];

}

  int main()
{
  int a[100][100], n, t[100][100], tt[100][100];
    //tt-dubla transpusa
    printf("n="); scanf("%d", &n);
    citeste_matrice(a, n, "A");
    scrie_matrice(a, n, "A");

    transpune_matrice(a, n, t);
    scrie_matrice(a, n, "T");

    transpune_matrice(t, n, tt);
    scrie_matrice(a, n, "TT");

    return 0;
}
