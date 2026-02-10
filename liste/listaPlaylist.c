#include <stdio.h> 
#include <stdlib.h>
#include <string.h>



typedef struct Brano{
    char autore[30];
    char titolo[30];
    int durata;
}BRANO;


typedef struct Nodo{
    BRANO info;
    struct Nodo* next;
    struct Nodo* prev;
}NODO; 


int main(){
    NODO* head=malloc(sizeof(NODO));    //lista vuota con sentinella
    head->prev=head;
    head->next=head;
    NODO* nuovo;        //per inserire nuove canzoni
    
    BRANO canzone;    
    FILE* fp= fopen("Playlist.dat", "rb");
    if(fp==NULL){
        fp= fopen("Playlist.dat", "wb");
        fclose(fp);
    }
    
    else{
        
        while(fread(&canzone, sizeof(BRANO), 1, fp)){
            nuovo=malloc(sizeof(NODO));
            if(nuovo==NULL){
                printf("Non ci sta spazio!!");
                break;
            }
            nuovo->info=canzone;
            
            nuovo->prev=head->prev;
            nuovo->next=head;

            head->prev->next=nuovo;
            head->prev=nuovo;
        }
        
        fclose(fp);
    }
    while(1){
        int scelta;
        printf("INSERISCI IN CODA UN BRANO (1)\n");
        printf("VISUALIZZA PLAYLIST (2)\n");
        printf("CANCELLA UN BRANO (3)\n");
        printf("ESCI(0)\n\n");
        
        scanf("%d", &scelta);
        if(scelta==1){
            nuovo=malloc(sizeof(NODO));
            if(nuovo==NULL)
                printf("NON CI STA ABBASTANZA SPAZIO!\n\n");
            else{
                while(getchar()!='\n');
                printf("Dimmi l'autore del brano:\n");
                fgets(nuovo->info.autore, 30,stdin);
                nuovo->info.autore[strlen(nuovo->info.autore)-1]='\0';
                printf("Dimmi il nome della canzone:\n");
                fgets(nuovo->info.titolo, 30, stdin);
                nuovo->info.titolo[strlen(nuovo->info.titolo)-1]='\0';
                printf("Dimmi la durata in secondi:\n");
                scanf("%d", &nuovo->info.durata);

                nuovo->prev=head->prev;
                nuovo->next=head;
                nuovo->prev->next=nuovo;
                head->prev=nuovo;
            }
        }
        else if(scelta==2){
            NODO* curr=head->next;     //head é un nodo fittizio
            if(head->prev==head && head->next==head){
                printf("La lista é vuota!\n\n");
            }
            else {
                while(curr!=head){
                    printf("Il nome dell'autore:%s\n", curr->info.autore);
                    printf("Il nome del brano:%s\n", curr->info.titolo);
                    printf("La durata:%d\n", curr->info.durata);
                    curr=curr->next;
                }
            }
        }
        else if(scelta==3){
            if(head->prev==head && head->next==head){
                printf("La lista é vuota!\n\n");
                continue;
            }
            char eliminautore[30];
            char eliminatitolo[30];
            while(getchar()!='\n');
            printf("Il nome dell'autore da cancellare:\n");
            fgets(eliminautore, 30, stdin);
            eliminautore[strlen(eliminautore)-1]='\0';
            printf("Il titolo del brano da cancellare:\n");
            fgets(eliminatitolo, 30, stdin);
            eliminatitolo[strlen(eliminatitolo)-1]='\0';
            
            NODO* curr=head->next;
            int trovato=0;
            
            while(curr!=head){
                if(strcmp(curr->info.autore, eliminautore)==0 && strcmp(curr->info.titolo, eliminatitolo)==0 ){
                    trovato=1;
                    
                    curr->prev->next=curr->next;         //eliminazione
                    curr->next->prev=curr->prev;
                    
                    NODO* canc= curr;
                    curr=curr->next;
                    free(canc);
                    
                    printf("Brano cancellato!\n\n");
                    break;
                }
                else{
                    curr=curr->next;
                }
            }
            if(!trovato){
                printf("Brano non trovato!\n\n");
            }
        }    
        else if(scelta==0){
            fp=fopen("Playlist.dat", "wb");
            if(fp==NULL){
                printf("Problemi a salvare il file!\n\n");
                return -1;
            }    
            NODO* curr=head->next;
            while(curr!=head){
                fwrite(&(curr->info), sizeof(BRANO), 1, fp);        //1 é quanti ne scrivo alla volta
                curr=curr->next;
            }
            fclose(fp);
            
            curr=head->next;
            while(curr!=head){   //deallocare tutta la lista
                NODO* temp=curr;
                curr=curr->next;
                free(temp);
            }
            free(head);
            return 0;
        }
        else {
            printf("COMANDO NON VALIDO!\n\n");
        }
        
    }
}