#include <stdio.h>


int recFatt(int numero){
    int fatt;
    //caso base
    if(numero==1)
    fatt=1;
    
    else
    fatt= numero*recFatt(numero-1);
    
    return fatt;
}




int main(){ 
    int numero;
    printf("Inserisci il numero di cui vuoi il fattoriale:\n");
    scanf("%d", &numero);
    printf("Il suo fattoriale: %d", recFatt(numero));
}