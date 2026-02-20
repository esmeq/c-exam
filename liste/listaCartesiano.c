#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct Punto{
    char colore[20];
    float x;
    float y;
}PUNTO;



typedef struct Nodo{
    PUNTO info;
    struct Nodo* next;
    struct Nodo* prev;
}NODO;


void distanzaEuclidea(NODO* head){
    if(head->next==head || head->prev==head ){
        printf("Lista vuota!\n\n");
        return;
    }
    
    NODO* curr=head->next;
    float mindistanza=-1;
    
    NODO* p1=NULL;
    NODO* p2=NULL;
    NODO* j;
    
    if(curr->next!=head){
        mindistanza=sqrt(pow(curr->next->info.x - curr->info.x, 2) + pow(curr->next->info.y - curr->info.y, 2));
    }
    for(curr=head->next; curr!=head; curr=curr->next){
        for(j=curr->next; j!=head; j=j->next){
            float d=sqrt(pow(curr->info.x - j->info.x, 2) + pow(curr->info.y - j->info.y, 2));
            if(mindistanza<0 || d<mindistanza){
                mindistanza=d;
                p1=curr;
                p2=j;
            }
        }
        
    }
    printf("La distanza euclidea minima vale: %f\n", mindistanza);
    printf("Generata dai punti (%f,%f) e (%f,%f)\n\n",p1->info.x,p1->info.y,p2->info.x,p2->info.y);

}


int main(){
    NODO* head=malloc(sizeof(NODO));
    head->prev=head;
    head->next=head;
    NODO* nuovo;
    PUNTO p;
    
    FILE* fp=fopen("Cartesiano.dat", "rb");
    if(fp==NULL){
        fp=fopen("Cartesiano.dat","wb");
        fclose(fp);
    }
    else{
        while(fread(&p, sizeof(PUNTO),1,fp)){
            nuovo=malloc(sizeof(NODO));
            if(nuovo==NULL){
                printf("Lista vuota!");
            }
            nuovo->info=p;
            
            nuovo->prev=head;
            nuovo->next=head->next;
            nuovo->next->prev=nuovo;
            head->next=nuovo;
        }
        fclose(fp);
    }
    while(1){
        int scelta;
        printf("INSERISCI PUNTO (1)\n");
        printf("VISUALIZZA LISTA PUNTI (2)\n");
        printf("VISUALIZZA PUNTI PER COLORE (3)\n");
        printf("CANCELLA PUNTO (4)\n");
        printf("CALCOLA E STAMPA I PUNTI CON LA MINIMA DISTANZA (5)\n");
        printf("ESCI (0)\n");
        scanf("%d", &scelta);
        
        if(scelta==0){
            fp=fopen("Cartesiano.dat", "wb");
            if(fp==NULL)
                printf("Errore ne salvataggio!\n\n");
            else {
                NODO* curr= head->next;
                while(curr!=head){
                    fwrite(&(curr->info), sizeof(PUNTO),1,fp);
                    curr=curr->next;
                }
                curr=head->next;
                while(curr!=head){
                    NODO*temp=curr;
                    curr=curr->next;
                    free(temp);
                }
                free(head);
                return 0;
            }
        }
        else if(scelta==1){
            NODO* nuovo=malloc(sizeof(NODO));
            if(nuovo==NULL)
                printf("Impossibile inserire!\n");
            else {
                while(getchar()!='\n');
                printf("Inserisci colore del punto: \n");
                fgets(nuovo->info.colore,20,stdin);
                nuovo->info.colore[strlen(nuovo->info.colore)-1]='\0';
                
                printf("Inserisci la coordinata x: \n");
                scanf("%f", &nuovo->info.x);
                
                printf("Inserisci la coordinata y: \n");
                scanf("%f", &nuovo->info.y);
                
                
                nuovo->prev=head;
                nuovo->next=head->next;
                nuovo->next->prev=nuovo;
                head->next=nuovo;
            }
        }
        else if(scelta==2){
            NODO* curr=head->next;
            while(curr!=head){
                printf("Coordinate: (%f,%f)\n", curr->info.x, curr->info.y);
                printf("Colore: %s\n", curr->info.colore);
                curr=curr->next;
            }
        }
        else if(scelta==3){
            char color[20];
            while(getchar()!='\n');
            printf("Che colore vuoi vedere? \n");
            fgets(color,20,stdin);
            color[strlen(color)-1]='\0';
            
            NODO* curr=head->next;
            while(curr!=head){
                if(strcmp(curr->info.colore, color)==0){
                    printf("Punto %s: \n", curr->info.colore);
                    printf("Coordinate: (%f,%f)\n", curr->info.x, curr->info.y);
                }
                curr=curr->next;
            }
        }
        else if(scelta==4){
            if(head->next==head){
                printf("Lista vuota!\n\n");
                break;
            }
            NODO* curr=head->next;
            float minimo=curr->info.y;
            while(curr!=head){
                if(curr->info.y<minimo){
                    minimo=curr->info.y;
                }
                curr=curr->next;
            }
            curr=head->next;
            while(curr!=head){
                if(curr->info.y==minimo){
                    curr->next->prev=curr->prev;
                    curr->prev->next=curr->next;
                    
                    NODO* temp=curr;
                    curr=curr->next;
                    free(temp);
                }
                else
                    curr=curr->next;
            }
        }
        else if(scelta==5){
            distanzaEuclidea(head);    
        }
        else{
            printf("Scelta non valida!\n\n");
        }
        
        
    }
}