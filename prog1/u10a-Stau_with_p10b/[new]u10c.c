//Name: Jason Volz
//Datum: 14.12.2022
//Beschreibung: Programm zur Veranschulichung eines Stau programms

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1024

struct stauTeilnehmer{
    char hersteller[MAX];
    char modell[MAX];
    char kennzeichen[MAX];
    int mitfahrer;
};

struct node{
    struct stauTeilnehmer teilnehmender;
    struct node* chainLink;
};

struct node* anhaengen(){
    struct node* newTeilnehmer = malloc(sizeof(struct node)); 
    if(!newTeilnehmer){
        printf("Error with creating new Participant");
    }
    printf("Geben sie den Hersteller des Neuen Stauteilnehmers ein: ");
    scanf(" %40[^\n]",newTeilnehmer->teilnehmender.hersteller);
    printf("Geben sie das Modell des Neuen Stauteilnehmers ein: ");
    scanf(" %40[^\n]",newTeilnehmer->teilnehmender.modell);
    printf("Geben sie das Kennzeichen des Neuen Stauteilnehmers ein: ");
    scanf(" %40[^\n]",newTeilnehmer->teilnehmender.kennzeichen);
    printf("Geben sie die Mitfahrer des Neuen Stauteilnehmers ein: ");
    scanf("%i",&newTeilnehmer->teilnehmender.mitfahrer);

    newTeilnehmer->chainLink = NULL;

    return newTeilnehmer;
}

void anzeigen(struct node* teilnehmer){
    do{
        printf("Hersteller: %s\n",teilnehmer->teilnehmender.hersteller);
        printf("Modell: %s\n",teilnehmer->teilnehmender.modell);
        printf("Kennzeichen: %s\n",teilnehmer->teilnehmender.kennzeichen);
        printf("Mitfahrende: %i\n",teilnehmer->teilnehmender.mitfahrer);
        teilnehmer = teilnehmer->chainLink;
    }while(teilnehmer != NULL);
}

struct node* ausklinken(struct node* actTeilnehmer){
    struct node* ausklinked = NULL;
    char find[MAX];
    printf("Oh nein! Fahrzeug mit dem Kennzeichen: ");
    scanf("%s",find);
    printf(" Muss auf toilette... Wird Ausgeklinkt\n");
    do{    
        if(!strcmp(actTeilnehmer->chainLink->teilnehmender.kennzeichen,find)){ //Wir pruefen den naechsten partner damit wir nicht in ein 
        //in ein NULL speicher kommen, was zur seg. Fault fuehren wuerde.
            if(actTeilnehmer->chainLink->chainLink == NULL){
            //hier wird der naechste des naechsten auf ein NULL geprueft, damit wir wissen
            //ob wir einen Stauteilnehmer oder NULL an den vor dem Ausgeklinkten annhaengen.
                ausklinked = actTeilnehmer->chainLink;
                actTeilnehmer->chainLink = NULL;
                return ausklinked;
            }else{
                ausklinked = actTeilnehmer->chainLink;
                actTeilnehmer->chainLink = actTeilnehmer->chainLink->chainLink;
                return ausklinked;
            }
        }
        actTeilnehmer = actTeilnehmer->chainLink;
    }while(actTeilnehmer != NULL);
    return ausklinked;
}

void einklinken(struct node* einklinker,struct node* stauTeilnehmer){
    char find[MAX];
    printf("Ach gut, der wagen mit dem kennzeichen: %s ",einklinker->teilnehmender.kennzeichen);
    printf("Hat es von der Toilette wieder auf die Strasse Geschafft. Er reiht sich hinter dem Fahrzeug mit dem Kennzeichen: ");
    scanf("%s",find);
    printf(" Wieder ein\n");
    do{
        if(!strcmp(stauTeilnehmer->teilnehmender.kennzeichen,find)){
            if(stauTeilnehmer->chainLink == NULL){
                stauTeilnehmer->chainLink = einklinker;
                einklinker->chainLink = NULL; 
            }else{
                einklinker->chainLink = stauTeilnehmer->chainLink;
                stauTeilnehmer->chainLink = einklinker;
            }
        }
        stauTeilnehmer = stauTeilnehmer->chainLink;
    }while(stauTeilnehmer != NULL);
    
    return; 
}


int main(){

    struct node* firstTeilnehmer = NULL;
    struct node* actTeilnehmer = NULL;
    struct node* toilettTeilnehmer = NULL;
    int isFirst = 0;
    int firstLinkIsMade = 0;
    int input;

    while(1){
        printf("Willkommen zur Stausimulation!\n");
        printf("1: Anhaengen\n2: Anzeigen\n3: Ausklinken\n4: Einklinken\n0: Exit\n");
        printf("Geben sie bitte eine Zahl ein:");
        scanf("%i",&input);
        
        switch(input){
            case 1:{
                if(!isFirst){
                    firstTeilnehmer = actTeilnehmer = anhaengen(); 
                    //aktueller und first muessen beim ersten auf das selbe zeigen fuer eine ordentliche verkettung
                    isFirst = 1;
                    break;
                }else{
                    if(!firstLinkIsMade){
                        actTeilnehmer = anhaengen();
                        firstTeilnehmer->chainLink = actTeilnehmer;
                        //der erste link wird auch den nachsten teilnehmer gemacht. Damit wir immer nur den ersten 
                        //Teilnehmer mitgeben muessen und trotzdem zugriff auf die Ganze liste haben.
                        firstLinkIsMade = 1;
                        break;
                    }else{
                        actTeilnehmer = actTeilnehmer->chainLink = anhaengen();
                        break;
                    }
                }
            }
            case 2:{
                anzeigen(firstTeilnehmer);
                break;
            }
            case 3:{
                toilettTeilnehmer = ausklinken(firstTeilnehmer);
                break;
            }
            case 4:{
                einklinken(toilettTeilnehmer,firstTeilnehmer);
                break;
            }
            case 0:{
                printf("Goodbye user!\n");
                exit(0);
            }
        }
    }
    return 0;
}