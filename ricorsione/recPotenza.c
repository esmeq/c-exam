#include <stdio.h>

int recPot(int x, int y){
    int pot;
    //caso base
    if(y==0)
    pot=1;
    
    else
    pot=x*recPot(x,y-1);
    
    return pot;
}


int main(){
    int x,y;
    printf("Inserisci un numero di cui vuoi la potenza:\n");
    scanf("%d", &x);
    printf("Inserisci la potenza:\n");
    scanf("%d", &y);
    
    printf("Il risulato:\n%d", recPot(x,y));
}