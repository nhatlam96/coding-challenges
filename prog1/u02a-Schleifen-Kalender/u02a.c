/*
 * Ein Kalendar
 * 15.10.18 - Robin Eschbach
 *
 */

 /*
  * Vorgehensplanung:
  *
  * Erstmal alle Monate + ihre Tage ausgeben
  * Hinzufuegen das Wochentages
  * Startpunkt des Monats bestimmen
  * Einruecken am Anfang des Monats + Zeilenumbruch anpassen
  */

 #include <stdio.h>

 int main() {

   /* Deklarierung der Monatsvariable */
   int month;

   /* Deklarierung der Tagesvariable und dessen Initialisierung */
   /* Sie wird verwendet um den Tag der Woche herauszufinden */
   int dayOfWeek = 0;

   /* Zaehlschleife um die Monate zu durchlaufen */
   for(month = 1; month <= 12; month++) {

     /* Hilfsvariable fuer die Anzahl an Tagen in dem Monat */
     int days;

     /* Switch case fuer eben diese Hilfsvariable */
     /* Hier wird die Anzahl an Tagen zugewiesen */
     switch(month) {
       case 1: days = 31; break;  /* Januar */
       case 2: days = 28; break;  /* Februar */
       case 3: days = 31; break;  /* Maerz */
       case 4: days = 30; break;  /* April */
       case 5: days = 31; break;  /* Mai */
       case 6: days = 30; break;  /* Juni */
       case 7: days = 31; break;  /* Juli */
       case 8: days = 31; break;  /* August */
       case 9: days = 30; break;  /* September */
       case 10: days = 31; break; /* Oktober */
       case 11: days = 30; break; /* November */
       case 12: days = 31; break; /* Dezember */
     }

     /* Ausgabe der Monatsnummer */
     printf("Monat: %i\n", month);

     /* Ausgabe der Tage der Woche */
     printf("\tMon\tTue\tWen\tThu\tFri\tSat\tSun\n");

     /* Einruecken falls der Monat nicht bei Montag anfaengt */
     for(int i = 0; i < dayOfWeek; i++) {
       printf("\t");
     }

     /* Durchlaufen aller Tage des Monats */
     for(int i = 1; i <= days; i++) {
       /* Ausgabe des Tages + ein vorangefuegter Tabulator */
       printf("\t%i", i);

       /* Ueberpruefen, ob eine neue Zeile erreicht ist */
       /* Dabei wird dayOfWeek (Der Startpunkt des Monats) */
       /* zu i hinzugefuegt */
       if((i + dayOfWeek) % 7 == 0) {
         /* Ausgabe des Linebreaks */
         printf("\n");
       }
     }

     /* Aenderung des Startpunktes des Monats */
     dayOfWeek += days % 7;
     dayOfWeek %= 7;

     /* Ausgabe von 2 Linebreaks (Monatsende) */
     printf("\n\n");
   }

   return 0;
 }
