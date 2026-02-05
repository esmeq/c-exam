/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int doppiaStringa(char stringa[]){
    int lunghezza=strlen(stringa);
    if(lunghezza%2!=0)
        return 0;
    
    int metá= lunghezza/2;
    for(int i=0; i<metá; i++){
        if(stringa[i]!=stringa[i+metá])
            return 0;
    }
    return 1;
}


int main(){
    char stringa[50];
    printf("Introduci una stringa: ");
    fgets(stringa, 50, stdin);
    stringa[strlen(stringa)-1]='\0';
    
    if(doppiaStringa(stringa)){
        printf("La stringa consiste di due doppie stringhe");
    }
    else
        printf("La stringa non consiste di due doppie stringhe");   
}