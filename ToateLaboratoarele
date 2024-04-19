SEMINAR3-13.03.024
  
->>LAB1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    ///pb1
    /*float a, b, s, d, p, c;
    printf("a=");
    scanf("%f", &a);
    printf("b=");
    scanf("%f", &b);
    s=a+b;
    d=a-b;
    p=a*b;
    printf("suma=%.f\ndiferenta=%.2f\nprodus=%.2f\n", s, d, p);
    if(b==0)
        printf("impartire la 0!");
    else
    {
        c=a/b;
        printf("cat=%.2f", c);
    }*/

    ///pb2-mediile aritmetica,geometrica,armonica
    /*int a,b,c;
    float ma,mg,mh;
    printf("a=");
    scanf("%i", &a);
    printf("b=");
    scanf("%i", &b);
    printf("c=");
    scanf("%i", &c);
    ma=(a+b+c)/3.0;
    printf("media aritmetica=%.2f\n", ma);
    mg=pow(a*b*c,1.0/3);
    printf("media geometrica=%.2f\n", mg);
    if(a*b*c==0)
        printf("impartire la 0!");
    else
    {
        mh=3/(1.0/a+1.0/b+1.0/c);
        printf("media armonica=%.2f\n", mh);
    }*/

    ///pb3

    /*float x,y,p,f;
    printf("x=");
    scanf("%f",&x);
    printf("y=");
    scanf("%f",&y);
    p=x*x+y*y;
    if(p>1)
        f=1/(p-1);
    else
        if(p==1)
        f=x+y;
    else
        f=1/(p+1);
    printf("f(%.2f,%.2f)=%.2f", x, y, f);*/

    ///pb4

    float x,a,b;
    printf("a=");
    scanf("%f",&a);
    printf("b=");
    scanf("%f",&b);
    if(a==0) printf("impartire la 0!");
    else
    {
        x=-b/a;
        printf("x=%.2f",x);
    }
    return 0;
}

------------------------------------------------------------------
-->LAB2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
  	///pb1
  
		/*int n, s=0, i;
    printf("n=");
    scanf("%i",&n);
    for(i=1; i<=n; i++)
        s=s+i;
    printf("Suma primelor %i numere naturale este %i", n, s);*/
  
  	///pb2
  
   /*int n, s=0, c;
    printf("n=");
    scanf("%i",&n);
    while(n!=0)
    {
        c=n%10;
        s=s+c;
        n=n/10;
    }
    printf("suma cifrelor este %i", s);*/
  
  	///pb3
  /*int n, s=0, c,x;
    printf("n=");
    scanf("%i",&n);
    printf("x=");
    scanf("%i",&x);
    c=n;
    while(c!=0)
    {
        if(c%10==x)
            s++;
        c=c/10;
    }
    printf("cifra %i apare de %i ori", x, s);*/

  ///pb4
    /*int a=0,b=1,c,i=2,n;
    printf("n=");
    scanf("%i",&n);
    printf("Sirul lui Fibonacci este\n %i %i ", a, b);
    while(i<n)
    {
        c=a+b;
        a++;
        printf("%i ",c);
        a=b;
        b=c;
        i++;
    }
    printf("%i\n",c);*/

 		return 0;
}
----------------------------------------------------------------------------------------------------------------------------
  LABORATOR3-30.03.2024
  
  //prim
    int n, prim=TRUE, d=2;
    printf("n=");
    scanf("%i", &n);
    while(d<=n/2 && prim==1)
    {
        if(n%d==0)
            prim=FALSE;
        d++;
    }
    if(prim==TRUE)
  
        printf("Numarul %i este prim", n);
    else
        printf("Numarul %i NU este prim", n);
    //SAU(IN LOC LA IF DE AFISARE)
    //printf("%d%sprim",n,prim?" e":"nu e");
  -----------------------------------------------
    
    ///descompunere in factori primi
    int n,d=2, p;
    printf("n=");
    scanf("%i", &n);
    while(n!=1)
    {
        p=0;
        if(n%d==0)
        {
            while(n%d==0)
            {
                n=n/d;
                p++;
            }
            printf("%i ^ %i\n", d, p);
        }
        d++;
    }
  -------------------------------------------------
    ///Se citeste un număr natural n. să se afișeze secvența:
    ///a. 1 2 2 3 3 3 4 4 4 4 5 5 5 5 5 ….

    int n, x=1, nr;
    printf("n=");
    scanf("%i", &n);
    while(x<=n)
    {
        nr=0;
        while(nr<x)
        {
            printf("%i ", x);
            nr++;
        }
        x++;
    }
    return 0;

		///b. 1 1 2 1 2 3 1 2 3 4 1 2 3 4 5 …
    int n, nr, d;
    printf("n=");
    scanf("%i", &n);
    for(int i=1; i<=n; i++)
    {
        nr=i;
        d=1;
        while(d<=i)
        {
            printf("%i ",d);
            d++;
        }
    }
  -----------------------------------------
    ///Să se scrie o funcție care verifică dacă un număr este sau nu palindrom.
    int palindrom(int n)
		{
    int inv=0,c;
    c=n;
    while(c!=0)
    {
        inv=inv*10+(c%10);
        c=c/10;
    }
    return inv;
		}
		
		int main()
    {
    int n,inv;
    printf("n=");
    scanf("%i", &n);
    inv=palindrom(n);
    if(n==inv)
        printf("palindrom");
    else
        printf("nu e palindrom");
    return 0;
		}
----------------------------------------------------------------------------
  LABORATOR 5-03.04.2024
  
  1. Se citeste un sir de n numere reale. Să se afișeze: suma acestor numere, valoarea maximă
din șir. 
    
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
  
	2. Se citeste un sir de n+1 numere reale a0, a1, …, an reprezentând coeficienții unui polinom de
gradul n . Se citeste o valoare reală x. să se calculeze valoarea polinomului in punctul x. 
    
    
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
  
  3. Se citeste o matrice pătratică A de dimensiune n x n. Să se calculeze transpusa matricii A. 
    
  
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
--------------------------------------------------------------------------------------------------------
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

#include <stdio.h>
#include <stdlib.h>

void afisare(int a[100], int n)
{
    int i;
    for(int i=0; i<=n; i++)
    {
        if(i!=n)
            printf("%dX^%d%s", a[i], n-i, a[i+1]>0?"+":"");
        else printf("%d", a[n]);
        printf("\n");
    }
}
int main()
{    int n, k, a[100],i,d;
    printf("n=");
    scanf("%d", &n);
    do
    {
        printf("nrdev(<%d)=", n);
        scanf("%d", k);
    }
    while(k<0 || k>=n);
    for(i=0; i<=n; i++)
    {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
    }
    printf("P(x)=");
    afisare(a,n);
    for(d=1; d<=k; d++)
    {
        for(i=0; i<=n; i++)
            a[i]=a[i]*(n-i);
        n--;
        printf("P=");
        afisare(a,n);
        for(i=1; i<=d; i++)
            printf("'");
        printf("(X)=");
        afisare(a,n);
    }

    return 0;
}

---------------------------------------------------------------------------------------------
  LABORATOR 7
  
  1. Se citeşte un număr întreg pozitiv n. Folosind operatori pe biţi să se afişeze reprezentarea în
baza 2 a numărului n.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    unsigned n;
    printf("n="); scanf("%u",&n);
    for(i=8*sizeof(n)-1; i>=0; i--)
        ///deplasam bitul de pe pozitia i, i pozitii spre dreapta pentru
        ///a ajunge pe prima pozitie
        ///facem o conjunctie cu masca 000...0001(numarul 1) pt a obtine val bitului (0 sau 1)
        printf("%d",(n>>i)&1);
    return 0;
}

=> daca vrem sa scapam de celalalte zerouri

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, cif_semn=0;
    ///cif_semn indica daca am intalnit prima cifra semnificativa (un 1)
    unsigned n;
    printf("n=");
    scanf("%u",&n);
    for(i=8*sizeof(n)-1; i>=0; i--)
    {
        ///facem o discjunctie cu cifra de pozitia i pentru a vedea daca este =1
        cif_semn|=(n>>i)&1; //cif_semn = cif_semn |((n>>i)&1)
        if(cif_semn)
            printf("%d",(n>>i)&1);
      			///tiparim cifra doar daca este semnificativa
    }
    return 0;
}

2. Se citeşte un număr întreg n reprezentând numărul de elemente dintr-o mulţime şi un şir de n
valori întregi reprezentând elementele acestei mulţimi. Folosind operatori pe biţi să se afişeze
toate submulţimile mulţimii date.
  
#include <stdio.h>
#include <stdlib.h>

void printSubmultimi(int multime[], int nr_elem)
{
    ///nr sumbult este egal cu (2*nr_elem-1)
    unsigned int nr_submultimi=1<<nr_elem;
    int contor, j;
    for(contor=0; contor<nr_submultimi; contor++)
    {
        printf("{");
        for(j=0; j<nr_elem; j++)
        {
            ///Verificam daca al j-lea bit din contor are val i
           if((contor>>j) & 1)/// sau if(contor & (1<<j))
                /// Daca este 1 atunci tiparim multimea[j] ca parte din submultimea curenta
                printf("%d", multime[j]);
        }
        printf("}\n");
    }
}
int main()
{
 int multime[]={1,2,3};
    printSubmultimi(multime, 3);
    return 0;
}
-----------------------------------------------------------------------------------------------------
  

