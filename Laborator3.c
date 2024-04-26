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
