//name: Jason Volz
//Datum 04.01.23
//Beschreibung: Programm zum einlesen von char's, die in int/floats umgewandelt werden. Unter der beachtung von MAXINT

#define MAXINT 2147483647

#include <stdio.h>
#include <limits.h>

double makeDouble(char input){
    static double double_number = 0.0;
    static int counter = 1;
    double buffer = 0.0;
    buffer = ((double) input - '0') / (10 * counter); 
    counter *= 10;      //Wir rechnen in 10er schritten, damit wir immer um eine 10er stelle kleiner werden
    return double_number += buffer;
}

int makeInt(char input){
    static int number = 0;
    static int counter = 0;
    int buffer = 0;
    buffer = input - '0';
    if(counter == 0){
        counter++;
        number = buffer;
        return buffer;
    }
    if(counter < 9 ){
        number = number * 10 + buffer;
        counter++;
        return number;
    }
    if(number > 214748364){
        return number;
    }
    if(number == 214748364){
        if(buffer <= 7){
            number = number * 10 + buffer;
            counter++;
            return number;
        }
    }
    return number;  
}

int main(){
    char eingabe;
    int zahl = 0;
    int doubleCheck = 0;
    double double_zahl = 0.0;
    printf("Geben sie bitte eine Zahl ein\n");
    do{
        eingabe = getchar();
        if(eingabe == EOF){
            break;
        }
        if(eingabe == '.'){
            doubleCheck = 1;
            continue;
        }
        if(doubleCheck){
            double_zahl = makeDouble(eingabe);
            double_zahl += zahl;
        }else{
            zahl = makeInt(eingabe);
        }
    }while(eingabe != EOF);
    if(doubleCheck){
        printf("\nDouble: %lf\n",double_zahl);
        printf("WissenschaftDouble: %e\n",double_zahl);

    }else{
        printf("\n%i\n",zahl);
    }
    return 0;
}