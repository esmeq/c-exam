#include <stdio.h>



float potenza(float base, int espo){
    if(espo==0)
        return 1;
    else
        return base*potenza(base, espo-1);
}

float polinomio(float array[], int grado, float x){
    if(grado==0)
        return array[0];
    return array[grado]*potenza(x,grado)+polinomio(array,grado+1,x);
}


int main(){
    int grado;
    float x;
    printf("Di che grado é il polinomio? ");
    scanf("%d",&grado);
    float array[grado+1];
    
    
    for(int i=0; i<=grado; i++){
        printf("Inserisci il coefficiente di grado %d: ", i);
        scanf("%f", &array[i]);
    }
    printf("Inserisci l'incognita: ");
    scanf("%f", &x);
    
    float ris= polinomio(array, grado, x);
    printf("Il risulato: %f", ris);

}