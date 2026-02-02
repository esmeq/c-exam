/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void inverso(int array[], int lungh, int array2[]){
    for(int i=0; i<lungh; i++){
        array2[i]= array[lungh-1-i];
    }
}

int main(){
    int n;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);
    
    int array[n];
    for(int i=0; i<n; i++){
        printf("Inserisci il numero: ");
        scanf("%d", &array[i]);
    }
    
    int array2[n];
    inverso(array, n, array2);
    printf("La nuova sequenza: ");
    for(int i=0; i<n; i++){
        printf("%d", array2[i]);
    }
}