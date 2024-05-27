1. Se citeşte un număr întreg pozitiv n. Folosind operatori pe biţi să se afişeze reprezentarea în baza 2 a numărului n. (Am poza pe telefon cu rezolvarea)

#include "stdio.h"
// problema cu operatorii pe biti
int main(void) {
    int i;
    unsigned n;
    printf("n=");
    scanf("%u", &n);

    for (i = 8*sizeof(n)-1; i >= 0; i--)
        /* deplasam bitul de pe pozitia i, i pozitii
         spre dreapta pentru
         a ajunge pe prima pozitie
         facem o conjunctie cu masca 000...0001 (numarul 1)
         pentru a obtine
         valoarea bitului (0 sau 1) */
        printf("%d", (n >> i)& 1);
    return 0;
}

Daca dorim sa eliminam zerourile nesemnificative codul devine: 

#include "stdio.h"
// problema cu operatorii pe biti
int main(void) {
    int i, cif_semn=0;
    // cif_semn indica daca am intalnit prima cifra semnificativa (un 1)
    unsigned n;
    printf("n=");
    scanf("%u", &n);

    for (i = 8*sizeof(n)-1; i >= 0; i--) {
        /* facem o disjunctie cu cifra de pe pozitia i pentru a vedea daca
         * este egala cu 1 */
        cif_semn |= (n >> i) & 1;
        // cif_semn = cif_semn | ((n >> i)& 1)
        // deplasam bitul de pe pozitia i, i pozitii spre dreapta pentru a ajunge pe prima pozitie
        // facem o conjunctie cu masca 000...0001 (numarul 1) pentru a obtine valoarea bitului (0 sau 1)
        if (cif_semn)
            printf("%d", (n >> i) & 1);
        // tiparim cifra doar daca este semnificativa
    }
    return 0;
}

2. Se citeşte un număr întreg n reprezentând numărul de elemente dintr-o mulţime şi un şir de n valori întregi reprezentând elementele acestei mulţimi. Folosind operatori pe biţi să se afişeze toate submulţimile mulţimii date.

#include "stdio.h"

// problema cu operatorii pe biti

void printSubmultimi (int multime[], int nr_elem)
{
    // nr_submultimi este egal cu (2**nr_elem - 1)
    unsigned int nr_submultimi = 1 << nr_elem;
    int contor, j;

    // contorul merge de la 0(000..0) la nr_submultimi-1(111..1)
    for (contor = 0; contor < nr_submultimi; contor++)
    /*contor parcurge toate valorile de la 0 la nr_submultimi - 1.
     * Fiecare valoare a contor reprezintă o submulțime prin
     * interpretarea fiecărui bit al său.*/
    {
        printf("{");
        for ( j = 0; j < nr_elem; j++)
        {
            /* Verificam daca al j-lea bit din contor are valoarea 1
             * Daca este 1 atunci tiparim multime[j] ca parte din submultimea curenta*/
            if (contor & (1<<j)) {
                printf("%d", multime[j]); }
        }
        printf("}\n");
    }
}

int main(void) {
    int multime[] = {1,2,3};
    printSubmultimi(multime, 3);
    return 0;
}



