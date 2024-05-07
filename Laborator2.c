-->LAB2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
  	///pb1
  
    int n, s=0, i;
    printf("n=");
    scanf("%i",&n);
    for(i=1; i<=n; i++)
        s=s+i;
    printf("Suma primelor %i numere naturale este %i", n, s);
  
  	///pb2
  
   int n, s=0, c;
    printf("n=");
    scanf("%i",&n);
    while(n!=0)
    {
        c=n%10;
        s=s+c;
        n=n/10;
    }
    printf("suma cifrelor este %i", s);
  
  	///pb3
  int n, s=0, c,x;
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
    printf("cifra %i apare de %i ori", x, s);

  ///pb4
    int a=0,b=1,c,i=2,n;
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
    printf("%i\n",c);

 return 0;
}
