#include <stdio.h>
#include <string.h>

int soloAlfabetici(char stringa[]){
    int trovato=0;
    int i=0;
    while(stringa[i]!='\0'){
        if(!((stringa[i]>='a'&&stringa[i]<='z')||(stringa[i]>='a'&&stringa[i]<='z'))){
            trovato=1;
            stringa[i]= '*';
        }
        i++;
    }
    return 0;
}

int main(){
    char stringa[50];
    printf("Inserisci una stringa: ");
    fgets(stringa,50,stdin);
    stringa[strlen(stringa)-1]='\0';
    
    int ris=soloAlfabetici(stringa);
    if(ris)
        printf("La stringa modificata: %s",stringa);
    else
        printf("La stringa contiene solo caratteri alfabetici!");
}