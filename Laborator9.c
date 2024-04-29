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




// varianta 3




// Folosind pointeri să se scrie o funcție C care primind ca și parametru 2 siruri de
// caractere, le concatenează cu obținerea noului sir in primul argument al funcției
// (implementare pentru funcția strcat –cu pointeri!).

// problema facuta in lab 8, dar de data asta o facem cu pointeri

