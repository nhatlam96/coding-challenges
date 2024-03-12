/*
	u02b
*/

#include <stdio.h>

int quersumme(char input)
{
	return (input - '0');
}

int main()
{
	char input;
	int uppercase = 0;
	int lowercase = 0;
	int numbers = 0;
	int controlchar = 0;
	int otherchars = 0;
	int result = 0;
	while ((input = getchar()) != EOF && result < 42)
	{
		if (input >= 'A' && input <= 'Z')
			uppercase++;
		else if (input >= 'a' && input <= 'z')
			lowercase++;
		else if (input >= '0' && input <= '9')
		{
			result += quersumme(input);
			numbers++;
		}
		else if (input <= ' ')
			controlchar++;
		else
			otherchars++;
	}
	printf("\n");
	printf("Quersumme: \t%i\n", result);
	printf("Grossbuchstaben: \t%i\n", uppercase);
	printf("Kleinbuchstaben: \t%i\n", lowercase);
	printf("Ziffernbuchstaben: \t%i\n", numbers);
	printf("Steuerbuchstaben: \t%i\n", controlchar);
	printf("Andere Zeichen:	\t%i\n", otherchars);
	return 0;
}
