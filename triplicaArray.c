/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void triplica(int array[], int lungh){
    for(int i=0; i<lungh; i++){
        array[i]*=3;
    }
}
int main(){
    int lungh;
    printf("Quanti interi vuoi inserire: ");
    scanf("%d", &lungh);
    int array[lungh];
    for(int i=0; i<lungh; i++){
        printf("Inserisci il numero: ");
        scanf("%d", &array[i]);
    }
    triplica(array, lungh);
    printf("Questa è la nuova sequenza:");
    for(int j=0; j<lungh; j++){
        printf("%d", array[j]);
    }
}