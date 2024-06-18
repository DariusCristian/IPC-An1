/*Se citeste un sir de cel putin 10 caractere.
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
