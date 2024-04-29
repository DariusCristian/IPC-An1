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

