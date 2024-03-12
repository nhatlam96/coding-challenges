/*
	p06-testat.c
*/

#include <stdio.h>
#include <string.h>

char *dez2bin_rek(int dez, char *output, int size);

int main()
{
	char out[8];
	out[8] = '\0';

	for (int i = 0; i < 128; i++)
	{
		if (i <= 32)
		{
			printf("%.3i | %s | 0x%.2x | o%.3o | Steuerzeichen\n", i, dez2bin_rek(i, out, 8), i, i);
			continue;
		}
		printf("%.3i | %s | 0x%.2x | o%.3o | %c\n", i, dez2bin_rek(i, out, 8), i, i, (char)i);
		
	}	

	return 0;
}

/*
	Fuer details zur berechnung siehe HWK Folie Seite 69.
*/
char *dez2bin_rek(int dez, char *output, int size)
{
	
	int value = dez % 2;
	dez /= 2; // Das selbe wie dez = dez / 2;
	
	/*
		Umwandeln vom integer wert in den richtigen char wert.
		prefix verkleinerung bei size. Beachten von unterschied zwischen --size und size--
	*/
	output[--size] = (value + '0');
	
	if (size == 0)
	{
		return output;
	}
	
	return dez2bin_rek(dez, output, size);
}
