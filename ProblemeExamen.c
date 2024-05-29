/*Fie doua numere ientregi a si b. Sa se determine cate cifre au in comun
 * De ex. : a=521345 si b=875326
 * Nr de cifre in comun: 3 cifre in comun (2,3,5)*/

#include "stdio.h"
#include "stdlib.h"

int main(void) {
    int a, a_i, b, b_i, c, nr_cifre_comune=0, i;
    // a_i si b_i valorile initiale ale lui a si b care sunt distruse de bucla while
    int tf_a[10], tf_b[10];

    printf("a=");
    scanf("%i", &a);
    a_i = a;

    printf("b=");
    scanf("%i", &b);
    b_i = b;

    // initializez cu 0 intrarile tabelelor de frecventa
    for (i=0; i<=9; i++) tf_a[i]=tf_b[i]=0;

    while(a){
        c = a%10; a=a/10; tf_a[c]++;
    } // creez tabela de frecvente a cifrelor lui a

    while(b){
        c = b%10; b=b/10; tf_b[c]++;
    } // creez tabela de frecvente a cifrelor lui b

    printf("Cifrele comune ale lui %i si %i sunt:", a_i, b_i);
    for (i=0;i<=9;i++){
        if (tf_a[i] && tf_b[i]) {
            nr_cifre_comune++;
            printf(" %i", i);
        }
    }

    printf("\nNumerele %i si %i au deci %i cifre in comun", a_i, b_i, nr_cifre_comune);

    return 0;
}
