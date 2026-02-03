#include <stdio.h>
#include <string.h>

void rendiMaiuscolo(char stringa[]){
    int i=0;
    while(stringa[i]!='\0'){
        if(stringa[i]>='a'&&stringa[i]<='z')
            stringa[i]= stringa[i]-('a'-'A');
        i++;
    }
}

int main() {
    char stringa[50];
    printf("Inserisci una stringa: ");
    fgets(stringa,50,stdin);
    stringa[strlen(stringa)-1]='\0';
    
    rendiMaiuscolo(stringa);
    
    printf("la nuova stringa: %s", stringa);
}