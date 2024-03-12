//Name: Jason Volz
//Datum: 21.12.2022
//Beschreibung: Programm zur Dechiffrierung

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1024
#define MAXx2 2048

void replaceChar(char zeichenkette[]){
    for(int i = 0;i < (strlen(zeichenkette));i++){
        switch(zeichenkette[i]){
            case '!':{
                zeichenkette[i] = 'i';
                break;
            }
            case  '0':{
                zeichenkette[i] = 'o';
                break;
            }
            case '2':{
                zeichenkette[i] = 'z';
                break;
            }
            case '3':{
                zeichenkette[i] = 'e';
                break;
            }
            case '7':{
                zeichenkette[i] = 'r';
                break;
            }
            case '9':{
                zeichenkette[i] = 'g';
                break;
            }
        }
    }
}

void textZusammenFuegen(char zeichenkette1[],char zeichenkette2[],char newZeichenkette[]){
    int i1 = 0;
    int i2 = 0;
    int j = 0;
    //Wir wollen bei einem Gefundenen Nullbyte aufhoeren, fuer den fall, dass nicht beide strings Gleichlang sind.
    while((zeichenkette1[i1] != '\0') && (zeichenkette2[i2] != '\0')){
        newZeichenkette[j] = zeichenkette1[i1];
        j++;
        i1++;
        newZeichenkette[j] = zeichenkette2[i2];
        i2++;
        j++;
    }
    if(zeichenkette1[i1] == '\0'){
        while(zeichenkette2[i2] != '\0'){
            newZeichenkette[j] = zeichenkette2[i2];
            i2++;
            j++;
        }
    }
    else if(zeichenkette2[i2] == '\0'){
        while(zeichenkette1[i1] != '\0'){
            newZeichenkette[j] = zeichenkette1[i1];
            i1++;
            j++;
        }
    }
    newZeichenkette[j] = '\0';
    return;
}

int main(int argc, char *argv[]){
    if(!(argc == 3)){
        printf("Bitte geben sie die Richtige menge an Argumenten ein.\n");
        return 1;
    }
    char *newZeichenkette = malloc(strlen(argv[1])+strlen(argv[2]));
    replaceChar(argv[1]);
    replaceChar(argv[2]);
    textZusammenFuegen(argv[1],argv[2],newZeichenkette);
    printf("%s\n",newZeichenkette);
    return 0;
}