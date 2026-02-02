/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int numMax(char stringa[]){
int i=0;
int max=-1;
int num=0;
int trovato=0;

while(stringa[i]!='\0'){
    if(stringa[i]>='0'&& stringa[i]<='9'){
        trovato=1;
        num=0;
        while(stringa[i]>='0'&&stringa[i]<='9'){
            num= num*10 + (stringa[i]-'0');
            i++;
        }
        if(num>max)
            max=num;
    }
    i++;
}
if(!trovato)
    return -1;
    
return max;
}


int main() {
    char stringa[50];
    printf("Inserisci una stringa: ");
    fgets(stringa,50,stdin);
    stringa[strlen(stringa)-1]='\0';
    
    int valore= numMax(stringa);
    if(valore==-1)
        printf("La stringa non contiene numeri!");
    else
        printf("Il valore dei numeri: %d", valore);
}