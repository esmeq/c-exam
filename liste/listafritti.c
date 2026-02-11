#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Fritto{
	char nome[20];
	float prezzo;
	char stato;
}FRITTO;

typedef struct Nodo{
	FRITTO info;
	struct Nodo* next;
	struct Nodo* prev;
}NODO;


void OrdinaPiatto(NODO* head, NODO* nuovo){
	NODO* curr=head->next;
	while(curr!=head){
		if(nuovo->info.stato=='f' && curr->info.stato=='s')
			break;    //esco e inserisco prima
		if(nuovo->info.stato==curr->info.stato && nuovo->info.prezzo<curr->info.prezzo)
			break;
		curr=curr->next;  //va avanti
	}
	nuovo->prev=curr->prev;
	nuovo->next=curr;
	nuovo->prev->next=nuovo;
	curr->prev=nuovo;
}


int main(){
	NODO* head=malloc(sizeof(NODO));
	head->prev=head;
	head->next=head;

	NODO* nuovo;
	FRITTO fritts;
	FILE* fp=fopen("Fritti.dat", "rb");
	if(fp==NULL){
		fp=fopen("Fritti.dat", "wb");
		fclose(fp);
	}
	else{
		while(fread(&(fritts), sizeof(FRITTO),1, fp)){
			nuovo=malloc(sizeof(NODO));
			if(nuovo==NULL){
				printf("Lista vuota!");
				return 1;
			}
			nuovo->info=fritts;
			OrdinaPiatto(head, nuovo);
		}
		fclose(fp);
	}
	while(1){
		int scelta;
		printf("Inserisci piatto (1)\n");
		printf("Visualizza menu (2)\n");
		printf("Esci (0)");
		scanf("%d", &scelta);

		if(scelta==0){
			fp=fopen("Fritti.dat", "wb");
			if(fp==NULL){
				printf("Problemi di salvataggi!\n");
				return 1;
			}
			else{
				NODO* curr=head->next;
				while(curr!=head){
					fwrite(&(curr->info), sizeof(FRITTO),1, fp);
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
		}
		else if(scelta==1){
			NODO* nuovo=malloc(sizeof(NODO));
			if(nuovo==NULL){
				printf("Problemi ad inserire!");
				return 1;
			}	
				while(getchar()!='\n');
				printf("Inserisci il nome:\n");
				fgets(nuovo->info.nome, 20, stdin);
				nuovo->info.nome[strlen(nuovo->info.nome)-1]='\0';
				printf("Inserisci il prezzo:\n");
				scanf("%f", &nuovo->info.prezzo);
				printf("Inserisci il suo stato (s/f):\n");
				scanf(" %c", &nuovo->info.stato);

				OrdinaPiatto(head, nuovo);


		}
		else if(scelta==2){
			NODO* curr=head->next;
			while(curr!=head){
				printf("Nome piatto: %s\nPrezzo: %f\nStato: %c\n\n",curr->info.nome, curr->info.prezzo, curr->info.stato);
				curr=curr->next;
			}
		}
		else
			printf("Scelta non valida!\n\n");
	}
}