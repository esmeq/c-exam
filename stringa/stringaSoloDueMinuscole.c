#include <stdio.h>
#include <string.h>

void soloDueMinuscoli(char stringa[]){
    
    char nuova[50];
    int nuovoi=0;
    
    int i=0;
    while(stringa[i]!='\0'){
        
        if(stringa[i]>='a'&&stringa[i]<='z'){
            int trovato=0;
            int minuscola=i;
            nuova[nuovoi++] = stringa[minuscola];
            while(stringa[i]>='a'&&stringa[i]<='z'){
                trovato++;
                i++;
            }
            
            if(trovato>=2)
                nuova[nuovoi++]=stringa[minuscola+1];
        }
        else{
            nuova[nuovoi++]=stringa[i];
            i++;
        }
    }
    
    nuova[nuovoi]='\0';
    strcpy(stringa, nuova);
}

int main(){
    char stringa[50];
    printf("Inserisci una stringa: ");
    fgets(stringa,50,stdin);
    stringa[strlen(stringa)-1]='\0';
    
    soloDueMinuscoli(stringa);
    printf("La nuova stringa: %s", stringa);
}