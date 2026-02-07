
#include <stdio.h>
#include <stdlib.h>

typedef struct Punto{
    float x;
    float y;
}Punto;

typedef struct Triangolo{
    int lato;
    Punto coord;
}Triangolo;

typedef struct Nodo{
    Triangolo T;
    struct Nodo* next;
}NODO;

void inserisciOrdinato(NODO** head, NODO* nuovo){         //doppio puntatore alla testa
    if(*head==NULL || nuovo->T.lato<(*head)->T.lato){
        nuovo->next=*head;
        *head=nuovo;
        return;
    }
    else{
        NODO* curr=*head;
        while(curr->next!=NULL && curr->next->T.lato<nuovo->T.lato){
            curr=curr->next;
        }
        nuovo->next=curr->next;
        curr->next=nuovo;
    }
}






int main(){
    NODO* head= NULL; //creo lista
    NODO* nuovo;  //per inserire nuovi triangoli
    FILE* fp=fopen("triangolo.txt","r");    //apre soltanto
    float x,y;
    int lato;
    if(fp==NULL){
        fp=fopen("triangolo.txt","w");     //creo
        fclose(fp);                         //chiudo e salvo
    }
    else {
        while(fscanf(fp,"%f %f %d", &x, &y, &lato)==3){          //finché legge 3 valori deve assegnarli
            nuovo= malloc(sizeof(NODO));        //creo NODO
            nuovo->T.coord.x=x;
            nuovo->T.coord.y=y;
            nuovo->T.lato=lato;
            inserisciOrdinato(&head, nuovo);
        }
        fclose(fp);       //salvo i dati 
   
    }
    while(1){
        int scelta;
        printf("Inserisci un triangolo(1)\n");
        printf("Cancella un triangolo(2)\n");
        printf("Visualizza la lista(3)\n");
        printf("Esci(0)\n\n");
        scanf("%d", &scelta);
        
        if(scelta==0){
            fp=fopen("triangolo.txt", "w");
            NODO* curr=head;
            while(curr!=NULL){
                fprintf(fp, "%f %f %d\n",curr->T.coord.x, curr->T.coord.y, curr->T.lato);    //scrive i dati sul FILE
                curr=curr->next;
            }
            while(head!=NULL){
                NODO* temp=head;
                head=head->next;
                free(temp);
            }
            return 0;
        }
        else if(scelta==1){
            nuovo= malloc(sizeof(NODO));       //creo spazio
            if(nuovo==NULL){         //controllo se é piena
                printf("Problemi con l'inserimento!\n");
                break;
            }
            else {
                printf("Dammi un lato: \n");
                scanf("%d", &nuovo->T.lato);
                printf("Dammi x e y:\n");
                scanf("%f%f",&nuovo->T.coord.x,&nuovo->T.coord.y);
                inserisciOrdinato(&head,nuovo);
            }
        }
        else if(scelta==2){
                float perimetro;
                printf("Damme sto perimetro:\n");
                scanf("%f", &perimetro);
                NODO* curr=head;
                NODO* prev=NULL;
                while(curr!=NULL){
                    if(perimetro==curr->T.lato*3){
                        if(prev==NULL){       //se é il primo nodo
                            head=curr->next;
                        }
                        else{
                            prev->next=curr->next;
                        }
                        NODO* temp=curr;
                        curr=curr->next;
                        free(temp);
                    }
                    else{
                        prev=curr;           //scorro prev
                        curr=curr->next;    //scorro
                    }
                }
        }
        else if(scelta==3){
                if(head==NULL)
                    printf("La lista é vuota!\n\n");
                else{
                    NODO* curr=head;
                    int i=1;
                    while(curr!=NULL){
                        printf("Il triangolo %d:\n", i);
                        printf("coordinate: (%f,%f)\n", curr->T.coord.x,curr->T.coord.y);
                        printf("Perimetro: %d\n\n", curr->T.lato*3);
                        i++;
                        curr=curr->next;
                    }
                }
                        
            }
        else
            printf("Non é un opzione valida!\n");
    }       
}



