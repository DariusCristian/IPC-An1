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
