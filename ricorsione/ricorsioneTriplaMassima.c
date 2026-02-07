#include <stdio.h>


int TriplaSomma( int array[], int lungh){
    
    if(lungh<3)
        return 0;
    
    int sommaCorr=array[0]+array[1]+array[2];
    int maxsomma=TriplaSomma(array+1, lungh-1);
    
    if(maxsomma>sommaCorr){
        return maxsomma;
    }

    return sommaCorr;
}







int main(){
    int n;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d",&n);
    int array[n];
    
    for(int i=0; i<n; i++){
        printf("Inserisci un numero: ");
        scanf("%d", &array[i]);
    }
    
        printf("La somma equivale a: %d",TriplaSomma(array,n));
}