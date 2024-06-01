/*1. Fie doua numere ientregi a si b. Sa se determine cate cifre au in comun
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
    // initializarea tabelelor de frecventa
    for (i=0; i<=9; i++)
        tf_a[i]=tf_b[i]=0;

    while(a){ // c - stocheaza ultima cifra a lui a
        c = a%10;
        a=a/10;
        tf_a[c]++;
    } // creez tabela de frecvente a cifrelor lui a

    while(b){
        c = b%10;
        b=b/10;
        tf_b[c]++;
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




/*2. Fie doua numere intregi a si b inbaza 16 citite de la tastatura.
 * Sa se determine cate cifre au in comun.*/
#include "stdio.h"

int main(void){
    int a, a_i, b, b_i, c, nr_cifre_comune=0, i;
    // a_i si b_i valorile initiale ale lui a si b care sunt
    // distruse de bucla while
    int tf_a[16], tf_b[16];

    printf("a=", a);
    scanf("%X", &a);
    a_i=a;

    printf("b=", b);
    scanf("%X", &b);
    b_i=b;

    for (i=0; i<=16;i++){
        tf_a[i]=tf_b[i]=0;
    }

    while(a){
        c=a%16;
        a=a/16;
        tf_a[c]++;
    }

    while(b){
        c=b%16;
        b=b/16;
        tf_b[c]++;
    }

    printf("Numerele %X si %X au in comun urmatoarele numere:", a_i, b_i);
    for (i=0;i<=16;i++){
        if(tf_a[i] && tf_b[i]){
            nr_cifre_comune++;
            printf("%X", i);
        }
    }
    printf("\n Numerele au un comun %X numere", nr_cifre_comune);

    return 0;
}




/*Sa se calculeze cu o precizie citita de la tastatura (de exemplu, de 0.000001)
 * valoarea constantei lui Euler e
 * e=1/0! + 1/1! + 1/2! + 1/3! + ... + 1/i! + ...*/
#include "stdio.h"

int fact(int n) {
    if(n<=1) return 1;
    return n * fact(n-1);
}

double e(float precizie) {
    int i;
    double suma_pas_curent = 1 / fact(0), suma_pas_precedent = 0;

    for (i=1; suma_pas_curent - suma_pas_precedent > precizie; i++){
        suma_pas_precedent = suma_pas_curent;
        suma_pas_curent += 1.0/ fact(i);
    }
    return suma_pas_curent;
}
int main(){
    double precizie;
    printf("Introduceti precizia pentru calculul lui e:");
    scanf("%lf", &precizie);
    printf("e=%.10f", e(precizie));

    return 0;
}



/* Dati o implementare a functiei substr care ne indica daca un sir s1 apare
 * ca subsir al unui sir s2,  iar rezultatul este prima pozitiei pe care apare
 * s1 in s2 sau -1 in caz contrar
 * Exemplu: s1=bella, s2=anabella substr(s1,s2)=3
 * daca s1=anabela si s2=anamaria substr(s1,s2)=-1*/
#include "stdio.h"
int substr(char s1[], char s2[]){
    int i,j;
    // parcurg toate caracterele din sirul s2
    for (i=0;s2[i];i++){
        // verific daca s1 nu incepe cu subsir al lui s2 la pozitia i
        for (j=0;s1[j]==s2[i+j] && s1[j] && s2[i+j]; j++);
        if(s1[j]=='\0') return i; //s1 e subsir a lui s2 daca iesirea din for e facuta
        // prin terminarea sirului s1
    }
    // daca nu e subsir, returnez -1
    return -1;
}
int main() {
    char s1[100], s2[100];

    printf("s1=");
    scanf("%s", s1);

    printf("s2=");
    scanf("%s", s2);

    if(substr(s1,s2)==-1) {
        printf("%s nu este subsir a lui %s\n", s1, s2);
    } else {
        printf("%s este subsir a lui %s incepand cu pozitia %i\n", s1, s2, substr(s1,s2));
    }
    return 0;
}
