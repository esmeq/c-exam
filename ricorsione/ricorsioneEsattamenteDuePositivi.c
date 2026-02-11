#include <stdio.h>

int esattamenteDue(int array[], int lungh){
    //caso base
    if(lungh==2)
        return 1;
    if(!((array[0]>0 && array[1]>0 && array[2]<0) ||(array[0]>0 && array[1]<0 && array[2]>0)||(array[0]<0 && array[1]>0 && array[2]>0)))
        return 0;
    return esattamenteDue(array+1, lungh-1);
}

int main(){
    int n;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d",&n);
    int array[n];
    for(int i=0; i<n; i++){
        printf("Inserisci numero: ");
        scanf("%d", &array[i]);
    }
    if(esattamenteDue(array,n)){
        printf("La richiesta é rispettata!\n");
    }
    else
        printf("Almeno una tripla non rispetta la richiesta!\n");
}