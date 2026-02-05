#include <stdio.h>

int main() {
	int n;

	printf("Quanto deve essere grande la matrice? ");
	scanf("%d", &n);
	int matrice[n][n];
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j)
                matrice[i][j]=1;
            else
                matrice[i][j]=0;
        }
    }
    
    printf("La nuova matrice: ");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
        printf("%d", matrice[i][j]);
    printf("\n");
    }
}