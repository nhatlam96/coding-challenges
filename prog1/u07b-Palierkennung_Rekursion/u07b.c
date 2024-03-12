#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

bool isPali(char eingabe[],int laenge){
    static int start = 0;
    if(eingabe[start] == eingabe[laenge]){
        start++;
        //--laenge, damit vor dem erneuten funktionsaufruf reduziert wird.
        return isPali(eingabe,--laenge);
    }
    if(start >= laenge){
        return true;
    }
    return false;
}

int main(){
    char eingabe[MAX];
    printf("Geben sie ein Wort zur Palindrompruefung ein: ");
    scanf("%s",eingabe);
    //Wir ziehen eins von strlen ab, damit wir den Value fuer unser ArrayIndex verwenden koennen.
    //Da strlen ja den gezaehlten buchstaben wert returned und wir aber einen 0 Indexierten wert benoetigen.
    if(isPali(eingabe,(strlen(eingabe) - 1))){
        printf("Ist Pali\n");
    }else{
        printf("Ist nix Pali\n");
    }
    return 0;
}