#include <stdio.h>
#include <string.h>

void AlPiuDue( char stringa[]){
    int trovato=0;
    int i=0;
    int nuovoi=0;
    char nuova[50];
    
    while(stringa[i]!='\0'){
        trovato=1;
        while(stringa[i+trovato]==stringa[i]){
            trovato++;
        }
        nuova[nuovoi++]=stringa[i];
        if(trovato>=2){
            nuova[nuovoi++]=stringa[i];
        }
        i+=trovato;
    }
    nuova[nuovoi]='\0';
    strcpy(stringa, nuova);
}


int main(){
    char stringa[50];
    printf("inserisci una stringa: ");
    fgets(stringa,50,stdin);
    stringa[strlen(stringa)-1]='\0';
    
    AlPiuDue(stringa);
    printf("La nuova stringa: %s", stringa);
    
}