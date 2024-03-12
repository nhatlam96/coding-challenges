/*
	p10a.c
	Name:	Linus Bleyl
	Datum: 	10.12.2018
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
	struct vehicle veh_right;	// Fahrzeuge auf der rechten spur
	struct vehicle veh_left;	// Fahrzeuge auf der linken spur
	struct vehicles *veh_next_right;
	struct vehicles *veh_next_left;
};

struct vehicles *anhaengen(char *manufacturerer, char *model, char * plate, int occupants, int pos);
struct vehicles *anheangenValues(struct vehicles *vehs , char *manufacturer, char *model, char *plate, int occupants, int pos);
void anzeigen(struct vehicles *vehs);
void ausklinken(struct vehicles **vehs, struct vehicles **removed, int rm, int pos);
void einklinken(struct vehicles **vehs, struct vehicles **toinsert, int in, int pos, int change);
int getVehFromPlate(struct vehicles *vehs, char *plate, int size, int pos);


int main()
{
	int remove, remove_pos, insert_pos;
	char insert[64];
	
	struct vehicles *veh_first = anhaengen("Audi", "RS3", "WO - RP 9", 1, 1);
	struct vehicles *veh_act = veh_first;
	struct vehicles *removedVeh;
	
	veh_act->veh_next_right = anhaengen("VW", "Golf GTI", "NE - RD 255", 2, 1);
	veh_act = veh_act->veh_next_right;
	
	veh_act->veh_next_right = anhaengen("Porsche", "Cayenne", "WIL - DE 13", 5, 1);
	veh_act = veh_act->veh_next_right;
	
	veh_act->veh_next_right = anhaengen("Ford", "Mustang", "ES - EL 68", 3, 1);
	veh_act = veh_act->veh_next_right;
	
	veh_act->veh_next_right = anhaengen("Setra", "S 515 HD", "B - US 55", 42, 1);
	veh_act = veh_act->veh_next_right;


	veh_act = veh_first;
	
	anheangenValues(veh_first, "Opel", "Admiral", "A - LT 1964", 2, 2);
	
	veh_act->veh_next_left = anhaengen("Mercedes", "A-Klasse", "EL - CH 97", 3, 2);
	veh_act = veh_act->veh_next_left;
	
	veh_act->veh_next_left = anhaengen("Porsche", "911Carrera", "BRA - US 1", 1, 2);
	veh_act = veh_act->veh_next_left;
	
	veh_act->veh_next_left = anhaengen("VW", "Golf-TDI", "NO - X 850", 4, 2);
	veh_act = veh_act->veh_next_left;



	anzeigen(veh_first);
	
	printf("Bitte geben sie an ob sie ein Fahrzeug auf der rechten = 1 oder linken = 2 entfernen moechten.\n");
	printf("Eingabe: ");
	scanf("%i", &remove_pos);
	printf("Bitte geben sie die nummer des zu entfernen Fahrzeuges an.\n");
	printf("Eingabe: ");
	scanf("%i", &remove);
	printf("\n");
	
	ausklinken(&veh_first, &removedVeh, remove, remove_pos);
	
	anzeigen(veh_first);
	
	
	printf("Bitte geben sie an ob sie ein Fahrzeug auf der rechten = 1 oder linken = 2 einfuegen moechten.\n");
	printf("Eingabe: ");
	scanf("%i", &insert_pos);
	printf("Bitte geben sie das Kennzeichen des Fahrzeuges an hinter dem das entfernte Fahrzeug eingefuegt werden soll.\n");
	printf("Eingabe: ");
	scanf(" %64[^\n]", insert); // " %64[^\n]" liest auch space mit und bricht erst bei \n sprich enter ab.
	
	printf("\n");
	
	einklinken(&veh_first, &removedVeh, getVehFromPlate(veh_first, insert, 64, insert_pos), insert_pos, insert_pos != remove_pos);

	anzeigen(veh_first);

	return 0;
}

/*
	Erstellen eines neuen Fahrzeuges und rueckgabe des pointers.
*/
struct vehicles *anhaengen(char *manufacturer, char *model, 
		char *plate, int occupants, int pos)
{
	struct vehicles *vehs = (struct vehicles *)malloc(sizeof(struct vehicles));

	return anheangenValues(vehs , manufacturer, model, plate, occupants, pos);
}

/*
	Erstellen eines neuen Fahrzeuges und rueckgabe des pointers.
	Ohne malloc()
*/
struct vehicles *anheangenValues(struct vehicles *vehs , char *manufacturer, char *model, 
		char *plate, int occupants, int pos)
{
	if (pos == 1)
	{
		strncpy(vehs->veh_right.manufacturer, manufacturer, 64);
		strncpy(vehs->veh_right.model, model, 64);
		strncpy(vehs->veh_right.plate, plate, 64);
		vehs->veh_right.occupants = occupants;
		vehs->veh_next_right = NIL;
	}
	else
	{
		strncpy(vehs->veh_left.manufacturer, manufacturer, 64);
		strncpy(vehs->veh_left.model, model, 64);
		strncpy(vehs->veh_left.plate, plate, 64);
		vehs->veh_left.occupants = occupants;
		vehs->veh_next_left = NIL;
	}
	
	return vehs;
}

/*
	Ausgabe der Fahrzeuge
*/
void anzeigen(struct vehicles *vehs)
{
	struct vehicles *veh_act = vehs;
	
	printf("––– Rechte Spur –––\n");
	
	while(veh_act != NIL)
	{
		printf("Hersteller: %10s  Modell: %10s Kennzeichen: %10s \tPersonen:%i\n", 
				veh_act->veh_right.manufacturer, veh_act->veh_right.model, 
				veh_act->veh_right.plate, veh_act->veh_right.occupants);
		
		veh_act = veh_act->veh_next_right;
	}
	
	printf("\n");
	printf("––– Linke Spur –––\n");
	
	veh_act = vehs;
	while(veh_act != NIL)
	{
		printf("Hersteller: %10s  Modell: %10s Kennzeichen: %10s \tPersonen:%i\n", 
				veh_act->veh_left.manufacturer, veh_act->veh_left.model, 
				veh_act->veh_left.plate, veh_act->veh_left.occupants);
		
		veh_act = veh_act->veh_next_left;
	}
	printf("\n");
}

/*
	"ausschneiden" eines Fahrzeuges an position "rm" und speichern des entfernten Fahrzeugs in "removed"
*/
void ausklinken(struct vehicles **vehs, struct vehicles **removed, int rm, int pos)
{
	struct vehicles *veh_act = (*vehs);
	struct vehicles *veh_next = (pos == 1) ? veh_act->veh_next_right : veh_act->veh_next_left;
	
	rm = (rm < 1) ? 1 : rm;	// Wenn rm kleiner 1 ist wird rm = 1.
	
	if(rm == 1)
	{
		(*removed) = (*vehs);
		(*vehs) = (pos == 1) ? (*vehs)->veh_next_right : (*vehs)->veh_next_left;
		return;
	}
	
	if (pos == 1)
	{
		for(int i = 1; i < rm; i++)
		{
			if (veh_next->veh_next_right == NIL)
			{
				(*removed) = veh_act->veh_next_right;
				veh_act->veh_next_right = veh_next->veh_next_right;
				break;
			}
			if (i + 1 == rm)
			{
				(*removed) = veh_act->veh_next_right;
				veh_act->veh_next_right = veh_next->veh_next_right;
				break;
			}
			
			veh_act = veh_act->veh_next_right;
			veh_next = veh_next->veh_next_right;
		}
	}
	else
	{
		for(int i = 1; i < rm; i++)
		{
			if (veh_next->veh_next_left == NIL)
			{
				(*removed) = veh_act->veh_next_left;
				veh_act->veh_next_left = veh_next->veh_next_left;
				break;
			}
			if (i + 1 == rm)
			{
				(*removed) = veh_act->veh_next_left;
				veh_act->veh_next_left = veh_next->veh_next_left;
				break;
			}
			
			veh_act = veh_act->veh_next_left;
			veh_next = veh_next->veh_next_left;
		}
	}
}

/*
	Einfuegen eines Fahrzeuges nach dem Fahrzeug auf position "in"
*/
void einklinken(struct vehicles **vehs, struct vehicles **toinsert, int in, int pos, int change)
{
	struct vehicles *veh_act = (*vehs);
	struct vehicles *veh_next = (pos == 1) ? veh_act->veh_next_right : veh_act->veh_next_left;
	
	if (pos == 1)
	{
		if (in < 1) // Sollte in < 1 sein wird das fahrzeug an das Ende angefuegt
		{
			while(veh_act != NIL)
			{
				if (veh_act->veh_next_right == NIL)
				{
					veh_act->veh_next_right = (*toinsert);
					(*toinsert)->veh_next_right = NIL;
					break;
				}
				veh_act = veh_act->veh_next_right;
			}
			return;
		}
		
		for(int i = 0; i < in; i++)
		{
			if (veh_act->veh_next_right == NIL)
			{
				veh_act->veh_next_right = (*toinsert);
				(*toinsert)->veh_next_right = NIL;
				break;
			}
			if (i + 1 == in)
			{
				(*toinsert)->veh_next_right = veh_next;
				veh_act->veh_next_right = (*toinsert);
				break;
			}
			
			veh_act = veh_act->veh_next_right;
			veh_next = veh_next->veh_next_right;
		}
		if (change)
			veh_act->veh_next_right->veh_right = veh_act->veh_next_right->veh_left;
	}
	else
	{
		if (in < 1) // Sollte in < 1 sein wird das fahrzeug an das Ende angefuegt
		{
			while(veh_act != NIL)
			{
				if (veh_act->veh_next_left == NIL)
				{
					veh_act->veh_next_left = (*toinsert);
					(*toinsert)->veh_next_left = NIL;
					break;
				}
				veh_act = veh_act->veh_next_left;
			}
			return;
		}
		
		for(int i = 0; i < in; i++)
		{
			if (veh_act->veh_next_left == NIL)
			{
				veh_act->veh_next_left = (*toinsert);
				(*toinsert)->veh_next_left = NIL;
				break;
			}
			if (i + 1 == in)
			{
				(*toinsert)->veh_next_left = veh_next;
				veh_act->veh_next_left = (*toinsert);
				break;
			}
			
			veh_act = veh_act->veh_next_left;
			veh_next = veh_next->veh_next_left;
		}
		if (change)
			veh_act->veh_next_left->veh_left = veh_act->veh_next_left->veh_right;
	}
}

/*
	Fahrzeug position anhand des kennzeichens bekommen.
	return 0 heißt es wurd kein Fahrzeug mit diesem Kennzeichen gefunden.
*/
int getVehFromPlate(struct vehicles *vehs, char *plate, int size, int pos)
{
	struct vehicles *veh_act = vehs;
	for (int i = 0; veh_act != NIL; i++)
	{
		char* posPlate = (pos == 1) ? veh_act->veh_right.plate : veh_act->veh_left.plate;
		/*
			Vergleichen der kennzeichen wobei Gross- und Kleinschreibung ignoriert werden.
			0 = gleich daher wird die negation "!" benoetigt
		*/
		if (!strncasecmp(posPlate, plate, size))
		{
			return i + 1;
		}
		
		veh_act = (pos == 1) ? veh_act->veh_next_right : veh_act->veh_next_left;
	}
	return 0;
}






