#include <stdio.h>
#include <string.h>

void alfabetici(char stringa[]){
    int lungh=strlen(stringa);
    if(lungh==0)
        printf("La stringa é vuota!");
    int i=0;
    int trovato=0;
    char nuovastringa[50];
    int nuovoi=0;
    while(stringa[i]!='\0'){
        if((stringa[i]>='a'&&stringa[i]<='z')||(stringa[i]>='A'&&stringa[i]<='Z')){
            trovato=1;
            nuovastringa[nuovoi++]=stringa[i];
        }
        i++;
    }
    nuovastringa[nuovoi]='\0';
    strcpy(stringa, nuovastringa);
}


int main(){
    char stringa[50];
    printf("Inserisci una stringa: ");
    fgets(stringa,50,stdin);
    stringa[strlen(stringa)-1]= '\0';
    
    alfabetici(stringa);
    printf("La nuova stringa: %s",stringa);
}