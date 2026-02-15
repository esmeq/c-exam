#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Computer{
	char modello[30];
	int codice;
	int seriale[12];
}COMPUTER;


typedef struct Nodo{
	COMPUTER info;
	struct Nodo* prev;
	struct Nodo* next;
}NODO;

int main(){
	NODO* head=malloc(sizeof(NODO));
	head->prev=head;
	head->next=head;
	NODO* nuovo;

	COMPUTER pc;
	FILE* fp=fopen("Computer.dat","rb");
	if(fp==NULL){
		fp=fopen("Computer.dat","wb");
		fclose(fp);
	}
	else{
		while(fread(&pc, sizeof(COMPUTER),1,fp)){
			nuovo=malloc(sizeof(NODO));
			if(nuovo==NULL)
				return 1;
			else{
				nuovo->info=pc;

				nuovo->prev=head->prev;
				nuovo->next=head;
				nuovo->prev->next=nuovo;
				head->prev=nuovo;
			}
		}
		fclose(fp);
	}
	while(1){
		int scelta;
		printf("INSERISCI COMPUTER (1)\n");
		printf("VISUALIZZA COMPUTER (2)\n");
		printf("CANCELLA COMPUTER (3)\n");
		printf("ESISTE COMPUTER (4)\n");
		printf("ESCI (0)\n");
		scanf("%d", &scelta);
		
		if(scelta==0){
			fp=fopen("Computer.dat", "wb");
			if(fp==NULL){
				printf("Problemi a salvare il file!\n\n");
				return 1;
			}
			NODO* curr=head->next;
			while(curr!=head){
				fwrite(&(curr->info), sizeof(COMPUTER),1,fp);
				curr=curr->next;	
			}
			fclose(fp);

			curr=head->next;
			while(curr!=head){
				NODO* temp=curr;
				curr=curr->next;
				free(temp);
			}
			free(head);
			return 0;
		}
		
		else if(scelta==1){
			nuovo=malloc(sizeof(NODO));
			if(nuovo==NULL){
				return 1;
			}
			while(getchar()!='\n');
			printf("Inserisci il modello del pc:\n");
			fgets(nuovo->info.modello, 30, stdin);
			nuovo->info.modello[strlen(nuovo->info.modello)-1]='\0';

			printf("Inserisci 12 numeri separati per l'ip:\n");
			for(int i=0; i<12; i++)
				scanf("%d", &(nuovo->info.seriale[i]));
			if(head->next==head){
				nuovo->info.codice=1;
			}
			else{
				nuovo->info.codice=head->prev->info.codice+1;
			}
			
			nuovo->prev=head->prev;
			nuovo->next=head;
			nuovo->prev->next=nuovo;
			head->prev=nuovo;
		}
		else if(scelta==2){
			if(head->next==head){
				printf("Lista vuota!\n\n");
			}
			NODO* curr=head->next;
			while(curr!=head){
				printf("Modello computer: %s\n", curr->info.modello);
				printf("Codice identificativo: %d\n", curr->info.codice);

				printf("Numero seriale: ");
				for(int i=0; i<12; i++){
					printf("%d",curr->info.seriale[i]);
					if((i+3)%2==0 && i<11)
						printf(".");
				}
				printf("\n");
				curr=curr->next;
			}
		}
		else if(scelta==3){
			if(head->next==head){
				printf("Cancellazione non possibile!\n\n");
				continue;
			}
			NODO* curr=head->next;
			head->next=curr->next;
			curr->next->prev=head;

			free(curr);
			printf("Cancellazione eseguita!\n\n");
		}
		else if(scelta==4){
			int identificativo;

			if(head->next==head){
				printf("Lista vuota!");
				return 1;
			}
			else{
				printf("Inserisci il codice identificativo: ");
				scanf("%d", &identificativo);
				NODO* curr=head->next;
				int trovato=0;
				while(curr!=head){
					if(curr->info.codice==identificativo){
						trovato=1;
					}
					curr=curr->next;
				}
				if(trovato)
					printf("Computer esiste!\n\n");
				else
					printf("Computer non esiste!\n\n");
			}
		}
		
		else{
			printf("Scelta non valida!\n\n");
		}
	}
}