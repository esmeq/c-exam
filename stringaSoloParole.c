#include <stdio.h>
#include <string.h>

void soloParole(char stringa[]){
    int i=0;
    int nuovoi=0;
    char parola[50];
    int trovata=0;
    
    while(stringa[i]!='\0'){
        if((stringa[i]>='a'&&stringa[i]<='z')||(stringa[i]>='A'&&stringa[i]<='Z')){
            parola[nuovoi++]= stringa[i];
            trovata=1;
        }
        else{
            if(trovata){
                parola[nuovoi++]=' ';
                trovata=0;
            }
        }
        i++;
    }
    parola[nuovoi]='\0';
    strcpy(stringa, parola);
}

int main(){
    char stringa[50];
    printf("Inserisci una stringa: ");
    fgets(stringa,50,stdin);
    stringa[strlen(stringa)-1]='\0';
    
    soloParole(stringa);
    printf("La nuova stringa: %s",stringa);
   
}