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
    
    char autor[30];
    char titol[30];
    int durat;
    FILE* fp= fopen("Playlist.txt", "r");
    if(fp==NULL){
        fp= fopen("Playlist.txt", "w");
        fclose(fp);
    }
    
    else{
        while(fscanf(fp, " %s %s %d", autor, titol, &durat)==3){
            nuovo=malloc(sizeof(NODO));
            if(nuovo==NULL){
                printf("Non ci sta spazio in memoria!\n");
                break;
            }
  
            strcpy(nuovo->info.autore, autor);
            strcpy(nuovo->info.titolo, titol);
            nuovo->info.durata= durat;
            
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
                fgets(autor, 30,stdin);
                autor[strlen(autor)-1]='\0';
                printf("Dimmi il nome della canzone:\n");
                fgets(titol, 30, stdin);
                titol[strlen(titol)-1]='\0';
                printf("Dimmi la durata in secondi:\n");
                scanf("%d", &durat);
                
                strcpy(nuovo->info.autore, autor);
                strcpy(nuovo->info.titolo, titol);
                nuovo->info.durata= durat;
 
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
            char autore[30];
            char titolo[30];
            while(getchar()!='\n');
            printf("Il nome dell'autore da cancellare:\n");
            fgets(autore, 30, stdin);
            autore[strlen(autore)-1]='\0';
            printf("Il titolo del brano da cancellare:\n");
            fgets(titolo, 30, stdin);
            titolo[strlen(titolo)-1]='\0';
            
            NODO* curr=head->next;
            int trovato=0;
            
            while(curr!=head){
                if(strcmp(curr->info.autore, autore)==0 && strcmp(curr->info.titolo, titolo)==0 ){
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
            fp=fopen("Playlist.txt", "w");
            if(fp==NULL){
                printf("Problemi a salvare il file!\n\n");
                return -1;
            }    
            NODO* curr=head->next;
            while(curr!=head){
                fprintf(fp, "%s %s %d\n", curr->info.autore,curr->info.titolo, curr->info.durata);
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