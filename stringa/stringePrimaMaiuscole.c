#include <stdio.h>
#include <string.h>

void primaMaiuscole(char stringa[]){
    char nuovastringa[50];
    int i=0;
    int nuovoi=0;
    
    while(stringa[i]!='\0'){
        if(stringa[i]>='A' && stringa[i]<='Z')
            nuovastringa[nuovoi++]= stringa[i];
        i++;
    }
    i=0;
    while(stringa[i]!='\0'){
        if(stringa[i]>='a' && stringa[i]<='z')
            nuovastringa[nuovoi++]= stringa[i];
        i++;
    }
    i=0;
    while(stringa[i]!='\0'){
        if(!((stringa[i]>='A' && stringa[i]<='Z')||(stringa[i]>='a' && stringa[i]<='z')))
            nuovastringa[nuovoi++]= stringa[i];
        i++;
    }
    nuovastringa[nuovoi]='\0';
    strcpy(stringa, nuovastringa);
}


int main() {
    char stringa[50];
    printf("Inserisci la stringa: ");
    fgets(stringa,50,stdin);
    stringa[strlen(stringa)-1]='\0';
    
    primaMaiuscole(stringa);
    printf("La nuova stringa:\n%s", stringa);
}