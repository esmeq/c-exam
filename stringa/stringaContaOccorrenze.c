#include <stdio.h>
#include <string.h>

void contaOccorrenze(char stringa[]){
    if(stringa[0]=='\0'){
        printf("La stringa é vuota!");
        return;
    }
    
    char charMax=stringa[0];
    int maxCount=1;
    
    int i=0;
    char charCurr=stringa[0];
    int count=1;
    
    i=1;
    while(stringa[i]!='\0'){
        if(charCurr==stringa[i]){
            count++;
        }
        else{
            if(count>maxCount){
                maxCount=count;
                charMax=charCurr;
            }
            charCurr=stringa[i];
            count=1;
        }
        i++;
    }
    if(count>maxCount){
        maxCount=count;
        charMax=charCurr;
    }
    printf("Il carattere con piu occorrenze %c, con %d occorrenze.", charMax, maxCount);
}

int main() {
    char stringa[50];
    printf("Inserisci la stringa: ");
    fgets(stringa,50,stdin);
    stringa[strlen(stringa)-1]='\0';
    
    contaOccorrenze(stringa);
    return 0;
}