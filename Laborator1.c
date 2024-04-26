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
