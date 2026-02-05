#include <stdio.h>


int recProd(int x1, int x2){
    int prod;
    //caso base
    if(x2==0)
    prod=0;
    
    else
    prod= x1+recProd(x1,x2-1);
    
    return prod;
}




int main(){ 
    int x1,x2;
    printf("Inserisci i numeri di cui vuoi il prodotto:\n");
    scanf("%d", &x1);
    scanf("%d", &x2);
    printf("Il loro prodotto: %d", recProd(x1,x2));
}