#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct Pizza{
    char nome[30];
    float prezzo;
    char stato;
}PIZZA;

typedef struct Nodo{
    PIZZA info;
    struct Nodo*prev;
    struct Nodo*next;
}NODO;


int main(){
    NODO* head=malloc(sizeof(NODO));
    head->prev=head;
    head->next=head;
    NODO* nuovo;
    PIZZA pizzas;
    
    FILE* fp=fopen("Pizza.dat", "rb");
    if(fp==NULL){
        fp=fopen("Pizza.dat", "wb");
        fclose(fp);
    }
    else {
        while(fread(&pizzas, sizeof(PIZZA),1,fp)){
            nuovo=malloc(sizeof(NODO));
            if(nuovo==NULL){
                printf("Errore!\n\n");
                return 1;
            }
            
            nuovo->info=pizzas;
            
            nuovo->next=head->next;
            nuovo->prev=head;
            nuovo->next->prev=nuovo;
            head->next=nuovo;
        }
        fclose(fp);
    }
    while(1){
        int scelta;
        printf("INSERISCI IN TESTA (1)\n");
        printf("VISUALIZZA LISTA (2)\n");
        printf("CANCELLA (3)\n");
        printf("ESCI (0)\n");
        
        scanf("%d", &scelta);
        if(scelta==0){
            fp=fopen("Pizza.dat", "wb");
            NODO* curr=head->next;
            while(curr!=head){
                fwrite(&(curr->info), sizeof(PIZZA), 1, fp);
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
            NODO* nuovo=malloc(sizeof(NODO));
            if(nuovo==NULL){
                printf("Errore di inserimento!\n\n");
                return 1;
            }
            else{
                while(getchar()!='\n');
                printf("Inserisci il tipo di pizza: \n");
                fgets(nuovo->info.nome,30,stdin);
                nuovo->info.nome[strlen(nuovo->info.nome)-1]='\0';
                printf("Inserisci il prezzo della pizza: \n");
                scanf("%f", &nuovo->info.prezzo);
                printf("La pizza é vegetariana? (y/n) \n");
                scanf(" %c", &nuovo->info.stato);
                
                nuovo->next=head->next;
                nuovo->prev=head;
                nuovo->next->prev=nuovo;
                head->next=nuovo;
            }
        }
        else if(scelta==2){
            if(head->next==head && head->prev==head){
                printf("Lista vuota!\n\n");
                return 1;
            }
            NODO* curr=head->next;
            while(curr!=head){
                printf("Pizza: %s\n", curr->info.nome);
                printf("Prezzo: %f\n", curr->info.prezzo);
                printf("Vegetariana: %c\n", curr->info.stato);
                curr=curr->next;
            }
        }
        else if(scelta==3){
            if(head->next==head && head->prev==head){
                printf("Lista vuota!\n\n");
                return 1;
            }
            else{
                NODO* curr=head->next;
                int cancellato=0;
                while(curr!=head && !(cancellato)){
                    if(curr->info.stato=='y'){
                        curr->prev->next=curr->next;
                        curr->next->prev=curr->prev;
                        cancellato=1;
                        free(curr);
                        printf("Cancellazione effettuata!\n\n");
                    }
                    if(!cancellato){
                        curr=curr->next;
                    }
                }
                if(!cancellato){
                    printf("Non sono presenti pizze vegetariane!\n\n");
                }
            }
        }
        else
            printf("Scelta non valida!\n\n");
    }
}