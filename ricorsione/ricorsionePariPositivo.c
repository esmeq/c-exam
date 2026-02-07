#include <stdio.h>

int pariPositivo(int array[], int lungh){
    if(lungh<2)
        return 0;
    if((array[0]%2==0 && array[1]>0)  || (array[1]%2==0 && array[0]>0))
        return 1;
    return pariPositivo(array+1, lungh-1);
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
    
    if(pariPositivo(array,n))
        printf("La sequenza contiene un numero pari e il successivo/precedente dispari!");
    
    else
        printf("La sequenza non contiene un numero pari e il successivo/precedente dispari!");

}