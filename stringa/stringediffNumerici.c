/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int diffNumerici(char stringa[]){
    int i;
    int diffatt;
    int diffmax;
    int ultimonum;
    int numattu;
    
    diffmax=-1;
    ultimonum=-1;
    i=0;
    
    while(stringa[i]!=-1){
        if(stringa[i]>='0'&&stringa[i]<='9'){
            numattu= stringa[i]-'0';
            
            if(ultimonum!=-1){
            if(numattu>ultimonum)
                diffatt= numattu - ultimonum;
            else
                diffatt= ultimonum - numattu;
            if(diffatt>diffmax)
                diffmax=diffatt;
            }
            ultimonum=numattu;

        }
        i++;
    }
    return diffmax;
}

int main() {
    char stringa[50];
    printf("Inserisci una stringa: ");
    fgets(stringa,50, stdin);
    stringa[strlen(stringa)-1]='\0';
    
    int differenza= diffNumerici(stringa);
    if(differenza==-1)
        printf("Non ci sono numeri nella stringa!");
    else
        printf("la differenza tra i numeri: %d", differenza);
}


