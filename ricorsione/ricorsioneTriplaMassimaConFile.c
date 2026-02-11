#include <stdio.h>

int triplaSommaMassima(int array[], int lungh){
    //caso base
    if(lungh==2)
        return 0;
    int somma= array[0]+array[1]+array[2];
    int maxSomma= triplaSommaMassima(array+1,lungh-1);
    if(somma>maxSomma)
        return somma;
    return maxSomma;
}
int main(){
    int n;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d",&n);
    int array[n];
    for(int i=0; i<n; i++){
        printf("Inserisci numero: ");
        scanf("%d", &array[i]);
    }
    printf("La somma é:%d\n", triplaSommaMassima(array,n));


    FILE* fp=fopen("SommaTripla.dat", "wb");
    if(fp!=NULL){
        for(int i=0; i<n; i++){
            fwrite(&array[i], sizeof(int),1, fp);
        }
        fclose(fp);
        return 0;
    }
    return 1;
}