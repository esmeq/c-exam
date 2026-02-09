#include <stdio.h>
#include <string.h>

void dueConsecutivi(char stringa[]){
int i=0;
int nuovoi=0;
char nuova[50];
    while(stringa[i]!='\0'){
        if(stringa[i]>='0'&&stringa[i]<='9'){
            int inizio=i;
            while(stringa[i]>='0'&&stringa[i]<='9'){
                i++;
            }
            
            int conta=i-inizio;
            if(conta==2){
                
            }
            else {
                int k;
                for(int k=inizio; k<i; k++){
                    nuova[nuovoi++]=stringa[k];
                }
            }
        }
        else{
            nuova[nuovoi++]=stringa[i++];
        }
    }
    nuova[nuovoi]='\0';
    strcpy(stringa, nuova);
}

int main(){
    char stringa[50];
    printf("Dammi una stringa:\n");
    fgets(stringa,50,stdin);
    stringa[strlen(stringa)-1]='\0';
    
    dueConsecutivi(stringa);
    printf("La nuova stringa:%s\n",stringa);
}