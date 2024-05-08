// LAB 3 - problema cu descompunerea in factori primi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    unsigned n, p, d;

    printf("n = ");
    scanf("%d", &n);

    d = 2; // pt ca 2 ii primul nr prim
    printf("%d = ", n);
    while (n>1){
        p=0; // incepe puterea de la 0



        while (n%d==0){
            p++;
            n=n/d;
        };



        if (p>0) {
            if(n==1)
                printf("(%d^%d)", d, p);
            else
                printf("(%d^%d) * ", d, p);
        }

        
        d++;
    }
    return 0;
}
