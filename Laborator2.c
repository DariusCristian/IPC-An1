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
      // pentru exemplu: 1234
      // prima etapa
        c=n%10; // extrage ultima cifra 4
        s=s+c; // adauga ultima cifra la s=0+4
        n=n/10; // taie ultima cifra -> numarul ramane 123, si acest proces se repeta in continua, pana cand n devine 0
    }
    printf("suma cifrelor este %i", s);
  
  	///pb3
  int main() {
    int s=0, c,x;

    printf("n=");
    scanf("%i",&c);

    printf("x=");
    scanf("%i",&x);

    while(c!=0)
    {
        if(c%10==x)
            s++;
        c=c/10;
    }
    printf("Cifra %i apare de %i ori", x, s);

    return 0;

  ///pb4 sirul lui fibonacci
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
