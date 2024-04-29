// Folosind pointeri să se scrie o funcţie C care returnează lungimea unui şir de
// caractere (funcţia strlen –cu pointeri!). 

#include <stdio.h> // problema gen tip examen

int mystrlen(char *s) {
    char *p = s;
    while(*p) p++;
    return (p-s);
}

int main(void) {
    char s[100];
    puts("s="); gets(s);
    printf("Sirul '%s' are %d caractere", s, mystrlen(s));

    return 0;
}


// varianta 2

int mystrlen(char *s){
    int i = 0;
    while(*(s+i)) i++;
    return (i);
}



// varianta 3
int mystrlen(char a[])
{ int n;
for(n=0;a[n];n++); //ciclul for se oprește în momentul întâlnirii octetului
// null care termină orice şir de caractere
return(n);
}



// Folosind pointeri să se scrie o funcție C care primind ca și parametru 2 siruri de
// caractere, le concatenează cu obținerea noului sir in primul argument al funcției
// (implementare pentru funcția strcat –cu pointeri!).

// problema facuta in lab 8, dar de data asta o facem cu pointeri


#include <stdio.h>

char* mystrcat(char* dest, char* s)
{ // il facem pe p sa puncteze spre sfarsitul lui dest
    char* p = dest;
    while(*p)p++;//sau while(*p!='\0') p++;
    // Adaugam caracterele lui s la finalul lui dest
    while((*p++=*s++)); // sau while(*s!='\0')*p++=*s++;*p='\0';
    //strcat() intoarce adresa inceputului sirului dest
    return dest;
}

int main ()
{
    char dest[100]= "Hello ";
    char nume[100];
    printf("nume="); scanf("%s", nume);
    printf("%s",mystrcat(mystrcat(mystrcat(mystrcat(dest, nume), "! How "), "are "), "you?"));
    
    return 0;
}

// varianta 2

char* mystrcat(char* dest, char* s)
{ // il facem pe p sa puncteze spre sfarsitul lui dest
    int i = 0;
    while(*(dest+i))i++;//sau while(*p!='\0') p++;
    // Adaugam caracterele lui s la finalul lui dest
    while((*(dest+i++)=*s++)); // sau while(*s!='\0')*p++=*s++;*p='\0';
    //strcat() intoarce adresa inceputului sirului dest
    return dest;
}

// Folosind pointeri să se scrie o funcție C care primind ca si parametru 2 șiruri de
// caractere returnează un număr negativ dacă primul sir este mai mic, 0 dacă cele 2
// siruri sunt egale si un număr pozitiv dacă primul sir este mai mare decât al 2-lea.
// Comparațiile sunt lexicografice. (implementare pentru funcția strcmp –cu pointeri!). 

// Prob. din lab8, dar de data asta cu pointeri
#include <stdio.h>

int mystrcmp(char *s, char *t) {
    //pana cand perechile de caractere curente din s si t sunt egale
    //ne pozitionam pe urmatoarea pereche de caractere
    for (; *s == *t; s++, t++)
    if (!*s)//*s!='\0'
    // daca am ajuns la sfarsitul amebele siruri si ele sunt identice
    // returnam 0
    return(0);
    // returnam diferența dintre codurile ASCII ale primei perechi de caractere
    // diferite
    return(*s - *t);
}

int main ()
{
    char s1[100], s2[100];
    int rez; 
    
    printf("s1=");scanf("%s", s1);
    printf("s2=");scanf("%s", s2);
    
    rez = mystrcmp(s1, s2);
    
    if(rez<0) printf("%s < %s ", s1, s2);
    else if(rez>0) printf("%s > %s ", s1, s2);
    else printf("%s = %s ", s1, s2);
    
    return 0;
    
}


//  PROBLEME EXAMEN !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Se citesc de la tastatura 2 siruri si un intreg i. Sa se gaseasca a i-a aparitie a sirului 2 in sirul 1.
// (funtia strstr() din string.h)
#include <stdio.h>
#define FALSE 0
// testeaza daca sirul Y apare la inceputul sirului X (sau mai bine zis apare pe pozitia curenta desemnata de X)
int compare(char *X, char *Y){
    //cat timp nu am ajuns la sfarsitul vreunui sir (X sau Y)
    while (*X && *Y){   
        if (*X != *Y) {
            return FALSE;
        }
 
        X++;
        Y++;
    }
    return (*Y == '\0');
}
// Functia care implementeaza strstr()
const char* mystrstr(char* X, char* Y, int index){
    int nb_app = 0;
    while (*X)//pana cand nu am ajuns la sfarsitul lui X
    {
        if ((*X == *Y) && compare(X, Y)) {//testam daca Y apare incepeand cu pozitia curenta a lui X
            nb_app++;
            if(index==nb_app) return X;
        }
        //trec la urmatoare pozitie din X 
        X++;
    }
    //daca nu am gasit a index aparitie a lui Y in X returnez NULL
    return NULL;
}
 
// Implement `strstr()` function in C
int main(){
    char *X = "Mama mare are mere, are mere, are mere";
    char *Y = "are";
 
    printf("%s\n", mystrstr(X, Y, 2));
 
    return 0;
}


// Se citeste un sir de la tastatura sa se afiseze inversul acelui sir cu ajutorul functiilor(cu tablouri).
// Conversie dinspre tablouri spre pointeri:
// a[i] <=> *(a+i) (regula 1)
// Conversie dinspre pointeri spre tablouri:
// a+i <=> &a[i]

// s=amar\0 => inverse=rama\0

#include <stdio.h>
#include <stdlib.h>
int mystrlen(char s[]){
    int i=0;
    while(s[i]) i++;
    return i;
}

char* myinverse(char s[]){
    int i,j;
    char* inverse = malloc(sizeof(char)*(mystrlen(s) + 1));//aloc spatiu pentru sirul invers
    inverse[mystrlen(s)]='\0';//echivalenta    *(inverse+mystrlen(s))='\0';vezi regula 1
    //parcurg sirul inverse de la sfarsit spre inceput si 
    //il umplu cu caracterele din sirul s luate de la inceptului acestuia spre sfarsitul lui
    for(i=mystrlen(s)-1,j=0; i>=0;i--,j++)
        inverse[i] = s[j];
    return inverse;
}
 
int main(){
    char sir[100] = "amar";
    printf("%s\n", myinverse(sir));
    return 0;
}

// Se citeste un sir de la tastatura sa se afiseze inversul acelui sir cu ajutorul functiilor(cu pointeri sau nu).

#include <stdio.h>
#include <stdlib.h>
 

int mystrlen(char*s){
    char*p = s;
    while(*p) p++;
    return p-s;
}

char* myinverse(char* s){
    char* inverse = (char*) malloc(sizeof(char)*(mystrlen(s) + 1));//aloc spatiu pentru sirul invers
    char* p;
    *(inverse+mystrlen(s))='\0'; //inverse[mystrlen(s)]='\0';
    for(p = inverse + mystrlen(s)-1; p>=inverse;p--,s++) //inverse = &inverse[0] 
        *p = *s;
    return inverse;
}
 
// Implement `strstr()` function in C
int main(){
    char *X = "Mama";
    printf("%s\n", myinverse(X));
    return 0;
}






#include <stdio.h>

int main()
{
    int v = 10;
    int *p = &v;
    char a[] = "Un sir";//tipul lui s e const char*
    char *p2=a;
    
    printf("Variabila %d se afla la adresa %p\n", v, p);
    //& operator de adresare/referentiere =>se aplica pe o variabila
    //* operator de dereferentiere =>se aplica pe un pointer
    printf("Variabila %d se afla la adresa %p\n", *p, p);
    //&*p==p
    printf("&*p==p? %s\n", &*p==p?"TRUE":"FALSE");
    //*&v==v
    printf("*&v==v? %s", *&v==v?"TRUE":"FALSE");
    //corespondenta intre notatiile cu pointeri si cele cu tablouri 
    //a[i] == *(a+i) //elementul care se adla la adresa (a + i)
    //&a[i] == &*(a+i) = a + i
    
    return 0;
}





