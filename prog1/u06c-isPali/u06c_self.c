/*
	u06c.c
	Name: Linus Bleyl
	Datum: 12.11.2018
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>		// Fuer die Nutzung von strnlen()

bool isPali(char *input, int size, int index);

int main()
{
    char input[65];
    bool result;

    printf("Program zur Ueberpuefung von Palindrome mit einer maximalen laenge von 64 Zeichen.\n");
    printf("Achtung bei unterschiedlicher Gross- und Kleinschreibung wir kein Palindrom erkannt.\n");
    printf("Eingabe: ");
    scanf("%s", input);

    result = isPali(input, (int)strnlen(input, sizeof(input)), 0);

    printf("%s ist %s Palindrom.\n", input, result ? "ein" : "kein");

    return 0;
}

/*
	*input 	= 	Zu vergleichender string.
	size 	=	Grosse des zu vergleichenden strings.
	index	= 	Aktuelle Position der zu vergleichenden Zeichen.
*/
bool isPali(char *input, int size, int index)
{
    // Wenn alle Zeichen verglichen wurden gibt true zurück.
    if (index >= (size / 2))
    {
        return true;
    }

    // Vergleich der z.B. ersten und letzten Zeichen.
    if (input[index] == input[size - index - 1])
    {
        // Rekusiver aufruf mit index Erhöhung um 1.
        return isPali(input, (int)strnlen(input, size), index + 1);
    }

    return false;
}

