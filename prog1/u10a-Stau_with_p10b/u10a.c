/*
	u10a.c
	Name:	Linus Bleyl
	Datum:	03.12.2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NIL (struct vehicles *)0

struct vehicle
{
	char manufacturer[64];
	char model[64];
	char plate[64];
	int occupants;
};

struct vehicles
{
	struct vehicle veh;
	struct vehicles *veh_next;
};

struct vehicles *anhaengen(char *manufacturerer, char *model, char * plate, int occupants);
void anzeigen(struct vehicles *vehs);
void ausklinken(struct vehicles **vehs, struct vehicles **removed, int rm);
void einklinken(struct vehicles **vehs, struct vehicles **toinsert, int in);
int getVehFromPlate(struct vehicles *vehs, char *plate, int size);


int main()
{
	int remove;
	char insert[64];
	
	struct vehicles *veh_first = anhaengen("Audi", "RS3", "WO - RP 9", 1);
	struct vehicles *veh_act = veh_first;
	struct vehicles *removedVeh;
	
	veh_act->veh_next = anhaengen("VW", "Golf GTI", "NE - RD 255", 2);
	veh_act = veh_act->veh_next;
	
	veh_act->veh_next = anhaengen("Porsche", "Cayenne", "WIL - DE 13", 5);
	veh_act = veh_act->veh_next;
	
	veh_act->veh_next = anhaengen("Ford", "Mustang", "ES - EL 68", 3);
	veh_act = veh_act->veh_next;
	
	veh_act->veh_next = anhaengen("Setra", "S 515 HD", "B - US 55", 42);
	veh_act = veh_act->veh_next;

	anzeigen(veh_first);
	
	printf("Bitte geben sie die nummer des zu entfernen Fahrzeuges an.\n");
	printf("Eingabe: ");
	scanf("%i", &remove);
	printf("\n");
	
	ausklinken(&veh_first, &removedVeh, remove);

	anzeigen(veh_first);
	
	printf("Bitte geben sie das Kennzeichen des Fahrzeuges an hinter dem das entfernte Fahrzeug eingefügt werden soll.\n");
	printf("Eingabe: ");
	scanf(" %64[^\n]", insert); // " %64[^\n]" liest auch space mit und bricht erst bei \n sprich enter ab.
	
	printf("\n");
	
	einklinken(&veh_first, &removedVeh, getVehFromPlate(veh_first, insert, 64));

	anzeigen(veh_first);

	return 0;
}

/*
	Erstellen eines neuen Fahrzeuges und rueckgabe des pointers.
*/
struct vehicles *anhaengen(char *manufacturer, char *model, 
		char *plate, int occupants)
{
	struct vehicles *vehs = (struct vehicles *)malloc(sizeof(struct vehicles));
	strncpy(vehs->veh.manufacturer, manufacturer, 64);
	strncpy(vehs->veh.model, model, 64);
	strncpy(vehs->veh.plate, plate, 64);
	vehs->veh.occupants = occupants;
	vehs->veh_next = NIL;
	
	return vehs;
}

/*
	Ausgabe der Fahrzeuge
*/
void anzeigen(struct vehicles *vehs)
{
	struct vehicles *veh_act = vehs;
	while(veh_act != NIL)
	{
		printf("Hersteller: %10s  Modell: %10s Kennzeichen: %10s \tPersonen:%i\n", veh_act->veh.manufacturer, 
				veh_act->veh.model, veh_act->veh.plate, veh_act->veh.occupants);
		
		veh_act = veh_act->veh_next;
	}
	printf("\n");
}

/*
	"ausschneiden" eines Fahrzeuges an position "rm" und speichern des entfernten Fahrzeugs in "removed"
*/
void ausklinken(struct vehicles **vehs, struct vehicles **removed, int rm)
{
	struct vehicles *veh_act = (*vehs);
	struct vehicles *veh_next = veh_act->veh_next;
	
	rm = (rm < 1) ? 1 : rm;	// Wenn rm kleiner 1 ist wird rm = 1.
	
	if(rm == 1)
	{
		(*removed) = (*vehs);
		(*vehs) = (*vehs)->veh_next;
		return;
	}
	
	for(int i = 1; i < rm; i++)
	{
		if (veh_next->veh_next == NIL)
		{
			(*removed) = veh_act->veh_next;
			veh_act->veh_next = veh_next->veh_next;
			break;
		}
		if (i + 1 == rm)
		{
			(*removed) = veh_act->veh_next;
			veh_act->veh_next = veh_next->veh_next;
			break;
		}
		
		veh_act = veh_act->veh_next;
		veh_next = veh_next->veh_next;
	}
}

/*
	Einfuegen eines Fahrzeuges nach dem Fahrzeug auf position "in"
*/
void einklinken(struct vehicles **vehs, struct vehicles **toinsert, int in)
{
	struct vehicles *veh_act = (*vehs);
	struct vehicles *veh_next = veh_act->veh_next;
	
	if (in < 1) // Sollte in < 1 sein wird das fahrzeug an das Ende angefuegt
	{
		while(veh_act != NIL)
		{
			if (veh_act->veh_next == NIL)
			{
				veh_act->veh_next = (*toinsert);
				(*toinsert)->veh_next = NIL;
				break;
			}
			veh_act = veh_act->veh_next;
		}
		return;
	}
	
	for(int i = 0; i < in; i++)
	{
		if (veh_act->veh_next == NIL)
		{
			veh_act->veh_next = (*toinsert);
			(*toinsert)->veh_next = NIL;
			break;
		}
		if (i + 1 == in)
		{
			(*toinsert)->veh_next = veh_next;
			veh_act->veh_next = (*toinsert);
			break;
		}
		
		veh_act = veh_act->veh_next;
		veh_next = veh_next->veh_next;
	}
}

/*
	Fahrzeug position anhand des kennzeichens bekommen.
	return 0 heißt es wurd kein Fahrzeug mit diesem Kennzeichen gefunden.
*/
int getVehFromPlate(struct vehicles *vehs, char *plate, int size)
{
	struct vehicles *veh_act = vehs;
	for (int i = 0; veh_act != NIL; i++)
	{
		/*
			Vergleichen der kennzeichen wobei Gross- und Kleinschreibung ignoriert werden.
			0 = gleich daher wird die negation "!" benoetigt
		*/
		if (!strncasecmp(veh_act->veh.plate, plate, size))
		{
			return i + 1;
		}
		
		veh_act = veh_act->veh_next;
	}
	return 0;
}

