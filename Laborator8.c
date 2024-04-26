/* 1. Să se scrie o funcție C care primind ca si parametru 2 șiruri de caractere returnează 
un număr negativ dacă primul sir este mai mic, 0 dacă cele 2 siruri sunt egale si un număr pozitiv
dacă primul sir este mai mare decât al 2-lea. Comparațiile sunt lexicografice. 
(implementare pentru funcția strcmp) 

strcmp - in libraria <stream.h> /// este o functie 

METODA 1 */

#include "stdio.h"

// returneaza <0 daca s<t,
// 0 daca s==t,
// >0 daca s>t
int mystrcmp (char s[], char t[]) {
    int i = 0; // ne pozitionam pe primul caracter din ambele siruri
    while (s[i] == t[i])
        if (s[i++] == '\0') // ne pozitionam pe urmatoarea pereche de caractere
            return (0); // daca am ajuns la sfarsitul ambelor siruri si ele sunt egale caracter cu caracter returnam 0
        return (s[i] - t[i]); //returnam diferenta dintre codurile ASCII ale primei perechi de caractere diferite
}


int main(void) {
     int rez;
     char s[4] = "Ana"; // sau s[4] = {'A', 'n', 'a', '\0'}
     char t[9] = "Anamaria";

     rez = mystrcmp(s ,t);

     if (rez > 0)
         printf("Sirul %s e mai mare decat %s", s,t);
     else if (rez < 0)
         printf("Sirul %s e mai mic decat %s", s,t);
     else
         printf("Sirul %s e mai egal decat %s", s,t);
    return 0;
}


// METODA 2

#include "stdio.h"

int mystrcmp (char a[], char b[]){
    int i;
    for(i=0;a[i]&& b[i] && a[i]==b[i]; i++); // foarte importante acest punct si virgula, daca nu il pun, inseamna ca returnul ii in interiorul for-ului
    /*iesim din ciclu daca unul din cele 2 siruri a ajuns la sfarsit
     * prin intalnirea octetului nul sau cand elementele corespunzatoare
     * din cele 2 siruri difera*/
    return (a[i]-b[i]);
}
int main(void) {
    int rez;
    char s[4] = "Ana"; // sau s[4] = {'A', 'n', 'a', '\0'}
    char t[9] = "Anamaria";

    rez = mystrcmp(s ,t);

    if (rez > 0)
        printf("Sirul %s e mai mare decat %s", s,t);
    else if (rez < 0)
        printf("Sirul %s e mai mic decat %s", s,t);
    else
        printf("Sirul %s e mai egal decat %s", s,t);
    return 0;
}


// ** apostroafele sunt doar pentru caractere, pentru siruri sunt ghilimele




/* 2. Să se scrie o funcție C care primind ca și parametru 2 siruri de caractere, 
le concatenează cu obținerea noului sir in primul argument al funcției 
(implementare pentru funcția strcat). (poza cu explicatia pe telefon)

METODA 1 */

#include "stdio.h"

const char* mystrcat (char dest[], char s[]) {
    //il facem pe i sa refere marcatorul de sfarsit a lui dest
    int i = 0, j = 0;
    while (dest[i])i++; // sau while(dest[i]!='\0' i++);
    // adaugam caracterele lui s la finalul lui dest
    while(dest[i++]=s[j++]); // sau while(s[j]!='\0') dest [i++]=s[j++]; dest[i]='\0'
    // strcat() intoarce pointerul inceputul sirului dest
    return dest;
}

int main(void) {
    char dest[100] = "Hello ";
    printf("%s", mystrcat(dest, "world"));

    return 0;
}



// METODA 2

#include "stdio.h"

const char* mystrcat (char a[], char b[]) {
    int i,j;
    for (i=0; a[i]; i++) ; // ajungem cu i la sfarsitul sirului a
    for (j=0; a[i]=b[j]; i++, j++);
    // iesim din acest ciclu for cand ajungem la sfarsitul
    // sirului b, adica vom atribui lui a[i] valoarea 0
    return a;
}

int main(void) {
    char dest[100] = "Hello ";
    printf("%s", mystrcat(dest, "world"));

    return 0;
}



/* 3. Se citeste un text de la tastatură, terminat prin caracterul sfarsit de rand (enter). Să se scrie
programul C care determină numărul de apariții ale fiecărei litere din șir – literele mici și mari se consideră impreună.
(am poza cu rezolvarea scrisa in cuvinte)

PROBLEMA DE EXAMEN (poza pe telefon) */

#include <stdio.h>
#include <string.h>  // Pentru operațiuni cu șiruri de caractere

#define FALSE 0
#define TRUE !(FALSE)

int myisalpha(char c) {
    // Verifică dacă caracterul este o literă (minuscule sau majuscule)
    return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) ? TRUE : FALSE;
}

int mytoupper(char c) {
    // Transformă literele mici în majuscule
    return (('a' <= c && c <= 'z')) ? c - 'a' + 'A' : c;
}

int main(void) {
    char sir[1000];
    int aparitii[26] = {0};  // Tablou de frecvențe pentru litere
    int i;

    // Folosim fgets pentru a citi în siguranță textul de la utilizator
    printf("Introdu sirul: ");
    fgets(sir, sizeof(sir), stdin);

    // Eliminăm caracterul newline de la sfârșitul șirului
    sir[strcspn(sir, "\n")] = '\0'; // codul merge si fara linia asta

    // Calculăm frecvența fiecărei litere
    for (i = 0; i < strlen(sir); i++) {
        // Verificăm dacă este literă și convertim în majusculă
        if (myisalpha(sir[i])) {
            int index = mytoupper(sir[i]) - 'A';
            aparitii[index]++;
        }
    }

    // Afișăm frecvența fiecărei litere dacă este mai mare de 0
    for (i = 0; i < 26; i++) {
        // Dacă litera are cel puțin o apariție, o afișăm
        if (aparitii[i] > 0) {
            printf("Literele %c sau %c apar de %d ori\n", 'a' + i, 'A' + i, aparitii[i]);
        }
    }

    return 0;
}







