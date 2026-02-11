#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int array[], int lunghezza){
    //caso base
    if(lunghezza<3)
        return 1;
    int min=array[0];
    if(min>array[1])
        min=array[1];
    if(min>array[2])
    min=array[2];

    if(min%2==0)
        return 0;
    
    return minimoDispari(array+1, lunghezza-1);
}

/* funzione che conta ... */
int quantiNumeri() {
    FILE* fp=fopen("interi.dat", "rb");
    if(fp==NULL)
        return 0;
    int conta=0;
    int temp;
    while(fread(&temp, sizeof(int),1,fp)){
            conta++;
        }
    fclose(fp);
    return conta;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
    FILE* fp=fopen("interi.dat", "rb");
    if(fp!=NULL){
        fread(sequenza, sizeof(int),lunghezza,fp);
        fclose(fp);
    }
}

/* funzione che scrive ... */
void scriviNumeri(int array[], int lunghezza) {
    FILE* fp=fopen("interi.dat", "wb");
    if(fp!=NULL){
        fwrite(array, sizeof(int),lunghezza , fp);
        fclose(fp);
    }
}

/* funzione principale */
int main() {
    int lunghezza; 		//	lunghezza dell'array
	int scelta;				//	scelta dell'utente

    /* acquisizione dati e lettura dell'array da input */
    printf("Vuoi introdurre una nuova sequenza (premi 1) oppure recuperarla da file (premi 2)? ");
    scanf("%d",&scelta);

	/* introduzione sequenza da input */
	if(scelta==1) {
		/* determina la lunghezza della sequenza */
		printf("Introduci la lunghezza della sequenza: ");
		scanf("%d",&lunghezza);

		/* crea l'array e leggine i valori degli elementi */
		int array[lunghezza];
		printf("Scrivi %d elementi \n",lunghezza);
		for(int i=0;i<lunghezza;i++)
			scanf("%d",&array[i]);

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf("Il minimo fra i tre interi di ogni tripla è dispari!\n");
		else
			printf("Almeno un minimo di una tripla non é dispari!\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
	/* recupero sequenza da file */
	else {
		/* determina la lunghezza della sequenza */
		lunghezza = quantiNumeri();

		/* crea l'array e leggine i valori degli elementi da file */
		int array[lunghezza];
		leggiNumeri(array,lunghezza);
		printf("Ecco la sequenza recuperata\n");
		for(int i=0;i<lunghezza;i++)
			printf("%d ", array[i]);
		printf("\n");

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf("Il minimo fra i tre interi di ogni tripla è dispari!\n");
		else
			printf("Almeno un minimo di una tripla non é dispari!\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}