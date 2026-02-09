#include <stdio.h>
#include <string.h>

void dueConsecutivi(char stringa[]){
    int i=0;
    int j=0;
    char nuova[50];
    while(stringa[i]!='\0'){
        if(stringa[i]>='0'&&stringa[i]<='9'){
            char numero=stringa[i];
            int inizio=i;
            while(stringa[i]==numero){
                i++;
            }
            int conta= i-inizio;
            if(conta==2 && stringa[inizio]==stringa[inizio+1]){
            //indice va gia avanti nel while
            }
            else{
                int k;   //indice temporaneo
                for(int k=inizio; k<i; k++){
                    nuova[j++]=stringa[k];
                }
            }
        }
        else { 
            nuova[j++]=stringa[i++];
        }
    }
    nuova[j]='\0';
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