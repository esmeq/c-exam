#include <stdio.h>
#include <stdlib.h>


typedef struct Coordinate{
    float longitudine;
    float latitudine;
}COORDINATE;

typedef struct Nodo{
    COORDINATE info;
    struct Nodo* prev;
    struct Nodo* next;
}NODO;

int main(){
    NODO* head=malloc(sizeof(NODO));
    head->prev=head;
    head->next=head;
    NODO* nuovo;
    if(head==NULL){
        printf("Non ci sta spazio!");
        return 1;
    }
    COORDINATE luogo;
    FILE* fp=fopen("Coordinate.dat", "rb");
    if(fp==NULL){
        fp=fopen("Coordinate.dat", "wb");
        fclose(fp);
    }
    else {
        while(fread(&luogo, sizeof(COORDINATE), 1, fp)){
            nuovo=malloc(sizeof(NODO));
            if(nuovo==NULL){
                printf("Non ci sta spazio!");
                break;
            }
            else{
                nuovo->info=luogo;

                nuovo->prev=head->prev;
                nuovo->next=head;
                nuovo->prev->next=nuovo;
                head->prev=nuovo;
            }
        }
        fclose(fp);   
    }
    while(1){
        printf("INSERISCI IN CODA(1)\n");
        printf("ELIMINA IN TESTA(2)\n");
        printf("VISUALIZZA(3)\n");
        printf("ESCI(0)\n\n");
        int scelta;
        scanf("%d", &scelta);

        if(scelta==0){
            fp=fopen("Coordinate.dat", "wb");
            if(fp==NULL){
                printf("Errore!");
                return 1;
            }
            else {
                NODO* curr=head->next;
                while(curr!=head){
                    fwrite(&(curr->info), sizeof(COORDINATE),1,fp);
                    curr=curr->next;
                }
                fclose(fp);
                curr=head->next;
                while(curr!=head){
                    NODO* temp=curr;
                    curr=curr->next;
                    free(temp);
                }
            }
            free(head);
            return 0;
        }
        else if(scelta==1){
            NODO* nuovo=malloc(sizeof(NODO));
            if(nuovo==NULL){
                printf("Lista piena!");
                return 1;
            }

            printf("Inserisci la latitudine:\n");
            scanf("%f", &nuovo->info.latitudine);
            printf("Inserisci la longitudine:\n");
            scanf("%f", &nuovo->info.longitudine);

            nuovo->prev=head->prev;
            nuovo->next=head;
            nuovo->prev->next=nuovo;
            head->prev=nuovo;
        }
        else if(scelta==2){
            if(head->next==head){
                printf("Lista vuota!\n");
            }
            NODO* curr=head->next;
            head->next=curr->next;
            curr->next->prev=head;
            printf("Cancellato!\n\n");
        }
        else if(scelta==3){
            if(head->next==head){
                printf("Lista vuota!\n");
            }
            NODO* curr=head->next;
            int i=1;
            while(curr!=head){
                printf("Coordinata %d: %f, %f", i, curr->info.latitudine, curr->info.longitudine);
                i++;
                curr=curr->next;
                printf("\n\n");
            }

        }
    }


}