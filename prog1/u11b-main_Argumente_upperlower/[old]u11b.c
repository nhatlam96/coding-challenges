/* Nhat-Lam Luong inf3381; Datum: 28.5.2019 */
/* Inspiration durch Robin Freund */

#include <stdbool.h>
#include <libgen.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

bool isnumeric (char * argvec){     /* Bestimmung, ob der Char eine Zahl ist */

    bool pointex = false;           /* Bool-Marker für den Punkt */
    
    if (*argvec == '+' || *argvec == '-' || (*argvec >= '0' && *argvec <= '9')){    /* Wenn am Anfang keine nutzbaren Zeichen, dann springe zu Zeile 25 */
        for(int i = 1; *(argvec+i) != '\0'; i++){                                   /* Fortsetzung der Überprüfung ab zweites Zeichen, bis Null-Byte */
            if(*(argvec+i) == '.'){                                                 /* Da Fließkommazahlen -> Berücksichtigung von Punkten */
                if(pointex){
                    return false;                                                   /* Mehr als 1 Punkt? -> String ist keine Zahl */
                }
                pointex = true;                                                     /* Punkt gefunden, daher Bool-Marker auf true */
                continue;                                                           /* Punkt gefunden, daher nächste Iteration */
            }
            if(!(*(argvec+i) >= '0' && *(argvec+i) <= '9')){                        /* Ansonsten keine Nummern mehr? -> String ist keine Zahl */
                return false;
            }
        }
    }   else {return false;}                                                        /* Siehe Zeile 12 */
    return true;                                                                    /* Überprüfung fullständig, alle Tests bestanden */
}

int calcmalloc(int argcount, char **argvector){                 /* Funktion für die genaue Berechnung der mallocsize */
    int mallocsize = 0, mallocstep = 0;
    
    for (int n = 1; n < argcount; n++){                         /* Jedes Argument außer Basename wird geprüft */
        mallocstep = strlen(argvector[n]);                      
        mallocsize += mallocstep;                               /* Die Stringlänge aller Argumente = die Gesamtstringlänge = mallocsize */
    }
    return mallocsize+argcount-1;                               /* Nach jedem Argument kommt ein Leerzeichen (siehe Zeile 31), deswegen "+argcount-1" */
}


int main (int argc, char **argv){

    if(argc == 1){
        printf("Nur Basename: %s angegeben.\n", argv[0]);       /* Zu wenige Argumente -> Programmende */
        return EXIT_FAILURE;
    }

    char * progname = basename(argv[0]);                        /* Programmname wird durch basename erkannt */
    char * charArray = malloc(calcmalloc(argc, argv));          /* Im charArray wird die Übersetzung der Argumente gespeichert */
    
    
    int i = 0, j = 0, k = 0;                                    /* Laufvariable i für Argumente; j für Argument-String; k für charArray */

    if (!(strcmp(progname, "upper")) ||                         /* Funktion für Großbuchstaben */
        !(strcmp(progname, "generatePass")))
    {                        
        for (i = 1; i < argc; i++){                             /* Läuft jedes Argument außer Basename durch */
            for (j = 0; j < strlen(argv[i]); j++){              /* Überprüft jeden Character vom String */
                charArray[k++] = toupper(*(*(argv+i)+j));       /* Übersetzung in Großbuchstaben */
            }
            *(charArray+k) = ' ';                               /* Ein Leerzeichen um die Argumente zu trennen */
            k += 1;                                             /* Nach dem Leerzeichen geht es mit dem nächsten Argument weiter */
        }
        charArray[k-1] = '\0';                                  /* Das letzte Leerzeichen von Zeile 31 wird durch das Nullbyte finalisiert */
        k = 0;                                                  /* Laufvariable k wird resettet, für die Wiederverwendung */
        printf("%s", charArray);                                /* Ausgabe des übersetzten Strings */
    }
    if (!(strcmp(progname, "lower"))){                          
        for (i = 1; i < argc; i++){
            for (j = 0; j < strlen(argv[i]); j++){
                charArray[k++] = tolower(*(*(argv+i)+j));
            }
            *(charArray+k) = ' ';
            k += 1;
        }
        charArray[k-1] = '\0';
        k = 0;
        printf("%s", charArray);
    }
    if (!(strcmp(progname, "number"))){                        
        for(int i = 1; i != argc; i++){                          /* Überprüfung aller Argumente auf nummerische Character */
            if(isnumeric(argv[i])){                              /* Wenn Argument = Zahl, dann... */
                printf("%i ", atoi(argv[i]));                    /* Int - Ausgabe aller numerischen Argumente*/
            }
        }  
    }
    printf("\n");
    return EXIT_SUCCESS;
}
