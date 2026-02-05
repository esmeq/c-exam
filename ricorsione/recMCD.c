#include <stdio.h>

int recMCD(int m, int n){
    int mcd;
    //caso base
    if(n==0)
        mcd=m;
    else
    mcd=recMCD(n,m%n);

    return mcd;
}


int main(){
    int m,n;
    printf("Inserisci un numero di cui vuoi sapere l'mcd:\n");
    scanf("%d", &m);
    printf("Inserisci l'altro:\n");
    scanf("%d", &n);
    
    printf("Il risulato:\n%d", recMCD(m,n));
}