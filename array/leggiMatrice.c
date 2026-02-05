#include <stdio.h>

int main() {
    int ncolonne;
    int nrighe;
    
    printf("Quante righe? ");
    scanf("%d", &nrighe);
    printf("Quante colonne? ");
    scanf("%d", &ncolonne);
    int matrice[nrighe][ncolonne];
    
    for(int i=0; i<nrighe; i++){
        for(int j=0; j<ncolonne; j++){
            printf("Introduci il numero con indice riga %d e indice colonna %d: ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }
    printf("\n");
    for(int i=0; i<nrighe; i++){
        for(int j=0; j<ncolonne; j++){
            printf("%5d", matrice[i][j]);
        printf("\n");
        }
    }
}