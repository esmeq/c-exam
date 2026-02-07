#include <stdio.h>

int TriplaDiversa(int array[], int n){
    //caso base
    if(n<3)
        return 1;
    if(array[0]==array[1]||array[0]==array[2]||array[1]==array[2])
        return 0;
        
    return TriplaDiversa(array+1, n-1);
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
    if(TriplaDiversa(array,n))
        printf("Le triple sono tutte diverse!");
    else
        printf("Ci sta almeno una tripla uguale!");
    return 0;
      
}