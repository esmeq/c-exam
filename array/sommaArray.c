/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int sommaElementi(int array[], int n){
    int somma=0;
    for(int i=0; i<n; i++){
        somma+=array[i];
    }
    return somma;
}

int main() {
    int lungh;
    int somma;
    printf("Quanti interi vuoi inserire? ");
    scanf("%d", &lungh);
    int array[lungh];
    for(int i=0; i<lungh; i++){
        printf("Inserisci l'intero: ");
        scanf("%d", &array[i]);
    }
    somma=sommaElementi(array,lungh);
    printf("La somma corrisponde a: %d", somma);
}