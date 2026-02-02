/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

void shift(char stringa[], int x){
    int lungh= strlen(stringa);
    if(lungh==0)
        return;
    x=x%lungh;
    
    for(int i=0; i<x; i++){
        char ultimo= stringa[lungh-1];
        for(int j=lungh-1; j>0; j--){
            stringa[j]=stringa[j-1];
        }
        stringa[0]=ultimo;
    }
}

int main(){
    char stringa[50];
    int n;
    printf("Introduci la stringa: ");
    fgets(stringa,50,stdin);
    stringa[strlen(stringa)-1]='\0';
    printf("Quante volte vuoi spostarla? ");
    scanf("%d", &n);
    
    shift(stringa, n);
    printf("La nuova stringa:\n%s",stringa);
}