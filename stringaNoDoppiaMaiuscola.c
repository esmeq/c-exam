#include <stdio.h>
#include <string.h>

void noDoppieMaiusc(char stringa[]){
    int lungh;
    if(lungh==0)
        printf("La stringa é vuota!");

    
   
    char nuovastringa[50];
    int nuovoi=0;
    
    int i=0;
    while(stringa[i]!='\0'){
        if(!((stringa[i]>='A'&& stringa[i]<='Z'))){
            nuovastringa[nuovoi++]=stringa[i];
        } 
        else{
            if(i==0 || stringa[i]!=stringa[i-1])
                nuovastringa[nuovoi++]=stringa[i];
        }
        i++;
    }
    nuovastringa[nuovoi]= '\0';
    strcpy(stringa, nuovastringa);
}


int main(){
    char stringa[50];
    printf("Inserisci una stringa: ");
    fgets(stringa,50,stdin);
    stringa[strlen(stringa)-1]='\0';
    
    noDoppieMaiusc(stringa);
    printf("La nuova stringa: %s",stringa);
   
}