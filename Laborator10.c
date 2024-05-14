#include <stdio.h>
#include <string.h>

struct persoana { // definim structura cu numele persoana
    char nume[20];
    char prenume[20];
    int varsta;
    char localitate[25]; 
// aici avem in final 69 de octeti 20+20+4+25
} sir[100]; /*variabila sir[100] va fi de tip structura persoana
 * functia pentru citirea inregistrarilor din fisier*/

int citeste_inregistrari (FILE *fp){
    int i=0;
    while(fscanf(fp, "%s %s %d %s", &sir[i].nume, &sir[i].prenume,
                 &sir[i].varsta, &sir[i].localitate)==4)
        i++;
    return i;
}

void sortare_varsta(int n){
    struct persoana tmp;
    int i, schimbare;
    do {
        for (schimbare=0, i=0; i<n-1;i++){
            if(sir[i].varsta > sir[i+1].varsta){
                tmp=sir[i];
                sir[i]=sir[i+1];
                sir[i+1]=tmp;
                schimbare=1;
            }
        }
    }while(schimbare==1);
}
//functia de ordonare a persoanelor dupa localitate
void sortare_localitate(int n) {
    struct persoana tmp;
    int i, schimbare;
    do {
        for(schimbare=0, i=0; i<n-1;i++)
            if(strcmp(sir[i].localitate, sir[i+1].localitate)==1){
                tmp=sir[i];
                sir[i]=sir[i+1];
                sir[i+1]=tmp;
                schimbare=1;
            }
    } while (schimbare==1);
}


void afiseaza_inregistrari(int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%s %s %d %s\n", sir[i].nume, sir[i].prenume, sir[i].varsta,
               sir[i].localitate);
    }
}

int main() {
    int nrinregistrari, numar=1, i;
    FILE *fp;
    fp=fopen("persoane.txt", "r"); //deschidem fisierul in mod citire
    if(fp==NULL) {// in caz de eroare
        printf("Nu am reusit deschiderea fisierului!\n");
        return -1;
    }
    nrinregistrari=citeste_inregistrari(fp);
    sortare_varsta(nrinregistrari); // sortam persoanele din sir dupa varsta
    printf("\nIntregistrarile sortate dupa varsta:\n");
    afiseaza_inregistrari(nrinregistrari);
    //numaram persoanele din fiecare varsta citita
    i=0;
    do {
        while((i+1<nrinregistrari)&&(sir[i].varsta==sir[i+1].varsta))
            i++,numar++;
        printf("\nAferent varstei &d ani avem %d inregistrari\n", sir[i].varsta, numar);
        i++;
        numar=1;
    }while(i<nrinregistrari);

    sortare_localitate(nrinregistrari); // sortam persoanele dupa localitate
    printf("Intregistrarile sortate dupa localitate:\n");
    afiseaza_inregistrari(nrinregistrari);
    i=0;
    do {
        while((i+1<nrinregistrari) && (strcmp(sir[i].localitate, sir[i+1].localitate)==0))
            i++,numar++;
        printf("\nAferent localitatii %s avem %d inregistrari\n", sir[i].localitate, numar);
        i++;
        numar=1;
    }while (i<nrinregistrari);

    fclose(fp); // inchidem fisierul
    /*https://www.geeksforgeeks.org/bubble-sort/
    This link explain the bubble sort, that we used here in this code*/
    return 0;
}
