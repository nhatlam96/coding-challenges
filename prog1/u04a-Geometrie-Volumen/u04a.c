//Name: Jason Volz
//Datum: 2.11.2022
//Beschreibung: Porgramm dass Gegen sich selbst schere stein papier echse spok spielen soll.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

enum Symbole{schere,stein,papier,echse,spok};

void zaehlmit(int player1, int player2, int win, bool ausgabe){
    //Static Variablen, damit wir uns die Werte auch ueber Funktionsaufrufe hinweg merken koennen
    static int schere_auftreten = 0;
    static int stein_auftreten = 0;
    static int papier_auftreten = 0;
    static int echse_auftreten = 0;
    static int spok_auftreten = 0;
    static int win_p1 = 0;
    static int win_p2 = 0;
    //Wenn die Auswerten funktion die Zaehlmit aufruft, nimmt sie ausgabe = true, damit,
    //Nicht nochmal alles abgechekt wird sondern nur ausgegeben und dann mit return beendet
    if(ausgabe){
        printf("Schere: %i\n",schere_auftreten);
        printf("Stein: %i\n",stein_auftreten);
        printf("Papier: %i\n",papier_auftreten);
        printf("Echse: %i\n",echse_auftreten);
        printf("Spok: %i\n",spok_auftreten);
        printf("Wins Player1: %i\n",win_p1);
        printf("Wins Player2: %i\n",win_p2);
        return;
    //Wenn die passenden werte zutreffen wird die Statistik geandert
    }
    if(player1 == schere || player2 == schere){
        schere_auftreten++;
    }
    if(player1 == stein|| player2 == stein){
        stein_auftreten++;
    }
    if(player1 == papier|| player2 == papier){
        papier_auftreten++;
    }
    if(player1 == echse || player2 == echse){
        echse_auftreten++;
    }
    if(player1 == spok || player2 == spok){
        spok_auftreten++;
    }
    if(win == 1){
        win_p1++;
    }
    else if(win == 2){
        win_p2++;
    }
}

void auswert(){
    //Ruft nur die Zaehlmit mit True auf, damit ausgegeben wird.
    zaehlmit(0,0,0,true);
}
//bekommt die zeichen der jeweiligen spieler und checkt, wer gewonnen hat
int entscheid(int player1,int player2){
    //Bei unentschieden, wird neugestartet, deswegen return 0, da keiner gewinnt
    if(player1 == player2){
        printf("Unentschieden, wir Spielen nochmal\n");
        return 0;
    }
    if((player1 == schere && player2 == papier) || player2 == spok){
        printf("Player1 hat Gewonnen\n");
        return 1; // return 1 bei player 1 win
    }else{
        printf("Player2 hat Gewonnen\n");
        return 2; // return 2 bei player 2 win
    }
    if((player1 == stein && player2 == echse) || player2 == schere){
        printf("Player1 hat Gewonnen\n");
        return 1;
    }else{
        printf("Player2 hat Gewonnen\n");
        return 2;
    }
    if((player1 == papier && player2 == stein) || player2 == spok){
        printf("Player1 hat Gewonnen\n");
        return 1;
    }else{
        printf("Player2 hat Gewonnen\n");
        return 2;
    }
    if((player1 == echse && player2 == spok) || player2 == papier){
        printf("Player1 hat Gewonnen\n");
        return 1;
    }else{
        printf("Player2 hat Gewonnen\n");
        return 2;
    }
    if((player1 == spok && player2 == schere) || player2 == stein){
        printf("Player1 hat Gewonnen\n");
        return 1;
    }else{
        printf("Player2 hat Gewonnen");
        return 2;
    } 
}

void spiel(){
    int symbol_1 = rand() % 5; //rand() % 5 damit nur zahlen zwischen 0-4 Rauskommen.
    int symbol_2 = rand() % 5;
    int playerwin = 0;
    switch(symbol_1){
        case schere:
            printf("Spieler1 hat: Schere\n");
            break;
        case stein:
            printf("Spieler1 hat: Stein\n");
            break;
        case papier:
            printf("Spieler1 hat: Papier\n");
            break;
        case echse:
            printf("Spieler1 hat: Echse\n");
            break;
        case spok:
            printf("Spieler1 hat: Spok\n");
            break;
    }
    switch(symbol_2){
        case schere:
            printf("Spieler2 hat: Schere\n");
            break;
        case stein:
            printf("Spieler2 hat: Stein\n");
            break;
        case papier:
            printf("Spieler2 hat: Papier\n");
            break;
        case echse:
            printf("Spieler2 hat: Echse\n");
            break;
        case spok:
            printf("Spieler2 hat: Spok\n");
            break;
    }
    if((playerwin = entscheid(symbol_1,symbol_2)) == 0){ //wenn 0 returned wurde, soll spiel sich nochmal aurufen, um nochmal zu spielen.
        spiel();
    //wenn kein unentschieden, sollen die Daten in die Statistik aufgenommen werden.
    }else{
        zaehlmit(symbol_1,symbol_2,playerwin,false);
        return;
    }
}


int main(){
    //startet den rand seed. Basierend auf der Zeit(NULL) also jetzt.
    srand(time(NULL));
    //Damit 5 Runden gespielt werden
    for(int i = 1; i <= 5; i++){
        printf("Runde: %i\n",i);
        spiel();
    }
    printf("\n------------------------Auswertung-------------------------\n\n");
    auswert();
    return 0;
}