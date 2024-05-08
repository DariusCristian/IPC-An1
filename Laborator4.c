// problema 1 -> sa se tipareasca 1 2 2 3 3 3 4 4 4 4 5 5 5 5 5 

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,j,n;

    printf("n=");
    scanf("%d", &n);

    for (i=1;i<=n;i++)
        for (j=1;j<=i;j++)
            printf("%d ", i); // tiparim numarul
    printf("\n");
    return 0;
}


// problema 2 -> sa se tipareasca 1 1 2 1 2 3 1 2 3 4 1 2 3 4 5

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,j,n;

    printf("n=");
    scanf("%d", &n);

    for (i=1;i<=n;++i) // aici 
      //           ^- aici nu conteaza daca este ++i sau i++, output-ul va fii acelasi in ambele cazuri
        for (j=1;j<=i;j++) // si aici se intampla modificarile
            printf("%d ", j); // tiparim numarul
    printf("\n");
    return 0;
}




