#include <stdio.h>
#include <string.h>

void soloNumeri(char stringa[]){
    int trovato=0;
    int i=0;
    int j=0;
    char nuova[50];
    
    while(stringa[i]!='\0'){
        if(stringa[i]>='0'&&stringa[i]<='9'){
        trovato=1;
        nuova[j++]=stringa[i];
        }
        i++;
        
    }
    nuova[j]='\0';
    strcpy(stringa, nuova);
}

int main(){
    char stringa[50];
    printf("Inserisci una stringa: ");
    fgets(stringa, 50, stdin);
    stringa[strlen(stringa)-1]='\0';
    
    soloNumeri(stringa);
    printf("La nuova stringa: %s");
}