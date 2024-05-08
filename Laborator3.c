LABORATOR3-30.03.2024
  
  // DACA NUMARUL ESTE PRIM SAU  NU
    int main() {
    int d,n, prim=1;
    // n - numarul pe care il verific daca e prim
    // d - variabila caruia ii atribui valoarea 2
    // pt a verfica restul daca este prim sau nu
    printf("n=");
    scanf("%d", &n);

    for (d=2;d<=(n/2);d++) {
        if (n%d==0)
            prim=0;
    }
    if (prim==0)
        printf("%d nu este nr. prim!", n);
    else
        printf("%d este nr prim!", n);
    return 0;
}
    
  -----------------------------------------------
    
    ///descompunere in factori primi
    int main() {
    unsigned int n,d,p; // unsigned = nu pot fi negative numerele
    // n - nr pe care il descompunem
    // p - numarul putere

    printf("n=");
    scanf("%d", &n);

    d = 2; // primul factor prim

    printf("%d = ", n);
    while(n>1) {

        p=0; // p stocheaza nr de repetari a unui factor prim (puterea)

        while (n%d==0) {
            p++;
            n=n/d;
        };

        if (p>0) {
            if (n==1)
                printf("(%d^%d)",d,p);
            else
                printf("(%d^%d) * ",d,p); // n se divide de p ori cu d
        }
        d++;
    }

    return 0;
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
