#include <stdio.h>
#include <stdlib.h>


typedef struct {
    float x;
    float y;
}COORDINATE;


typedef struct {
    COORDINATE punto;
    int lunghezza;
}SEGMENTO;

typedef struct Nodo{
    SEGMENTO info;
    struct Nodo* prev;
    struct Nodo* next;
}NODO;

void salvaSuFile(NODO* head){
    FILE* fp=fopen("Coordinate.dat", "wb");
    NODO* curr=head->next;
    while(curr!=head){
        fwrite(&(curr->info), sizeof(SEGMENTO),1,fp);
        curr=curr->next;
    }
    fclose(fp);
    curr=head->next;
    while(curr!=head){
        NODO* temp= curr;
        curr=curr->next;
        free(temp);
    }
    free(head);
}
void inserisci(NODO* head){
    NODO* nuovo=malloc(sizeof(NODO));
    if(nuovo==NULL){
        printf("Errore!\n\n");
        return;
    }
    else{
        printf("Inserisci coordinate dell'estremo sinistro: \n");
            scanf("%f%f", &nuovo->info.punto.x, &nuovo->info.punto.y);
        
        printf("Inserisci lunghezza segmento: \n");
        scanf("%d", &nuovo->info.lunghezza);
        
        nuovo->prev=head->prev;
        nuovo->next=head;
        nuovo->prev->next=nuovo;
        head->prev=nuovo;
        printf("Inserimento effettuato!\n\n");
    }
}

void visualizza(NODO* head){
    if(head->next==head &&head->prev==head){
        printf("Lista vuota!\n\n");
        return;
    }
    else{
        NODO* curr=head->next;
        int i=1;
        while(curr!=head){
            printf("Segmento %d: \n",i);
            printf("Coordinate estremo sinistro: (%f,%f)\n", curr->info.punto.x, curr->info.punto.y);
            printf("Coordinate estremo destro : (%f,%f)\n", (curr->info.punto.x + curr->info.lunghezza), curr->info.punto.y);
            printf("Lunghezza segmento: %d\n\n", curr->info.lunghezza);
            curr=curr->next;
            i++;
        }
    }
    return;
}



void elimina(NODO* head){
    if(head->next==head && head->prev==head){
        printf("Lista vuota!\n\n");
        return;
    }
    NODO* curr=head->next;
    while(curr!=head){
        if(curr->info.lunghezza==12){
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            free(curr);
            printf("Cancellazione effettuata!\n\n");
            return;
            
        }
        curr=curr->next;
    }
    printf("Non ci sono segmenti lunghi 12!\n\n");
    return;
}



int main(){
    NODO* head= malloc(sizeof(NODO));
    head->prev=head;
    head->next=head;
    NODO* nuovo;
    SEGMENTO linea;
    FILE* fp=fopen("Coordinate.dat", "rb");
    if(fp==NULL){
        fp=fopen("Coordinate.dat", "wb");
        fclose(fp);
    }
    else{
        while(fread(&linea, sizeof(SEGMENTO),1,fp)){
            nuovo=malloc(sizeof(NODO));
            if(nuovo==NULL){
                printf("Errore\n");
                return 1;
            }
            nuovo->info=linea;
            
            nuovo->prev=head->prev;
            nuovo->next=head;
            nuovo->prev->next=nuovo;
            head->prev=nuovo;
        }
        fclose(fp);
    }
    while(1){
        int scelta;
        printf("INSERISCI IN CODA UN SEGMENTO (1)\n");
        printf("VISUALIZZA LISTA (2)\n");
        printf("ELIMINA (3)\n");
        printf("ESCI (0)\n\n");
        
        scanf("%d", &scelta);
        
        if(scelta==0){
            salvaSuFile(head);
            return 0;
        }
        else if(scelta==1){
            inserisci(head);    
        }
        else if(scelta==2){
            visualizza(head);    
        }
        else if(scelta==3){
            elimina(head);    
        }
        else
            printf("Scelta non valida!\n\n");
    }
}