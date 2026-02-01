#include <stdio.h>

int positivi(int array[], int lungh){
    int cont=0;
    for(int i=0; i<lungh; i++){
            if(array[i]>0)
                cont++;
    }
    return cont;
}

int main(){
    int n;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);
    int array[n];
    for(int i=0; i<n; i++){
        printf("Inserisci un numero: ");
        scanf("%d", &array[i]);
    }
    int pos= positivi(array,n);
    int positiv[pos];
    int k=0;
    for(int i=0; i<n; i++){
        if(array[i]>0){
            positiv[k]=array[i];
            k++;
        }
            
    }
    printf("La nuova sequenza: ");
    for(int j=0; j<pos; j++){
        printf("%d ", positiv[j]);
    
    }
}