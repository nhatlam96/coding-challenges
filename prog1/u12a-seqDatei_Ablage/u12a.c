/* Musterloesung zur u12a Uebungsaufgabe */
/* Notizzettel-Textdateien */
/* Dateiname und Text via Tastatureingabe */

#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char * argv[]) {
	char prognam [5120];
	char filename [1024];
	FILE * fd;		/* Zugriffsvariable ("Handle") auf die Datei */
	char textPuffer [1024];
	int gelesen = 0;	/* Merker ob die Datei leer / neu erzeugt war */
	
	if (strrchr(argv[0], '/')) {
		strncpy (prognam, strrchr(argv[0], '/')+1, sizeof(prognam)); 
						/* + 1 wegen dem Schraegstrich selbst */
	}
	else {
		strncpy(prognam, argv[0], sizeof(prognam));
	}
	
	printf("Notizenprogramm %s: bitte geben Sie ein Stichwort als Dateinamen der Notizdatei ein: ", prognam);
	scanf("%1023s", filename);
	
	printf("Notizenprogramm %s: Dateiname: %s\n", prognam, filename);
	
	fd = fopen(filename, "a+");	/* Datei wird erzeugt falls sie nicht existiert */
	
	if (fd == NULL) {
		printf("%s: Fehler beim Oeffnen der Datei %s\n", prognam, filename);
		fprintf(stderr, "%s: file open error on file %s, errno %i, (%s)\n", prognam,
					filename, errno, strerror(errno));
		return (errno);		/* harter Programmabbruch */
	}

	/* hier geht es mit der geoffneten Datei weiter, Inhalt lesen */
	
	while (fgets(textPuffer, sizeof(textPuffer), fd)) {
		printf("Leseinhalt der Datei: |%s|\n", textPuffer);
		gelesen++;
	}
	
	/* Wenn die Datei leer war, dann zur Texteingabe auffordern */
	
	if (!gelesen) {
		printf("Notizenprogramm %s: bitte geben Sie den Text der Notiz ein (Ende: *fin*): ", prognam);
		do {
			fgets(textPuffer, sizeof(textPuffer), stdin);	/* Text von der Tastatur einlesen  */
			fputs(textPuffer, fd);				/* Text in die Datei schreiben */
		} while (strncmp(textPuffer, "*fin*", 5));
	}
	
	fclose(fd);			/* Datei wieder schliessen */

	return 0;
}