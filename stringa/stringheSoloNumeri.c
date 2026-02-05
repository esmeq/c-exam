#include <stdio.h>
#include <string.h>

void soloNumeri(char stringa[]){
    char nuovastringa[50];
    int trovato=0;
    int nuovoi=0;
    
    int i=0;
    while(stringa[i]!='\0'){
        if(stringa[i]>='0' && stringa[i]<='9'){
            
            nuovastringa[nuovoi++]=stringa[i];
            trovato=1;
        }
        i++;
    }
    
    
    if(trovato==0){
        printf("Non ci sono numeri nella stringa!");
    }
    
    nuovastringa[nuovoi]='\0';
    strcpy(stringa,nuovastringa);
}

int main(){
    char stringa[50];
    printf("Inserisci una stringa: ");
    fgets(stringa,50,stdin);
    stringa[strlen(stringa)-1]= '\0';
    
    soloNumeri(stringa);
    printf("La nuova stringa: %s", stringa);
    return 0;
}
