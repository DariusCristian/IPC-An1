/*1.Se citeste un sir de cel putin 10 caractere.
 * Sa se stearga primele 5 caractere din sir*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[100];

    do {
        puts("s(cel putin 10 caractere)="); gets(s);
    } while (strlen(s)<10);

    strcpy(s, s+5);
    puts(s);
    return 0;
}

/*Se citeste un sir de cel putin 10 caractere.
 * Sa se stearga ultimele 5 caractere din sir*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[100];

    do {
        puts("s(cel putin 10 caractere)="); gets(s);
    } while (strlen(s)<10);

    strcpy(s+(strlen(s)-5), s+strlen(s));    // sau aici mai usor sa scriu doar s[strlen(s)-5]='\0';
    puts(s);
    return 0;
}

/*2. Se citesc 2 siruri de caractre s1, s2 de la tastatura
 * Sa se stearga toate aparitiile sirului s2 in sirul s1.
 * Ex:
 * s1=Ana are mere si pere
 * s2=mere*/

#include <stdio.h>
#include <string.h>

int main() {
   char s1[100], s2[100];
   int i;

   puts("s1=");
   gets(s1);

   puts("s2=");
   gets(s2);

   // cat timp gasesc o noua aparitie a lui s2 in s1
   while(strstr(s1,s2)) {
       // sterg aparitiile lui s2 din s1 deplasand caracterele aflate dupa s2
       // in s1 si in locul lui s2
       strcpy(strstr(s1,s2), strstr(s1,s2) + strlen (s2));
   }
   puts(s1);
   return 0;
}


/*3. Se citesc 2 siruri de caractre s1, s2 de la tastatura
 * Sa se stearga toate aparitiile sirului s2 in sirul s1.
 * Ex:
 * s1=Ana are mere si pere
 * s2=mere*/

#include <stdio.h>
#include <string.h>

int main() {
   char s1[100], s2[100];
   int i;

   puts("s1=");
   gets(s1);

   puts("s2=");
   gets(s2);

   // cat timp gasesc o noua aparitie a lui s2 in s1
   while(strstr(s1,s2)) {
       // sterg aparitiile lui s2 din s1 deplasand caracterele aflate dupa s2
       // in s1 si in locul lui s2
       strcpy(strstr(s1,s2), strstr(s1,s2) + strlen (s2));
       // s1=mere pere si prune, s2=pere
       // strstr(s1,s2) = s1+5
       // pe pozitia 5 incepe pere
       // strstr(s1,s2) + strlen (s2) - te deplaseaza pana pe pozitia unde se gata s2=pere
       // strcpy inlocuieste
   }
   puts(s1);
   return 0;
}


/*4. Se citeste un cuvant s format din cel mult 100 de litere mici.
 * Se citeste un numar natural p (p<=100)
 * Afisati cuvintele obtinute prin eliminarea unei secvente de p
 * litere din s.
 * Exemplu: s="adina", si p=3, rezulta cuvintele:
 * na aa ad*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[101], s_c[101];
    int i,p;

    do{
        puts("s(cel mult 100 de caractere=");
        gets(s);
    } while (strlen(s)>100);

    do {
        printf("p(<%d)=", strlen(s));
        scanf("%d", &p);
    } while (p >= strlen(s));

    for (i=0;i <= strlen(s) - p; i++){
        strcpy(s_c, s);
        strcpy(s_c+i, s_c+i+p);
        puts(s_c);
    }
    /* s_c + i: Este un pointer care indică poziția în șirul s_c de unde începem să copiem.
        s_c + i + p: Este un pointer care indică poziția în șirul s_c după secvența de p caractere 
        care trebuie eliminată.*/
   return 0;
}


/*5. Se citesc 3 siruri de caractere
 * Sa se inlocuiasca toate aparitiile sirului s2 in sirul s1 cu sirul s3*/

#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100], s3[100], s4[100];
    char* p;
    int i;

    puts ("s1=");
    gets (s1);
    puts ("s2=");
    gets (s2);
    puts ("s3=");
    gets (s3);

    // cat timp gasesc o noua aparitie a lui s2 in s1
    while(p= strstr(s1,s2)){
        // sterg pe s2 de pe pozitia gasita
        strcpy(p,p + strlen(s2));
        // p + strlen(s2): Pointer la poziția imediat următoare după apariția lui s2 în s1.
        strcpy(s4,s1);
        // copiez pe s3 pe locul in care se afla s2
        strcpy(s4+(p-s1), s3);
        // s4 + (p - s1): Pointer la poziția în s4 corespunzătoare poziției inițiale a lui s2 în s1
        // copiez caracterele ramase dupa s2
        strcpy(s4+(p-s1)+ strlen(s3), p);
        //  Copiază restul șirului s1 (începând de la poziția p) în s4, după s3.
        strcpy(s1,s4);
    }
    puts(s1);
   return 0;
}

