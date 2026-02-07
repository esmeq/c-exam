#include <stdio.h>

int Quadrato(int array[], int lungh){
    //caso base
    if(lungh<2)
        return 0;
    
    if(array[1]%array[0]==0 || array[0]%array[1]==0 )
        return 1;
    else
        return Quadrato(array+1, lungh-1);
    
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
    
    if(Quadrato(array, n)){
        printf("La sequenza contiene un quadrato!");
    }
    else
        printf("La sequenza non contiene un quadrato!"); 
}